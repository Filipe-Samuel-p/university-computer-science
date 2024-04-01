#include "ponto.h"
#include <stdio.h>



int main() {

    float d;
    Pontos *p, *q;
    p = pto_cria(10, 21);
    q = pto_cria(7, 25);
    d = pto_distancia(p, q);
    printf("a distancia entre pontos: %f\n", d);
    pto_libera(p);
    pto_libera(q);
}