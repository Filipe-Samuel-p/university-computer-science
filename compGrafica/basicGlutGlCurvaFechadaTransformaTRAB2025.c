#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <GLUT/glut.h>

#define MAXVERTEXS 50
#define NPOLYGON 6
#define PHI 3.141592653589793

//  tipos de curvas
#define HERMITE 1
#define BEZIER 2
#define BSPLINE 3
#define CATMULLR 4

//  tipos de transformação
#define TRANSLACAO 1
#define ROTACAO 2
#define ESCALA 3
#define CISALHA 4
#define ESPELHARX 5
#define ESPELHARY 6

GLenum doubleBuffer;

typedef struct spts {
    float v[3];
} tipoPto;

tipoPto ptsCurva[MAXVERTEXS];
tipoPto ptsContrle[MAXVERTEXS];

int windW, windH;
int nPtsCtrole, nPtsCurva;

int jaCurva = 0;
int ptoSelect = -1;
int tipoCurva = 0;
int tipoTransforma = 0;

// matriz de trabalho
float M[4][4] = 
    {{0.0, 0.0, 0.0, 0.0},
     {0.0, 0.0, 0.0, 0.0},
     {0.0, 0.0, 0.0, 0.0},
     {0.0, 0.0, 0.0, 0.0}};

// matriz de Hermite
float Mh[4][4] = 
    {{2.0, -2.0, 1.0, 1.0},
     {-3.0, 3.0, -2.0, -1.0},
     {0.0, 0.0, 1.0, 0.0},
     {1.0, 0.0, 0.0, 0.0}};

// matriz de Bezier
float Mb[4][4] = 
    {{-1.0, 3.0, -3.0, 1.0},
     {3.0, -6.0, 3.0, 0.0},
     {-3.0, 3.0, 0.0, 0.0},
     {1.0, 0.0, 0.0, 0.0}};

// matriz de B-spline
float Ms[4][4] = 
    {{-1.0, 3.0, -3.0, 1.0},
     {3.0, -6.0, 3.0, 0.0},
     {-3.0, 0.0, 3.0, 0.0},
     {1.0, 4.0, 1.0, 0.0}};

// matriz de Catmull Rom
float Mc[4][4] = 
    {{-1.0, 3.0, -3.0, 1.0},
     {2.0, -5.0, 4.0, -1.0},
     {-1.0, 0.0, 1.0, 0.0},
     {0.0, 2.0, 0.0, 0.0}};

float MCor[9][3] = {
    {1.0, 0.5, 0.0},
    {0.8, 0.7, 0.5},
    {0.5, 0.5, 0.5},
    {0.5, 1.0, 0.5},
    {0.5, 0.5, 1.0},
    {1.0, 0.5, 1.0},
    {0.0, 0.0, 1.0},
    {0.0, 1.0, 0.0},
    {1.0, 0.0, 0.0}
};
int nCors = 9;

// Funções auxiliares para transformações
void multMat3Vec(const float A[3][3], const float v[3], float out[3]) {
    int i, j;
    for (i = 0; i < 3; i++) {
        out[i] = 0.0f;
        for (j = 0; j < 3; j++)
            out[i] += A[i][j] * v[j];
    }
}

void applyTransformToControl(const float T[3][3]) {
    int i;
    for (i = 0; i < nPtsCtrole; i++) {
        float vin[3] = {ptsContrle[i].v[0], ptsContrle[i].v[1], 1.0f};
        float vout[3];
        multMat3Vec(T, vin, vout);
        ptsContrle[i].v[0] = vout[0];
        ptsContrle[i].v[1] = vout[1];
    }
}

void calcCentroide(float *cx, float *cy) {
    *cx = *cy = 0.0f;
    int i;
    for (i = 0; i < nPtsCtrole; i++) {
        *cx += ptsContrle[i].v[0];
        *cy += ptsContrle[i].v[1];
    }
    if (nPtsCtrole > 0) {
        *cx /= nPtsCtrole;
        *cy /= nPtsCtrole;
    }
}

