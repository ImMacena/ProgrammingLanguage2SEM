#include <stdio.h>
#include <stdlib.h>

#define ex5

#ifdef ex1

// 1 - Escreva um programa que permute o conteúdo de duas variáveis sem utilizar uma variável auxiliar.

int main()
{
  char V1 = '1', V2 = '2';

  printf("V1 = %c\n", V1);
  printf("V2 = %c", V2);

  // Utilizando o operador "^", que representa o valor lógico XOR ou "ou exclusivo"

  V2 ^= V1;
  V1 ^= V2;
  V2 ^= V1;

  printf("\nValues ​​after exchange\n");

  printf("V1 = %c\n", V1);
  printf("V2 = %c\n", V2);
}

#endif

// ================================================================================

#ifdef ex2

/*
    2 - Escreva um programa que receba dados via teclado para variaveis do tipo short,
        long, int, float, double e um char e imprima-os no video no seguinte
        formato:
                10        20        30        40        50        60
        12345678901234567890123456789012345678901234567890123456789012345
            short               long                int
                    float               double              char
*/

int main()
{
  short s;
  long l;
  int i;
  float f;
  double d;
  char c;

  scanf("%hd", &s);
  scanf("%ld", &l);
  scanf("%d", &i);
  scanf("%f", &f);
  scanf("%f", &d);
  scanf("%c", &c);
}

#endif

// ================================================================================

#ifdef ex3

/*
    3 - Escreva um programa que receba via teclado um tempo em segundos e converta
        para horas, minutos e segundos.
        Ex.: recebe 3850 segundos que converte para 1h 4min 10s.
*/

int main()
{
  int input, sec, min, hour;

  scanf("%d", &input);

  hour = input / 3600; // 3600 segundos é o equivalente a 1 hora
  min = (input % 3600) / 60;
  sec = input % 60;

  system("cls");

  printf("\n-- Converted seconds: %dh %dmin %ds.", hour, min, sec);
}

#endif

// ================================================================================

#ifdef ex4

/*
    4 - Faça um programa para ler um numero inteiro, positivo de tres digitos, e gerar
    outro número formado pelos dígitos invertidos do número lido.
    Ex:   NúmeroLido = 123
          NúmeroGerado = 321
*/

int main()
{
  unsigned int num, hund, ten, uni, convertedNum;

  scanf("%u", &num);

  hund = num / 100;
  ten = (num / 10) % 10;
  uni = num % 10;

  convertedNum = (uni * 100) + (ten * 10) + hund;

  printf("Converted number: %d\n", convertedNum);

  return 0;
}

#endif

// ================================================================================

#ifdef ex5

/*
  5 - Escreva um programa que determine o menor multiplo de um numero inteiro. Este
      multiplo deve ser maior que o limite minimo recebido. Recebe os 2 numeros via
      teclado.
      Ex: menor multiplo de 13 maior que 100. Resultado: 104.
*/

int main()
{
  unsigned num, limit, result, factor;

  scanf("%u", &num);
  scanf("%u", &limit);

  // Caso o limite seja menor que o número, o menor múltiplo é ele mesmo.
  if (limit < num)
    result = num;
  else
  {
    
  }

  return 0;
}

#endif

// ================================================================================
