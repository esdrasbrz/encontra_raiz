/*
  Arquivo com os cálculos necessários para o programa

  @author Esdras R. Carmo
  RA: 170656
  UNICAMP
*/

#include "encontra_raiz.h"

// erro máximo alcançado pelo programa
#define ERR 0.00000000000000001
// primeiro passo para determinar a raiz
#define PRIM_PASSO 0.5

// Encontra o próximo intervalo que possui alguma raíz, pelo TVI
void encontra_intervalo(float *a, float *b, float max) {
  int aux;

  if (*b == *a)
    *b += PRIM_PASSO;
  else if (*b < *a) {
    aux = *a;
    *a = *b;
    *b = aux;
  }

  while (((f(*a) < 0 && f(*b) < 0) || (f(*a) > 0 && f(*b) > 0)) && *b <= (max - PRIM_PASSO)) {
    *b += PRIM_PASSO;
    *a += PRIM_PASSO;
  }

  return;
}

// Encontra raíz, já checando se a função é crescente ou decrescente no intervalo (a, b) dado
long double encontra_raiz(long double a, long double b) {
  long double passo; // Passo variável

  if (f(a) < f(b)) { // função crescente no intervalo
    // executa até chegar no erro, diminuindo sempre o passo
    for (passo = PRIM_PASSO; b - a > ERR; passo /= 10.0) {
      while (f(a + passo) < 0 || f(b - passo) > 0) {
        // verifica qual passo é possível ser dado
        if (f(a + passo) < 0)
          a += passo;
        if (f(b - passo) > 0)
          b -= passo;
      }
    }
  } else { // função decrescente no intervalo
    // executa até chegar no erro, diminuindo sempre o passo
    for (passo = PRIM_PASSO; b - a > ERR; passo /= 10.0) {
      while (f(a + passo) > 0 || f(b - passo) < 0) {
        // verifica qual passo é possível ser dado
        if (f(a + passo) > 0)
          a += passo;
        if (f(b - passo) < 0)
          b -= passo;
      }
    }
  }

  return (a + b)/2.0;
}