void translacao(float dx, float dy) {
    float T[3][3] = {{1, 0, dx}, {0, 1, dy}, {0, 0, 1}};
    applyTransformToControl(T);
    printf("Translacao aplicada: dx=%.2f, dy=%.2f\n", dx, dy);
}

void rotacao_centro(float ang_deg) {
    float ang = ang_deg * (PHI / 180.0f);
    float c = cos(ang), s = sin(ang);
    float cx, cy;
    calcCentroide(&cx, &cy);
    
    float T1[3][3] = {{1, 0, -cx}, {0, 1, -cy}, {0, 0, 1}};
    float Rm[3][3] = {{c, -s, 0}, {s, c, 0}, {0, 0, 1}};
    float T2[3][3] = {{1, 0, cx}, {0, 1, cy}, {0, 0, 1}};
    
    float tmp[3][3], R[3][3];
    int i, j, k;
    
    // Multiply Rm * T1
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++) {
            tmp[i][j] = 0;
            for (k = 0; k < 3; k++)
                tmp[i][j] += Rm[i][k] * T1[k][j];
        }
    
    // Multiply T2 * tmp
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++) {
            R[i][j] = 0;
            for (k = 0; k < 3; k++)
                R[i][j] += T2[i][k] * tmp[k][j];
        }
    
    applyTransformToControl(R);
    printf("Rotacao aplicada: %.2f graus\n", ang_deg);
}

void escala_centro(float sx, float sy) {
    float cx, cy;
    calcCentroide(&cx, &cy);
    
    float T1[3][3] = {{1, 0, -cx}, {0, 1, -cy}, {0, 0, 1}};
    float S[3][3] = {{sx, 0, 0}, {0, sy, 0}, {0, 0, 1}};
    float T2[3][3] = {{1, 0, cx}, {0, 1, cy}, {0, 0, 1}};
    
    float tmp[3][3], R[3][3];
    int i, j, k;
    
    // Multiply S * T1
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++) {
            tmp[i][j] = 0;
            for (k = 0; k < 3; k++)
                tmp[i][j] += S[i][k] * T1[k][j];
        }
    
    // Multiply T2 * tmp
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++) {
            R[i][j] = 0;
            for (k = 0; k < 3; k++)
                R[i][j] += T2[i][k] * tmp[k][j];
        }
    
    applyTransformToControl(R);
    printf("Escala aplicada: sx=%.2f, sy=%.2f\n", sx, sy);
}

void cisalha(float shx, float shy) {
    float cx, cy;
    calcCentroide(&cx, &cy);
    
    float T1[3][3] = {{1, 0, -cx}, {0, 1, -cy}, {0, 0, 1}};
    float Sh[3][3] = {{1, shx, 0}, {shy, 1, 0}, {0, 0, 1}};
    float T2[3][3] = {{1, 0, cx}, {0, 1, cy}, {0, 0, 1}};
    
    float tmp[3][3], R[3][3];
    int i, j, k;
    
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++) {
            tmp[i][j] = 0;
            for (k = 0; k < 3; k++)
                tmp[i][j] += Sh[i][k] * T1[k][j];
        }
    
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++) {
            R[i][j] = 0;
            for (k = 0; k < 3; k++)
                R[i][j] += T2[i][k] * tmp[k][j];
        }
    
    applyTransformToControl(R);
    printf("Cisalha aplicada: shx=%.2f, shy=%.2f\n", shx, shy);
}

void espelharX() {
    float cx, cy;
    calcCentroide(&cx, &cy);
    
    float T1[3][3] = {{1, 0, -cx}, {0, 1, -cy}, {0, 0, 1}};
    float Mx[3][3] = {{1, 0, 0}, {0, -1, 0}, {0, 0, 1}};
    float T2[3][3] = {{1, 0, cx}, {0, 1, cy}, {0, 0, 1}};
    
    float tmp[3][3], R[3][3];
    int i, j, k;
    
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++) {
            tmp[i][j] = 0;
            for (k = 0; k < 3; k++)
                tmp[i][j] += Mx[i][k] * T1[k][j];
        }
    
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++) {
            R[i][j] = 0;
            for (k = 0; k < 3; k++)
                R[i][j] += T2[i][k] * tmp[k][j];
        }
    
    applyTransformToControl(R);
    printf("Espelhamento em X aplicado\n");
}

