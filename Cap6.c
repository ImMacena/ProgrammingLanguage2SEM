#include "stdio.h"
#include "stdlib.h"

#define ex1

/*
OBS.:Todos os programa devem ser finalizados pelo usuario.

2 - Escreva um programa que receba via teclado uma data (dia, mes, e ano).
		Determine o dia da semana desta data.
*/

#ifdef ex1

/*
1 - Escreva um programa para determinar a idade de uma pessoa, em anos, meses e
		dias, recebendo via teclado a data (dia, mes e ano) do seu nascimento e a
		data (dia, mes e ano) atual.
*/

int menu()
{
	int opt = 0;

	system("cls");

	printf("=============================\n");
	printf("      Date Operations\n");
	printf("=============================\n");
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

			
			printf("\n");

			system("pause");
		}
	}
}

#endif

// ================================================================================

#ifdef ex3

/*
3 - Escreva um programa que receba via teclado 2 numeros inteiros e execute
		as operacoes logicas bit a bit AND, OU, OU EXCLUSIVO e imprima-os no
		video no formato decimal e hexadecimal.
*/

int menu()
{
	int opt = 0;

	system("cls");

	printf("=============================\n");
	printf("     Logical Operations\n");
	printf("=============================\n");
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
			printf("\nAND: %d + %d: %d\n", input1, input2, (input1 && input2));
			printf("OR: %d - %d: %d\n", input1, input2, (input1 || input2));
			printf("XOR: %d * %d: %d\n", input1, input2, (input1 ^ input2));

			printf("\n");

			system("pause");
		}
	}
}

#endif

// ================================================================================

#ifdef ex4

/*
4 - Escreva um programa que receba via teclado 2 numeros inteiros e
		imprima-os no video com o resultado das 4 operacoes aritmeticas.
*/

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
			printf("\nSum: %d + %d: %d\n", input1, input2, (input1 + input2));
			printf("Subtraction: %d - %d: %d\n", input1, input2, (input1 - input2));
			printf("Multiplication: %d * %d: %d\n", input1, input2, (input1 * input2));
			printf("Division: %d / %d: %.3f\n", input1, input2, (input1 / (double)input2));

			printf("\n");

			system("pause");
		}
	}
}

#endif

// ================================================================================

#ifdef ex5

/*
5 - Reescreva o exercicio anterior utilizando operadores de atribuicao
		composta.
*/

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
	int optMenu, input1, input2, sumRes, subRes, multRes;
	double divRes;

	while ((optMenu = menu()) != 2)
	{
		if (optMenu == 1)
		{
			system("cls");

			printf("Enter the first value: ");
			scanf("%d", &input1);

			sumRes = input1;
			subRes = input1;
			multRes = input1;
			divRes = (double)input1;

			printf("Enter the second value: ");
			scanf("%d", &input2);

			sumRes += input2;
			subRes -= input2;
			multRes *= input2;
			divRes /= input2;

			system("cls");

			printf("- RESULTS - \n");
			printf("\nSum: %d + %d: %d\n", input1, input2, sumRes);
			printf("Subtraction: %d - %d: %d\n", input1, input2, subRes);
			printf("Multiplication: %d * %d: %d\n", input1, input2, multRes);
			printf("Division: %d / %d: %.3f\n", input1, input2, divRes);

			printf("\n");

			system("pause");
		}
	}
}

#endif