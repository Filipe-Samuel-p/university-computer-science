
typedef struct ponto Pontos;


Pontos *pto_cria(float x, float y);
void pto_libera(Pontos *p);
float pto_distancia(Pontos *p1, Pontos *p2);