void espelharY() {
    float cx, cy;
    calcCentroide(&cx, &cy);
    
    float T1[3][3] = {{1, 0, -cx}, {0, 1, -cy}, {0, 0, 1}};
    float My[3][3] = {{-1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    float T2[3][3] = {{1, 0, cx}, {0, 1, cy}, {0, 0, 1}};
    
    float tmp[3][3], R[3][3];
    int i, j, k;
    
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++) {
            tmp[i][j] = 0;
            for (k = 0; k < 3; k++)
                tmp[i][j] += My[i][k] * T1[k][j];
        }
    
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++) {
            R[i][j] = 0;
            for (k = 0; k < 3; k++)
                R[i][j] += T2[i][k] * tmp[k][j];
        }
    
    applyTransformToControl(R);
    printf("Espelhamento em Y aplicado\n");
}

void ptoCurva(float t, int j, float pp[3]) {
    int i, ji;
    float cc;
    tipoPto ptsCont[4];

    pp[0] = pp[1] = pp[2] = 0.0;

    // Preparando os pontos de controle para curva fechada
    for (i = 0; i < 4; i++) {
        ji = (j + i) % nPtsCtrole;
        ptsCont[i].v[0] = ptsContrle[ji].v[0];
        ptsCont[i].v[1] = ptsContrle[ji].v[1];
        ptsCont[i].v[2] = ptsContrle[ji].v[2];
    }
    
    if (tipoCurva == HERMITE) {
        // Para Hermite, precisamos calcular as tangentes
        int idx_prev = (j + nPtsCtrole - 1) % nPtsCtrole;
        int idx_next = (j + 2) % nPtsCtrole;
        
        // P0 = ptsCont[0], P1 = ptsCont[1]
        // T0 = (P1 - P_{-1})/2
        ptsCont[2].v[0] = (ptsCont[1].v[0] - ptsContrle[idx_prev].v[0]) * 0.5f;
        ptsCont[2].v[1] = (ptsCont[1].v[1] - ptsContrle[idx_prev].v[1]) * 0.5f;
        
        // T1 = (P_{2} - P0)/2
        ptsCont[3].v[0] = (ptsContrle[idx_next].v[0] - ptsCont[0].v[0]) * 0.5f;
        ptsCont[3].v[1] = (ptsContrle[idx_next].v[1] - ptsCont[0].v[1]) * 0.5f;
    }

    for (i = 0; i < 4; i++) {
        cc = t*t*t*M[0][i] + t*t*M[1][i] + t*M[2][i] + M[3][i];
        pp[0] += cc * ptsCont[i].v[0];
        pp[1] += cc * ptsCont[i].v[1];
        pp[2] += cc * ptsCont[i].v[2];
    }
}

void init(void) {
    int i;
    jaCurva = 0;
    nPtsCtrole = 0;
    nPtsCurva = 0;
    tipoCurva = 0;
    tipoTransforma = 0;
    ptoSelect = -1;

    for (i = 0; i < MAXVERTEXS; i++) {
        ptsContrle[i].v[0] = 0.0;
        ptsContrle[i].v[1] = 0.0;
        ptsContrle[i].v[2] = 0.0;

        ptsCurva[i].v[0] = 0.0;
        ptsCurva[i].v[1] = 0.0;
        ptsCurva[i].v[2] = 0.0;
    }
}

static void Key(unsigned char key, int x, int y) {
    switch (key) {
        case 27: // ESC
            exit(0);
        case 'r':
        case 'R':
            init();
            glutPostRedisplay();
            break;
    }
}

