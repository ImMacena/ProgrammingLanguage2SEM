#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ex2

/*
  OBS.: Todos os programa devem ser finalizados pelo usuario.

  3 - Escreva um programa que receba na funcao main() 2 valores inteiro. Escreva
      uma funcao para cada operacoes aritmeticas e passe como parametro os 2
      valores recebidos na funcao main(). Retorne os resultados usando o comando
      return e imprima os 4 resultados no video na funcao main().

  4 - Reescreva o programa do exercicio anterior para receber via teclado n
      valores. Os n valores nao sao definidos previamente.

  5 - Escreva um programa que receba n valores inteiros via teclado na funcao main().
      Faca uma calculadora com as 4 operacoes aritmeticas.(utilize o comando switch).
      As operacoes aritmeticas devem ser funcoes. O resultado acumulado deve ser 
      mostrado na funcao main().
*/

#ifdef ex1

/*
    1 - Escreva um programa que receba um numero N via teclado. Escreva uma funcao
      que retorne a soma dos algarismos do resultado de N!. O resultado deve ser
      mostrado na funcao main().
      Ex: se N = 4, N! = 24. Logo, a soma de seus algarismos e´ 2 + 4 = 6.
*/

int calculateSum(int N)
{
  /*
    O programa só retornará valores corretos quando N < 20,
    levando em consideração as limitações de tamanho de variáveis númericas
    do próprio compilador (no caso o 'gcc');
  */

  long fatResult = N;
  int response = 0;

  for (int i = (N - 1); i != 1; i--)
  {
    fatResult *= i;
  }

  while (fatResult > 0)
  {
    response += fatResult % 10;
    fatResult /= 10;
  }

  return response;
}

int menu()
{
  int opt = 0;

  system("cls");

  printf("=====================================\n");
  printf("  Sum of the digits of a factorial\n");
  printf("=====================================\n");
  printf("\n");
  printf(" |  1 - Start\n");
  printf(" |  2 - Exit the program\n");
  printf("\nSelect an option: ");

  scanf("%d", &opt);

  return opt;
}

int main()
{
  int optMenu, input;

  while ((optMenu = menu()) != 2)
  {
    if (optMenu == 1)
    {
      system("cls");

      printf("Enter the number to calculate: ");
      scanf("%d", &input);

      printf("\nResult: %d\n", calculateSum(input));
      printf("\n");

      system("pause");
    }
  }
}

#endif

// ================================================================================

#ifdef ex2

/*
  2 - Escreva um programa que receba dois numeros inteiros e execute as seguintes
      funçoes:
      - Verificar se o numero digitado e' positivo ou negativo. Sendo que o valor de
        retorno sera' 1 se positivo, 0 se negativo ou -1 se for igual a 0.
      - Se os 2 numeros sao positivos, retorne a soma dos N numeros existentes entre
        eles.
      - Se os 2 numeros sao negativos, retorne a multiplicacao dos N numeros existente
        entre eles.
      - Se 1. numero for positivo e o 2. negativo faca a divisao entre eles.
*/

int verifyNumberStatus(int input)
{
  if (input > 0) return 1;
  else if (input == 0) return -1;
  else if (input < 0) return 0;
  else return 2;
}

int positiveNumbers(int n1, int n2)
{

}

int negativeNumbers(int n1, int n2)
{

}

int differentNumbers(int n1, int n2)
{

}

void operateNumbers(int status1, int status2, int n1, int n2)
{
  if (status1 == 2 || status2 == 2)
  {
    printf("Error: unexpected number format!");
  }
  else if (status1 != 0 && status2 != 0)
  {
    if ((status1 > 0) && (status2 > 0))
    {
      int response = positiveNumbers(n1, n2);
    }
    else if ((status1 < 0) && (status2 < 0))
    {
      int response = negativeNumbers(n1, n2);
    }
    else 
    {
      int response = differentNumbers(n1, n2);
    }
  }
  else printf("Some of the numbers are 0!");
}

int menu()
{
  int opt = 0;

  system("cls");

  printf("=====================================\n");
  printf("    Operations With Two Numbers\n");
  printf("=====================================\n");
  printf("\n");
  printf(" |  1 - Start\n");
  printf(" |  2 - Exit the program\n");
  printf("\nSelect an option: ");

  scanf("%d", &opt);

  return opt;
}

int main()
{
  int optMenu;

  while ((optMenu = menu()) != 2)
  {
    if (optMenu == 1)
    {
      int input1, input2, status1, status2, response;

      system("cls");

      printf("Enter the two numbers separated by space: ");
      scanf("%d %d", &input1, &input2);

      status1 = verifyNumberStatus(input1);
      status2 = verifyNumberStatus(input2);




      system("pause");
    }
  }
}

#endif