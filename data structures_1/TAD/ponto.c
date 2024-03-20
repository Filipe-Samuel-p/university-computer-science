#include "ponto.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

struct ponto {
  float ponto_x;
  float ponto_y;
};

Pontos *pto_cria(float x, float y) {
  Pontos *p;
  p = (Pontos *)malloc(sizeof(Pontos));
  if (p != NULL) {
    p->ponto_x = x;
    p->ponto_y = y;
  }
  return p;
}

void pto_libera(Pontos *p) { free(p); }

void pto_acessa(Pontos *p, float *x, float *y) {
  *x = p->ponto_x;
  *y = p->ponto_y;
}
void pto_atribui(Pontos *p, float x, float y) {
  p->ponto_x = x;
  p->ponto_y = y;
}

float pto_distancia(Pontos *p1, Pontos *p2) {
  float distancia;
  distancia = sqrt(pow((p2->ponto_x - p1->ponto_x), 2)) +
              pow((p2->ponto_y - p1->ponto_y), 2);
  return distancia;
}
