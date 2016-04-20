/*
  Header file para o programa para encontrar todas as raizes em um intervalo
  fechado [a, b] de uma função f.

  @author Esdras R. Carmo
  RA: 170656
  UNICAMP
*/

#ifndef ENCONTRA_RAIZ
#define ENCONTRA_RAIZ

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// funcao.c
long double f(long double x);

// calculos.c
void encontra_intervalo(float *a, float *b, float max);
long double encontra_raiz(long double a, long double b);

#endif
