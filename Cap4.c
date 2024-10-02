#include "stdio.h"
#include "stdlib.h"

#define ex2

/*
  OBS.: Todos os programa devem ser finalizados pelo usuario.
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

#ifdef ex2
int menu()
{
  int opt = 0;

  system("cls");

  printf("=====================================\n");
  printf("          Organizar variaveis\n");
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
  int inteiro[3], optMenu, i;
  long l[3];
  unsigned int u[3];
  float f[3];
  double d[3];
  while ((optMenu = menu()) != 2)
  {
    if (optMenu == 1)
    {
      system("cls");

      for(i = 0; i < 3; i++){
        printf("====%d vetor=====", i+1);
        printf("\nInteiro: ");
        scanf("%d", &inteiro[i]);

        printf("Long: ");
        scanf("%ld", &l[i]);

        printf("unsigned: ");
        scanf("%u", &u[i]);

        printf("Float: ");
        scanf("%f", &f[i]);

        printf("Double: ");
        scanf("%lf", &d[i]);
      }

      printf("\n");
      printf("        10        20        30        40        50");
      printf("\n");
      printf("12345678901234567890123456789012345678901234567890");
      printf("\n");

      for(i = 0; i < 3; i++){
        printf("  %-20d", inteiro[i]);
        printf("%-20ld", l[i]);
        printf("%-20u", u[i]);

        printf("\n");

        printf("            %-18f", f[i]);
        printf("  %-20lf", d[i]);

        printf("\n");

      }
      system("pause");
    }
  }
  return 0;
}

#endif // ex2

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

// ================================================================================

#ifdef ex4

/*
  4 - Escreva um programa que receba um vetor de inteiros com tamanho 10 e o
      decomponha em dois outros vetores. Um tera´ as componentes de valor impar
      e o outro tera´ as componentes de valor par.
      Por exemplo, se o vetor dado for v = {3, 5, 6, 8, 1, 4, 2, 3, 7, 4} o
      programa deve gerar os vetores u = {3, 5, 1, 3, 7} e w = {6, 8, 4, 2, 4}.
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

int *getEvenValues(int *vector, int length, int *evenCount)
{
  int *response = (int *)malloc(length * sizeof(int));

  int counter = 0;
  for (int i = 0; i < length; i++)
  {
    if (vector[i] % 2 == 0)
    {
      response[counter] = vector[i];
      counter++;
    }
  }

  *evenCount = counter;
  return response;
}

int *getOddValues(int *vector, int length, int *oddCount)
{
  int *response = (int *)malloc(length * sizeof(int));

  int counter = 0;
  for (int i = 0; i < length; i++)
  {
    if (vector[i] % 2 == 1)
    {
      response[counter] = vector[i];
      counter++;
    }
  }

  *oddCount = counter;
  return response;
}

int main()
{
  int optMenu, vectorLength = 10, evenCount, oddCount;
  int numbers[10];
  int *vectorEvenValues, *vectorOddValues;

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

      vectorEvenValues = getEvenValues(&numbers[0], vectorLength, &evenCount);
      vectorOddValues = getOddValues(&numbers[0], vectorLength, &oddCount);

      printf("Original vector: [ ");
      for (int i = 0; i < vectorLength; i++)
      {
        printf("%d ", numbers[i]);
      }
      printf("]\n");

      printf("Even values vector: [ ");
      for (int i = 0; i < evenCount; i++)
      {
        printf("%d ", vectorEvenValues[i]);
      }
      printf("]\n");

      printf("Odd values vector: [ ");
      for (int i = 0; i < oddCount; i++)
      {
        printf("%d ", vectorOddValues[i]);
      }
      printf("]\n \n");

      system("pause");

      free(vectorEvenValues);
      free(vectorOddValues);
    }
  }
}

#endif

// ================================================================================

#ifdef ex5

/*
  5 - Defina 2 vetores bidimensionais do tipo inteiro de 2x3. Escreva um programa
      que recebe os dados via teclado para esses 2 vetores. Usando o operador
      adicao "+", some os elementos de mesmo indice dos 2 vetores e guarde o
      resultado em um 3. vetor. Imprima na tela o indice, os valores e o resultado
      dos 6 elementos dos vetores.
*/

int menu()
{
  int opt = 0;

  system("cls");

  printf("=====================================\n");
  printf("       Bidimensional Vector Sum\n");
  printf("=====================================\n");
  printf("\n");
  printf(" |  1 - Start\n");
  printf(" |  2 - Exit the program\n");
  printf("\nSelect an option: ");

  scanf("%d", &opt);

  return opt;
}

void fillBidimensionalVector(int vector[2][3])
{
  int VectorFirstIndexSize = 2;
  int VectorSecondIndexSize = 3;

  for (int i = 0; i < VectorFirstIndexSize; i++)
  {
    for (int i2 = 0; i2 < VectorSecondIndexSize; i2++)
    {
      printf("\nVector[%d][%d]: ", i, i2);
      scanf("%d", &vector[i][i2]);
    }
  }
}

void sumBidimensionalVectorValues(int vector1[2][3], int vector2[2][3], int vectorResult[2][3])
{
  int VectorFirstIndexSize = 2;
  int VectorSecondIndexSize = 3;

  for (int i = 0; i < VectorFirstIndexSize; i++)
  {
    for (int i2 = 0; i2 < VectorSecondIndexSize; i2++)
    {
      vectorResult[i][i2] = vector1[i][i2] + vector2[i][i2];
    }
  }
}

int main()
{
  int optMenu;
  int vector1[2][3], vector2[2][3], vectorResult[2][3];

  while ((optMenu = menu()) != 2)
  {
    if (optMenu == 1)
    {
      for (int i = 0; i < 2; i++)
      {
        system("cls");

        printf(" - Vector%d Entries - \n", i + 1);

        switch (i)
        {
        case 0:
          fillBidimensionalVector(vector1);
          break;

        case 1:
          fillBidimensionalVector(vector2);
          break;

        default:
          break;
        }
      }

      system("cls");

      sumBidimensionalVectorValues(vector1, vector2, vectorResult);

      printf("Result: \n");

      for (int i = 0; i < 2; i++)
      {
        for (int i2 = 0; i2 < 3; i2++)
        {
          printf("\nVectorResult[%d][%d] = %d", i, i2, vectorResult[i][i2]);
        }
      }

      printf("\n \n");
      system("pause");
    }
  }
}

#endif