void coord_line(void) {
    glLineWidth(1);
    
    // Eixo X (vermelho)
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINE_STRIP);
        glVertex2f(-windW, 0);
        glVertex2f(windW, 0);
    glEnd();
    
    // Eixo Y (verde)
    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_LINE_STRIP);
        glVertex2f(0, -windH);
        glVertex2f(0, windH);
    glEnd();
}

void verticesDraw(int n, tipoPto vertices[MAXVERTEXS], float cr, float cg, float cb) {
    int i;
    glColor3f(cr, cg, cb);
    glPointSize(6);
    glBegin(GL_POINTS);
    for (i = 0; i < n; i++)
        glVertex2f(vertices[i].v[0], vertices[i].v[1]);
    glEnd();
}

void poligonoControleFechado(int n, tipoPto vertices[MAXVERTEXS], float cr, float cg, float cb) {
    int i;
    glColor3f(cr, cg, cb);
    glLineWidth(2);
    
    if (n > 2) {
        glBegin(GL_LINE_LOOP); // Polígono fechado
        for (i = 0; i < n; i++) {
            glVertex2fv(vertices[i].v);
        }
        glEnd();
    } else if (n > 1) {
        glBegin(GL_LINE_STRIP);
        for (i = 0; i < n; i++) {
            glVertex2fv(vertices[i].v);
        }
        glEnd();
    }
}

void curvaDraw(int n, tipoPto vertices[MAXVERTEXS], float cr, float cg, float cb) {
    int i;
    glColor3f(cr, cg, cb);
    glLineWidth(3);
    
    glBegin(GL_LINE_STRIP);
    for (i = 0; i < n; i++) {
        glVertex2fv(vertices[i].v);
    }
    glEnd();
}

void geraCurva(int j) {
    float t = 0.0;
    float dt;

    if (nPtsCtrole > 3) {
        dt = 1.0f / ((float)(MAXVERTEXS - 1));
        for (nPtsCurva = 0; nPtsCurva < MAXVERTEXS; nPtsCurva++) {
            t = (float)(nPtsCurva) * dt;
            ptoCurva(t, j, ptsCurva[nPtsCurva].v);
        }
    }
}

static void Draw(void) {
    int c, j = 0;
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);

    coord_line(); // Eixos cartesianos

    // Mostra pontos de controle em verde
    verticesDraw(nPtsCtrole, ptsContrle, 0.0, 1.0, 0.0);
    
    // Mostra polígono de controle fechado em preto
    poligonoControleFechado(nPtsCtrole, ptsContrle, 0.0, 0.0, 0.0);

    // Se curva está ativa e temos pontos suficientes
    if (jaCurva && nPtsCtrole > 3) {
        j = 0;
        while (j < nPtsCtrole) {
            geraCurva(j); // Gera pedaço da curva
            c = j % (nCors - 3); // Define cor do pedaço
            curvaDraw(nPtsCurva, ptsCurva, MCor[c][0], MCor[c][1], MCor[c][2]);
            j++;
        }
    }
    
    // Destaca ponto selecionado em vermelho
    if (ptoSelect >= 0 && ptoSelect < nPtsCtrole) {
        glColor3f(1.0, 0.0, 0.0);
        glPointSize(8);
        glBegin(GL_POINTS);
        glVertex2f(ptsContrle[ptoSelect].v[0], ptsContrle[ptoSelect].v[1]);
        glEnd();
    }

    if (doubleBuffer) {
        glutSwapBuffers();
    } else {
        glFlush();
    }
}

static void Args(int argc, char **argv) {
    GLint i;
    doubleBuffer = GL_FALSE;

    for (i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-sb") == 0) {
            doubleBuffer = GL_FALSE;
        } else if (strcmp(argv[i], "-db") == 0) {
            doubleBuffer = GL_TRUE;
        }
    }
}

