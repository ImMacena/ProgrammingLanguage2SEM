#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ex5

/*
  OBS.: Todos os programa devem ser finalizados pelo usuario.
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

#ifdef ex2

/*
  2 - Reescreva o programa do exercicio anterior agora utilizando o comando switch.
      Conte o n. de tentativas e imprima o resultado no video.
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
  int response = 50, increment = 50, attempt = 1;
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
    printf("\nAttempt %d - Your number is: %d?\n", attempt, response);
    printf("Response: ");

    scanf("%c", &input);

    switch (input)
    {
    case '>':
      increment = increment * 0.5;
      response += increment;
      attempt++;
      break;
    case '<':
      increment = increment * 0.5;
      response -= increment;
      attempt++;
      break;
    case '=':
      stop = true;
      break;
    }
  }

  system("cls");

  printf("Your number is %d!\n", response);
  printf("Number of attempts: %d.\n", attempt);

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

#ifdef ex3

/*
  3 - Escreva um programa que receba via teclado numeros inteiros positivos.
      Quando o numero digitado for negativo o programa deve parar e calcula a
      media dos valores positivos digitados.
*/

int menu()
{
  int opt = 0;

  system("cls");

  printf(" - Average of Numbers - \n");
  printf("\n");
  printf(" |  1 - Start\n");
  printf(" |  2 - Exit the program\n");
  printf("\nSelect an option: ");

  scanf("%d", &opt);

  return opt;
}

int main()
{
  int optMenu, input, count = 0;
  float response, sum = 0;

  while ((optMenu = menu()) != 2)
  {
    if (optMenu == 1)
    {
      sum = 0;
      count = 0;
      input = 0;

      while (input >= 0)
      {
        system("cls");

        printf("To calculate the average, enter a negative number.\n");
        printf("Type a number: ");
        scanf("%d", &input);

        if (input >= 0)
        {
          sum += input;
          count++;
        }
      }

      system("cls");

      response = sum / count;

      printf("Number of values entered: %d\n", count);
      printf("Average: %.3f\n", response);

      system("pause");
    }
  }
}

#endif

// ================================================================================

#ifdef ex4

/*
  4 - Receba via teclado a distancia em km e a quantidade de litros de gasolina
      consumidos por um carro em um percurso.
      Calcule o consumo em km/l e escreva uma mensagem de acordo com a tabela
      abaixo:
      CONSUMO (km/l) MENSAGEM
      menor que 8    Venda o carro!
      entre 8 e 14   Economico!
      maior que 14   Super economico!
*/

int menu()
{
  int opt = 0;

  system("cls");

  printf(" - Calculate Consumption - \n");
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
      double distance = 0, gasoline = 0, average = 0;

      system("cls");

      printf(" - Calculate Consumption - \n");

      while (distance <= 0)
      {
        printf("\nEnter the distance in km traveled: ");
        scanf("%lf", &distance);
      }

      while (gasoline <= 0)
      {
        printf("\nEnter the amount of gasoline used: ");
        scanf("%lf", &gasoline);
      }

      average = distance / gasoline;

      system("cls");

      printf(" - Calculate Consumption - \n");
      printf("\nAverage consumption: %.2f km/l.", average);
      printf("\nMessage: ");

      if (average < 8)
        printf("Sell the car!");
      else if (average <= 14)
        printf("Economic!");
      else if (average > 14)
        printf("Super economic!");
      else
        printf("ERROR!");

      printf("\n");
      printf("\n");

      system("pause");
    }
  }
}

#endif

// ================================================================================

#ifdef ex5

/*
  5 - As ligacoes telefonicas são cobradas pela sua duracao. O sistema registra os
      instantes em que a ligacao foi iniciada e concluida.
      Escreva um programa que recebe via teclado dois instantes dados em
      horas, minutos e segundo e determina o intervalo de tempo
      (em horas, minutos e segundos) decorrido entre eles.
*/

int menu()
{
  int opt = 0;

  system("cls");

  printf(" - Calculate Call Time - \n");
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
      system("cls");

      if (optMenu == 1)
      {
        int startHours, startMinutes, startSeconds, endHours, endMinutes, endSeconds;

        while (1)
        {
          printf("Call start time (format: HH MM SS): ");
          scanf("%d %d %d", &startHours, &startMinutes, &startSeconds);

          if (startHours > 24 || startMinutes >= 60 || startSeconds >= 60)
          {
            printf("\nError: invalid entries! Try again...\n");
          } else break;
        }

        while (1)
        {
          printf("\nCall end time (format: HH MM SS): ");
          scanf("%d %d %d", &endHours, &endMinutes, &endSeconds);

          if (endHours > 24 || endMinutes >= 60 || endSeconds >= 60)
          {
            printf("\nError: invalid entries! Try again...\n");
          } else break;
        }

        int startConvertedTime = 0, endConvertedTime = 0;
        
        startConvertedTime += (startHours * 3600);
        startConvertedTime += (startMinutes * 60);
        startConvertedTime += startSeconds;

        endConvertedTime += (endHours * 3600);
        endConvertedTime += (endMinutes * 60);
        endConvertedTime += endSeconds;

        if (startConvertedTime > endConvertedTime)
        {
          printf("Error: invalid entries ()!\n");
        }
        else
        {
          int totalTime = endConvertedTime - startConvertedTime;

          int totalHours = (totalTime / 3600);
          int totalMinutes = ((totalTime % 3600) / 60 );
          int totalSeconds = totalTime % 60;

          printf("\nTotal call time: %dh %dm %ds\n", totalHours, totalMinutes, totalSeconds);
        }
      }

      system("pause");
    }
  }
}

#endif
