#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ex3

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
    do próprio compilador (no caso, o 'gcc');
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
  if (input > 0)
    return 1;
  else if (input == 0)
    return -1;
  else if (input < 0)
    return 0;
  else
    return 2;
}

int positiveNumbers(int n1, int n2)
{
  int response = 0;

  if (n1 == n2)
    return 0;
  else if (n1 < n2)
  {
    for (int i = n1 + 1; i < n2; i++)
    {
      response += i;
    }
  }
  else if (n1 > n2)
  {
    for (int i = n2 + 1; i < n1; i++)
    {
      response += i;
    }
  }

  return response;
}

int negativeNumbers(int n1, int n2)
{
  int response = 0;

  if (n1 == n2)
    return 0;
  else if ((n1 < n2) && ((n1 + 1) != n2))
  {
    response = 1; // Deve ser iniciado em 1 por ser multiplicado

    for (int i = n1 + 1; i < n2; i++)
    {
      response *= i;
    }
  }
  else if ((n1 > n2) && ((n2 + 1) != n1))
  {
    response = 1; // Deve ser iniciado em 1 por ser multiplicado

    for (int i = n2 + 1; i < n1; i++)
    {
      response *= i;
    }
  }

  return response;
}

float differentNumbers(int n1, int n2)
{
  return n1 / (float)n2;
}

void operateNumbers(int status1, int status2, int n1, int n2)
{
  if (status1 == 2 || status2 == 2)
  {
    printf("Error: unexpected number format!\n");
  }
  else if (status1 != -1 && status2 != -1)
  {
    if ((status1 > 0) && (status2 > 0))
    {
      int response = positiveNumbers(n1, n2);

      printf("The numbers are positive.\n");
      printf("The sum of the numbers between %d and %d is: %d\n", n1, n2, response);
    }
    else if ((status1 == 0) && (status2 == 0))
    {
      int response = negativeNumbers(n1, n2);

      printf("The numbers are negative.\n");
      printf("The multiplication of the numbers between %d and %d is: %d\n", n1, n2, response);
    }
    else
    {
      float response = differentNumbers(n1, n2);

      printf("One of the numbers is positive and the other is negative.\n");
      printf("The division between %d and %d is: %.3f\n", n1, n2, response);
    }
  }
  else
    printf("Some of the numbers are 0!\n");
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
      int input1, input2, status1, status2;

      system("cls");

      printf("Enter the two numbers separated by space: ");
      scanf("%d %d", &input1, &input2);

      status1 = verifyNumberStatus(input1);
      status2 = verifyNumberStatus(input2);

      system("cls");

      operateNumbers(status1, status2, input1, input2);

      system("pause");
    }
  }
}

#endif

// ================================================================================

#ifdef ex3

/*
  3 - Escreva um programa que receba na funcao main() 2 valores inteiro. Escreva
      uma funcao para cada operacoes aritmeticas e passe como parametro os 2
      valores recebidos na funcao main(). Retorne os resultados usando o comando
      return e imprima os 4 resultados no video na funcao main().
*/

int multiplication(int v1, int v2)
{
  return v1 * v2;
}

int sum(int v1, int v2)
{
  return v1 + v2;
}

int subtraction(int v1, int v2)
{
  return v1 - v2;
}

float division(int v1, int v2)
{
  return v1 / (float)v2;
}

int menu()
{
  int opt = 0;

  system("cls");

  printf("===========================\n");
  printf("       Calculator\n");
  printf("===========================\n");
  printf("\n");
  printf(" |  1 - Start\n");
  printf(" |  2 - Exit the program\n");
  printf("\nSelect an option: ");

  scanf("%d", &opt);

  return opt;
}

int main()
{
  int optMenu, input1, input2;

  while ((optMenu = menu()) != 2)
  {
    if (optMenu == 1)
    {
      system("cls");

      printf("Enter the first value: ");
      scanf("%d", &input1);

      printf("Enter the second value: ");
      scanf("%d", &input2);

      system("cls");

      printf("- RESULTS - \n");
      printf("\nSum: %d + %d: %d\n", input1, input2, sum(input1, input2));
      printf("Subtraction: %d - %d: %d\n", input1, input2, subtraction(input1, input2));
      printf("Multiplication: %d * %d: %d\n", input1, input2, multiplication(input1, input2));
      printf("Division: %d / %d: %.3f\n", input1, input2, division(input1, input2));

      printf("\n");

      system("pause");
    }
  }
}

#endif

// ================================================================================