void processMenuCurvas(int option) {
    int i, j;

    tipoCurva = option;
    if (nPtsCtrole > 3) {
        switch (option) {
            case HERMITE:
                printf("Selecionada curva de Hermite\n");
                for (i = 0; i < 4; i++)
                    for (j = 0; j < 4; j++)
                        M[i][j] = Mh[i][j];
                jaCurva = 1;
                break;

            case BEZIER:
                printf("Selecionada curva de Bezier\n");
                for (i = 0; i < 4; i++)
                    for (j = 0; j < 4; j++)
                        M[i][j] = Mb[i][j];
                jaCurva = 1;
                break;

            case BSPLINE:
                printf("Selecionada curva B-Spline\n");
                for (i = 0; i < 4; i++)
                    for (j = 0; j < 4; j++)
                        M[i][j] = Ms[i][j] / 6.0f;
                jaCurva = 1;
                break;

            case CATMULLR:
                printf("Selecionada curva Catmull-Rom\n");
                for (i = 0; i < 4; i++)
                    for (j = 0; j < 4; j++)
                        M[i][j] = Mc[i][j] / 2.0f;
                jaCurva = 1;
                break;
        }
    } else {
        printf("Precisa de pelo menos 4 pontos de controle!\n");
    }
    glutPostRedisplay();
}

void processMenuTransforma(int option) {
    if (nPtsCtrole < 3) {
        printf("Precisa de pelo menos 3 pontos para transformar!\n");
        return;
    }
    
    tipoTransforma = option;

    switch (option) {
        case TRANSLACAO:
            translacao(20.0f, 15.0f);
            break;
        case ROTACAO:
            rotacao_centro(15.0f);
            break;
        case ESCALA:
            escala_centro(1.2f, 1.2f);
            break;
        case CISALHA:
            cisalha(0.2f, 0.0f);
            break;
        case ESPELHARX:
            espelharX();
            break;
        case ESPELHARY:
            espelharY();
            break;
    }
    
    jaCurva = 0; // Força regeneração da curva
    glutPostRedisplay();
}

void processMenuOperacoes(int option) {
    switch (option) {
        case 1: // Finalizar polígono
            if (nPtsCtrole > 2) {
                printf("Polígono de controle finalizado com %d pontos\n", nPtsCtrole);
            }
            break;
        case 2: // Limpar tudo
            printf("Limpando tudo...\n");
            init();
            break;
        case 3: // Modo manipulação
            if (jaCurva) {
                printf("Modo manipulação ativado. Clique e arraste pontos.\n");
                tipoTransforma = 0;
            }
            break;
    }
    glutPostRedisplay();
}

