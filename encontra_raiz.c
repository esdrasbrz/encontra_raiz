#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
  Programa que, dado um intervalo em que possui uma raíz de uma função, ele
  estima valores infinitamente próximos dela ou a encontra. Divirta-se!

  @author Esdras R. Carmo - RA: 170656
**/

/*
  Define a função que será testada
*/
long double f(long double x) {
  return (pow(x, 5)) + x + 1;
}

/*
  Método executável
*/
int main(void) {
  long double a = -1.0, b = 0.0; // intervalos iniciais
  long double passo; // passo variável em que será aproximado o intervalo

  // Executa até encontrar uma raíz no a. Caso não encontre, o passo é diminuído
  for (passo = 0.1; f(a) != 0.0; passo /= 10.0) {
    while ((f(a + passo) < 0.0) || (f(b - passo) > 0.0)) {
      // imprime os atuais valores do intervalos
      printf("(%.50llf, %.50llf) (f(a) = %.20llf, f(b) = %.20llf)\n", a, b, f(a), f(b));

      // caso seja possível mais um passo, ele é dado
      if (f(a + passo) < 0.0)
        a = a + passo;
      if (f(b - passo) > 0.0)
        b = b - passo;
    }
  }

  printf("A raíz desse polinômio é: %.50llf\n", a);

  return 0;
}
