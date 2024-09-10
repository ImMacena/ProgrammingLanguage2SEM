#include "stdio.h"
#include "stdlib.h"

#define ex3

/*

  OBS.: Todos os programa devem ser finalizados pelo usuario.

  2 - Escreva um programa para receber via teclado em vetores 3 int, 3 long,
      3 unsigned, 3 float e 3 double e imprima-os no video no seguinte formato:

              10        20        30        40        50
      12345678901234567890123456789012345678901234567890
        int                 long                unsigned
                  float               double
        int                 long                unsigned
                  float               double
        int                 long                unsigned
                  float               double

  4 - Escreva um programa que receba um vetor de inteiros com tamanho 10 e o
      decomponha em dois outros vetores. Um tera´ as componentes de valor impar
      e o outro tera´ as componentes de valor par.
      Por exemplo, se o vetor dado for v = {3, 5, 6, 8, 1, 4, 2, 3, 7, 4} o
      programa deve gerar os vetores u = {3, 5, 1, 3, 7} e w = {6, 8, 4, 2, 4}.

  5 - Defina 2 vetores bidimensionais do tipo inteiro de 2x3. Escreva um programa
      que recebe os dados via teclado para esses 2 vetores. Usando o operador
      adicao "+", some os elementos de mesmo indice dos 2 vetores e guarde o
      resultado em um 3. vetor. Imprima na tela o indice, os valores e o resultado
      dos 6 elementos dos vetores.

*/

#ifdef ex1

/*
  1 - Receba via teclado 10 valores inteiros e ordene por ordem crescente assim
      que sao digitados. Guarde-os em um vetor. Mostre ao final os valores
      ordenados.
*/

int menu()
{
  int opt = 0;

  system("cls");

  printf("=====================================\n");
  printf("          Sort Vector\n");
  printf("=====================================\n");
  printf("\n");
  printf(" |  1 - Start\n");
  printf(" |  2 - Exit the program\n");
  printf("\nSelect an option: ");

  scanf("%d", &opt);

  return opt;
}

void order(int *values, int value, int index)
{
  if (values[index] == 0)
  {
    values[index] = value;
    printf("\t%d =0\n", values[index]);
    printf("\t%d =0\n", index + 1);
  }

  if (value < values[index])
  {
    order(values, values[index], index + 1);
    values[index] = value;
    printf("\t%d <\n", values[index]);
    printf("\t%d <\n", index + 1);
  }

  if (value > values[index])
  {
    order(values, value, index + 1);

    printf("\t%d >\n", value);
    printf("\t%d >\n", index + 1);
  }
}

int main()
{
  int optMenu, input;
  int numbers[10] = {0};

  while ((optMenu = menu()) != 2)
  {
    if (optMenu == 1)
    {
      system("cls");

      for (int i = 0; i < 10; i++)
      {
        input = 0;

        while (input == 0)
        {
          printf("Enter the %do number to order: ", i + 1);
          scanf("%d", &input);

          order(numbers, input, 0);
        }
      }

      system("cls");

      printf("Result: \n");
      printf("\n");

      for (int i = 0; i < 10; i++)
      {
        printf("Position [%d] - Value: %d\n", i, numbers[i]);
      }

      system("pause");
    }
  }
}

#endif

// ================================================================================

#ifdef ex3

/*
  3 - Escreva um programa que receba um vetor de inteiros com tamanho 10 e o
      decomponha em dois outros vetores. Um tera´ as componentes de ordem impar
      e o outro tera´ as componentes de ordem par.
      Por exemplo, se o vetor dado for v = {3, 5, 6, 8, 1, 4, 2, 3, 7, 9}, o programa
      deve gerar os vetores u = {3, 6, 1, 2, 7} e w = {5, 8, 4, 3, 9}.
*/

int menu()
{
  int opt = 0;

  system("cls");

  printf("=====================================\n");
  printf("          Decompose vector\n");
  printf("=====================================\n");
  printf("\n");
  printf(" |  1 - Start\n");
  printf(" |  2 - Exit the program\n");
  printf("\nSelect an option: ");

  scanf("%d", &opt);

  return opt;
}

int *getEvenIndexes(int *vector, int length, int *evenCount)
{
  *evenCount = (length + 1) / 2; // Calcula o número de elementos pares

  int *response = (int *)malloc(*evenCount * sizeof(int));

  int counter = 0;
  for (int i = 0; i < length; i++)
  {
    if (i % 2 == 0)
    {
      response[counter] = vector[i];
      counter++;
    }
  }

  return response;
}

int *getOddIndexes(int *vector, int length, int *oddCount)
{
  *oddCount = length / 2; // Calcula o número de elementos ímpares

  int *response = (int *)malloc(*oddCount * sizeof(int));

  int counter = 0;
  for (int i = 0; i < length; i++)
  {
    if (i % 2 == 1)
    {
      response[counter] = vector[i];
      counter++;
    }
  }

  return response;
}

int main()
{
  int optMenu, vectorLength = 10, evenCount, oddCount;
  int numbers[10];
  int *vectorEvenIndexes, *vectorOddIndexes;

  while ((optMenu = menu()) != 2)
  {
    system("cls");

    if (optMenu == 1)
    {
      for (int i = 0; i < vectorLength; i++)
      {
        printf("Enter the %do value: ", i + 1);
        scanf("%d", &numbers[i]);
      }

      system("cls");

      vectorEvenIndexes = getEvenIndexes(&numbers[0], vectorLength, &evenCount);
      vectorOddIndexes = getOddIndexes(&numbers[0], vectorLength, &oddCount);

      printf("Original vector: [ ");
      for (int i = 0; i < vectorLength; i++)
      {
        printf("%d ", numbers[i]);
      }
      printf("]\n");

      printf("Even indexes vector: [ ");
      for (int i = 0; i < evenCount; i++)
      {
        printf("%d ", vectorEvenIndexes[i]);
      }
      printf("]\n");

      printf("Odd indexes vector: [ ");
      for (int i = 0; i < oddCount; i++)
      {
        printf("%d ", vectorOddIndexes[i]);
      }
      printf("]\n \n");

      system("pause");

      free(vectorEvenIndexes);
      free(vectorOddIndexes);
    }
  }
}

#endif