void createGLUTMenus() {
    int menu, submenu1, submenu2, submenu3;

    // Submenu de curvas
    submenu1 = glutCreateMenu(processMenuCurvas);
    glutAddMenuEntry("Hermite", HERMITE);
    glutAddMenuEntry("Bezier", BEZIER);
    glutAddMenuEntry("B-Spline", BSPLINE);
    glutAddMenuEntry("Catmull-Rom", CATMULLR);

    // Submenu de transformações
    submenu2 = glutCreateMenu(processMenuTransforma);
    glutAddMenuEntry("Translacao", TRANSLACAO);
    glutAddMenuEntry("Rotacao", ROTACAO);
    glutAddMenuEntry("Escala", ESCALA);
    glutAddMenuEntry("Cisalha", CISALHA);
    glutAddMenuEntry("Espelhar X", ESPELHARX);
    glutAddMenuEntry("Espelhar Y", ESPELHARY);

    // Submenu de operações
    submenu3 = glutCreateMenu(processMenuOperacoes);
    glutAddMenuEntry("Finalizar Poligono", 1);
    glutAddMenuEntry("Modo Manipulacao", 3);

    // Menu principal
    menu = glutCreateMenu(processMenuOperacoes);
    glutAddSubMenu("Operacoes", submenu3);
    glutAddSubMenu("Tipo de Curva", submenu1);
    glutAddSubMenu("Transformacoes", submenu2);
    glutAddMenuEntry("Limpar Tudo", 2);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void motion(int x, int y)
{
	x = x - windW;
	y = windH - y;
	if (jaCurva)
		if (!tipoTransforma)
		{
			if (ptoSelect >= 0 && ptoSelect < nPtsCtrole)
			{
				ptsContrle[ptoSelect].v[0] = (float)x;
				ptsContrle[ptoSelect].v[1] = (float)y;
			}
		}
		else
		{
			printf(" transformando, ");
			switch (tipoTransforma)
			{
			case TRANSLACAO:
				printf(" Translacao, ");
				translacao(1.0f, 0.5f);
				break;

			case ROTACAO:
				printf(" Rotacao, ");
				rotacao_centro(1.0f);
				break;

			case SCALA:
				printf(" Scala, ");
				escala_centro(1.01f, 1.01f);
				break;

			case CISALHA:
				printf(" Cisalha, ");
				shear(0.01f, 0.0f);
				break;

				break;
			}
		}

	glutPostRedisplay();
}

int buscaPuntoClick(int x, int y)
{
	int i;
	float dx, dy, dd;

	ptoSelect = -1;
	for (i = 0; i < nPtsCtrole; i++)
	{
		dx = ptsContrle[i].v[0] - (float)x;
		dy = ptsContrle[i].v[1] - (float)y;
		dd = sqrt(dx * dx + dy * dy);
		if (dd < 6.00)
		{
			ptoSelect = i;
			break;
		}
	}
	return ptoSelect;
}

int buscaPuntoClick(int x, int y) {
    int i;
    float dx, dy, dd;
    int encontrado = -1;

    for (i = 0; i < nPtsCtrole; i++) {
        dx = ptsContrle[i].v[0] - (float)x;
        dy = ptsContrle[i].v[1] - (float)y;
        dd = sqrt(dx*dx + dy*dy);
        if (dd < 8.0) {
            encontrado = i;
            break;
        }
    }
    return encontrado;
}

void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON) {
        if (state == GLUT_DOWN) {
            x = x - windW;
            y = windH - y;
            
            if (!jaCurva) {
                // Modo criação de pontos
                if (nPtsCtrole < MAXVERTEXS) {
                    ptsContrle[nPtsCtrole].v[0] = (float)x;
                    ptsContrle[nPtsCtrole].v[1] = (float)y;
                    ptsContrle[nPtsCtrole].v[2] = 1.0f;
                    nPtsCtrole++;
                    printf("Ponto %d adicionado em (%.1f, %.1f)\n", 
                           nPtsCtrole, (float)x, (float)y);
                }
            } else {
                // Modo seleção de pontos
                ptoSelect = buscaPuntoClick(x, y);
                if (ptoSelect >= 0) {
                    printf("Ponto %d selecionado\n", ptoSelect);
                }
            }
            glutPostRedisplay();
        } else if (state == GLUT_UP) {
            ptoSelect = -1;
        }
    }
}

static void Reshape(int width, int height) {
    windW = width / 2;
    windH = height / 2;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
    gluOrtho2D(-windW, windW, -windH, windH);
    glMatrixMode(GL_MODELVIEW);
    glutPostRedisplay();
}

int main(int argc, char **argv) {
    GLenum type;

    glutInit(&argc, argv);
    Args(argc, argv);

    type = GLUT_RGB;
    type |= (doubleBuffer) ? GLUT_DOUBLE : GLUT_SINGLE;

    glutInitDisplayMode(type);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Curvas Parametricas Fechadas - OpenGL/GLUT");

    init();
    displayInstructions();

    glutReshapeFunc(Reshape);
    glutKeyboardFunc(Key);
    glutDisplayFunc(Draw);
    glutMotionFunc(motion);
    glutMouseFunc(mouse);

    createGLUTMenus();

    printf("Programa iniciado. Comece clicando para adicionar pontos de controle.\n");
    glutMainLoop();

    return 0;
}