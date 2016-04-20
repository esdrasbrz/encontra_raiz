/*
  Arquivo com o método main para o programa

  @author Esdras R. Carmo
  RA: 170656
  UNICAMP
*/
#include "encontra_raiz.h"

int main(void) {
  float a = -100.0, b = 100.0; // intervalo para checar as raízes da função
  float x0 = a, x = a; // intervalo para verificar a existência ou não de raízes
  int qtd_raizes = -2; // quantidade de raizes
  int i; // contador

  // verifica a quantidade de raízes a função irá possuir
  do {
    qtd_raizes++;
    encontra_intervalo(&x0, &x, b);

    printf("x0 = %f\n", x0);
    printf("x = %f\n", x);

    x0 = x;
  } while (x <= b);

  if (qtd_raizes == 0) { // função não possui raizes
    printf("A função, no intervalo dado, não possui raizes reais.\n");
    return 0;
  }

  // retorna os valores de x0 e x
  x0 = x = a;

  printf("Raíz(es) encontrada(s):\n");
  // encontra as raízes e as exibe
  for (i = 0; i < qtd_raizes; i++) { // percorre encontrando as raizes
    encontra_intervalo(&x0, &x, b);

    printf("%.17llf\n", encontra_raiz((long double) x0, (long double) x));
    x0 = x;
  }

  return 0;
}
