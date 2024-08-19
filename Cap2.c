#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ex1

/*
  OBS.: Todos os programa devem ser finalizados pelo usuario.

  2 - Reescreva o programa do exercicio anterior agora utilizando o comando switch.
      Conte o n. de tentativas e imprima o resultado no video.

  3 - Escreva um programa que receba via teclado numeros inteiros positivos.
      Quando o numero digitado for negativo o programa deve parar e calcula a
      media dos valores positivos digitados.

  4 - Receba via teclado a distancia em km e a quantidade de litros de gasolina
      consumidos por um carro em um percurso.
      Calcule o consumo em km/l e escreva uma mensagem de acordo com a tabela
      abaixo:
      CONSUMO (km/l) MENSAGEM
      menor que 8    Venda o carro!
      entre 8 e 14   Economico!
      maior que 14   Super economico!

  5 - As ligacoes telefonicas são cobradas pela sua duracao. O sistema registra os
      instantes em que a ligacao foi iniciada e concluida.
      Escreva um programa que recebe via teclado dois instantes dados em
      horas, minutos e segundo e determina o intervalo de tempo
      (em horas, minutos e segundos) decorrido entre eles.
*/

#ifdef ex1

/*
  1 - Escreva um programa para adivinhar um numero entre 1 e 99 que o usuario
      pensou. Digite via teclado os simbolos =, > ou < a cada pergunta. Utilize o
      comando if-else.
*/

int menu()
{
  int opt = 0;

  system("cls");

  printf("============================\n");
  printf("       NUMBER GUESSER\n");
  printf("============================\n");
  printf("\n");
  printf(" |  1 - Start\n");
  printf(" |  2 - Exit the program\n");
  printf("\nSelect an option: ");

  scanf("%d", &opt);

  return opt;
}

void game()
{
  int response = 50, increment = 50;
  char input;
  bool stop = false;

  while (!stop)
  {
    system("cls");

    printf("============================\n");
    printf("       NUMBER GUESSER\n");
    printf("============================\n");
    printf("\n");
    printf("Think of a number... Use [ > ] and [ < ]. In the correct number type [ = ]\n");
    printf("\nYour number is: %d?\n", response);
    printf("Response: ");

    scanf("%c", &input);

    if (input == '>')
    {
      increment = increment * 0.5;
      response += increment;
    }
    else if (input == '<')
    {
      increment = increment * 0.5;
      response -= increment;
    }
    else if (input == '=')
      stop = true;
  }

  system("cls");

  printf("Your number is %d!\n", response);

  system("pause");
}

int main()
{
  int optMenu;

  while ((optMenu = menu()) != 2)
  {

    if (optMenu == 1)
    {
      game();
    }
  }
}

#endif

// ================================================================================
