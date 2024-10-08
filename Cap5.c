#include "stdio.h"
#include "stdlib.h"

#define ex2

/*
	OBS.: Todos os programa devem ser finalizados pelo usuario.
*/

#ifdef ex1

/*
	1 - Receba 2 string de ate 10 caracteres via teclado na funcao main(). Faça uma
		funcao para compara-las e retorne como resultado se são IGUAIS 1 ou se
		DIFERENTES 0 para a funcao main(). Imprima o resultado na funcao main().
		(Declare os vetores como variavel global) (nao pode usar funcao de biblioteca)
*/

char str1[10], str2[10];

int menu()
{
	int opt = 0;

	system("cls");

	printf("=====================================\n");
	printf("          Strings Compare\n");
	printf("=====================================\n");
	printf("\n");
	printf(" |  1 - Start\n");
	printf(" |  2 - Exit the program\n");
	printf("\nSelect an option: ");

	scanf("%d", &opt);

	return opt;
}

int comparaStrings()
{
	int i = 0;

	while (str1[i] != '\0' && str2[i] != '\0')
	{
		if (str1[i] != str2[i])
		{
			return 0;
		}
		i++;
	}

	if (str1[i] == '\0' && str2[i] == '\0')
	{
		return 1;
	}
	return 0;
}

int main()
{
	int optMenu;

	while ((optMenu = menu()) != 2)
	{
		system("cls");

		if (optMenu == 1)
		{
			for (int i = 0; i < 2; i++)
			{
				printf("Digite a String n. %d: ", i + 1);

				if (i == 0)
				{
					fflush(stdin);
					gets(str1);
				}
				else if (i == 1)
				{
					fflush(stdin);

					gets(str2);
				}
			}

			if (comparaStrings())
				printf("As Strings sao iguais");
			else if (!comparaStrings())
				printf("As Strings sao diferentes");

			printf("\n");
			system("pause");
		}
	}

	return 0;
}

#endif

// ================================================================================

#ifdef ex2

/*
	2 - Escreva um programa para receber 5 nomes, com até 7 caracteres, via teclado
		e imprima-os no video no seguinte formato:(Declare os 5 vetores como variaveis
		globais)

						10        20        30        40        50
		12345678901234567890123456789012345678901234567890
			nome1                                   nome5
								nome2               nome4
													nome3
*/

int menu()
{
	int opt = 0;

	system("cls");

	printf("=====================================\n");
	printf("           Print Names\n");
	printf("=====================================\n");
	printf("\n");
	printf(" |  1 - Start\n");
	printf(" |  2 - Exit the program\n");
	printf("\nSelect an option: ");

	scanf("%d", &opt);

	return opt;
}

char nome1[8], nome2[8], nome3[8], nome4[8], nome5[8];

int main()
{
	int optMenu;

	while ((optMenu = menu()) != 2)
	{
		system("cls");

		if (optMenu == 1)
		{
			for (int i = 0; i < 5; i++)
			{
				printf("Digite o nome %d: ", i + 1);

				fflush(stdin);
				i == 0 ? gets(nome1) : (i == 1 ? gets(nome2) : (i == 2 ? gets(nome3) : (i == 3 ? gets(nome4) : gets(nome5))));
			}

			printf("        10        20        30        40        50");
			printf("\n");
			printf("12345678901234567890123456789012345678901234567890");
			printf("\n");
			printf("  %-40s", nome1);
			printf("%s", nome5);
			printf("\n");
			printf("            %-20s", nome2);
			printf("%-s", nome4);
			printf("\n");
			printf("                      %-s", nome3);

			printf("\n");
			system("pause");
		}
	}
}

#endif

// ================================================================================

#ifdef ex3

/*
	3 - Escreva um programa que receba uma string na funcao main(). Faca uma funcao que
		calcula o comprimento de uma string recebida via teclado. Mostre o valor do
		comprimento na funcao main().
		(Declare o vetor como variavel global) (nao pode usar funcao de biblioteca)
*/

int menu()
{
	int opt = 0;

	system("cls");

	printf("=====================================\n");
	printf("           Vector Lentgh\n");
	printf("=====================================\n");
	printf("\n");
	printf(" |  1 - Start\n");
	printf(" |  2 - Exit the program\n");
	printf("\nSelect an option: ");

	scanf("%d", &opt);

	return opt;
}

char str1[100];

int tamanhoString()
{
	int i = 0;

	while (str1[i] != '\0')
	{
		i++;
	}
	return i;
}

int main()
{
	int optMenu;

	while ((optMenu = menu()) != 2)
	{
		system("cls");

		if (optMenu == 1)
		{
			int tamString;

			printf("Digite a String: ");

			fflush(stdin);
			gets(str1);

			tamString = tamanhoString();

			printf("%d", tamString);

			printf("\n");
			system("pause");
		}
	}

	return 0;
}
#endif

// ================================================================================

#ifdef ex4

/*
	4 - Receba via teclado uma cadeia de caracteres (10) e converta todos os caracteres
		para letras maiusculas. (nao pode usar funcao de biblioteca)
*/

int menu()
{
	int opt = 0;

	system("cls");

	printf("=====================================\n");
	printf("          String Uppercase\n");
	printf("=====================================\n");
	printf("\n");
	printf(" |  1 - Start\n");
	printf(" |  2 - Exit the program\n");
	printf("\nSelect an option: ");

	scanf("%d", &opt);

	return opt;
}

char str1[11];

void convertMaiusculo()
{
	int i = 0;

	while (str1[i] != '\0')
	{
		if (str1[i] == ' ')
		{
			str1[i] = ' ';
			i++;
		}
		str1[i] = str1[i] & ~(1 << 5);
		i++;
	}
}

int main()
{
	int optMenu;

	while ((optMenu = menu()) != 2)
	{
		system("cls");

		if (optMenu == 1)
		{
			printf("Digite a String: ");

			fflush(stdin);
			gets(str1);

			convertMaiusculo();

			printf("%s", str1);

			printf("\n");
			system("pause");
		}
	}

	return 0;
}
#endif

// ================================================================================

#ifdef ex5

/*
	5 - Receba via teclado uma cadeia de caracteres (10) e converta todos os caracteres
		para letras minusculas. (nao pode usar funcao de biblioteca)
*/

int menu()
{
	int opt = 0;

	system("cls");

	printf("=====================================\n");
	printf("          String Lowercase\n");
	printf("=====================================\n");
	printf("\n");
	printf(" |  1 - Start\n");
	printf(" |  2 - Exit the program\n");
	printf("\nSelect an option: ");

	scanf("%d", &opt);

	return opt;
}

char str1[11];

void convertMinusculo()
{
	int i = 0;

	while (str1[i] != '\0')
	{
		if (str1[i] == ' ')
		{
			str1[i] = ' ';
			i++;
		}
		str1[i] = str1[i] | (1 << 5);
		i++;
	}
}

int main()
{
	int optMenu;

	while ((optMenu = menu()) != 2)
	{
		system("cls");

		if (optMenu == 1)
		{
			printf("Digite a String: ");

			fflush(stdin);
			gets(str1);

			convertMinusculo();
			printf("%s", str1);

			printf("\n");
			system("pause");
		}
	}

	return 0;
}

#endif