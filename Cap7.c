#include "stdio.h"
#include "stdlib.h"

#define AZUL "\x1b[34m"
#define RESET "\x1b[0m"

#define ex2

/*
OBS.: Todos os programa devem ser finalizados pelo usuario.

1 - Escreva um programa que tem uma estrutura da dados com os membros abaixo.
    Receba dados via teclado em uma funcao e imprima estes conteudos no video,
    em outra funcao, no seguinte formato.
     estrutura: char, int, long, float, double, unsigned char, unsigned int, 
                unsigned long

            10        20        30        40        50        60        70
    1234567890123456789012345678901234567890123456789012345678901234567890
        int                 long                float     double          
              unsigned int        unsigned long       char      unsigned char 

4 - Escreva um programa com a estrutura de dados abaixo. Defina um vetor de
    estrutura de 4 elementos. Receba dados via teclado e imprima-os no video.
    Faca um menu com as seguintes opcoes:
    1 - receber todos os dados
    2 - imprime todos os dados 
    3 - calcula o IMC de todas as pessoas. 
    4 - sair
        Calculo do IMC = peso/(altura*altura).
        estrutura: nome, peso, altura
*/

#ifdef ex1

/*
2 - Escreva um programa com a estrutura de dados abaixo. Defina um vetor de
    estruturas de 4 elementos. Receba os dados pelo teclado em uma funcao 
    e imprima-os no video em uma funcao. Utilize vetor de estruturas.
    Fa a um menu com uma opcao para saida do programa. 
		estrutura: nome, end, cidade, estado, cep
*/

typedef struct {
    char nome[25];
    char end[50];
    char cidade[25];
    char estado[25];
    char cep[10];
} Person;

Person person;

int menu() {
    int option;

    system("cls");

    printf(AZUL "=============================\n");
    printf("      Person Register\n");
    printf("=============================\n");
    printf("\n");
    printf(" | 1 - Create Person\n");
    printf(" | 2 - Print Person\n");
    printf(" | 3 - Exit the program\n");
    printf("\nSelect an option: " RESET);

    scanf("%d", &option);

    return option;
}

void registerPerson() {
    printf(AZUL " - Enter the values - \n" RESET);

    fflush(stdin);

    printf(AZUL "Name: " RESET);
    gets(person.nome);

    printf(AZUL "Addres: " RESET);
    gets(person.end);
    
    printf(AZUL "City: " RESET);
    gets(person.cidade);

    printf(AZUL "State: " RESET);
    gets(person.estado);

    printf(AZUL "ZipCode: " RESET);
    gets(person.cep);

    printf("\n");
}

void printPerson() {
    printf(AZUL " - Person Informations - \n" RESET);
    printf(AZUL "Name:" RESET " %s\n", person.nome);
    printf(AZUL "Addres:" RESET " %s\n", person.end);
    printf(AZUL "City:" RESET " %s\n", person.cidade);
    printf(AZUL "State:" RESET "%s\n", person.estado);
    printf(AZUL "ZipCode:" RESET " %s\n \n", person.cep);
}

int main() {
    int optMenu;

    while ((optMenu = menu()) != 3) {
        if (optMenu == 1) {
            system("cls");

            registerPerson();
            
            system("pause");
        }

        if (optMenu == 2) {
            system("cls");

            printPerson();
            
            system("pause");
        }
    }
}

#endif

// ================================================================================

#ifdef ex2

/*
3 - Escreva um programa com a estrutura de dados abaixo. Receba 2 datas via
    teclado na funcao main(). Faca uma funcao que calcule o numero de dias 
    entre elas e mostre o resultado no video na funcao main(). 
    Utilize vetor de estruturas.
                estrutura: dia, mes, ano
*/

typedef struct {
    int day;
    int month;
    int year;
} Date;

Date date[2];

int menu() {
    int option;

    system("cls");

    printf(AZUL "=============================\n");
    printf("      Date Operation\n");
    printf("=============================\n");
    printf("\n");
    printf(" | 1 - Start\n");
    printf(" | 2 - Exit the program\n");
    printf("\nSelect an option: " RESET);

    scanf("%d", &option);

    return option;
}

int main() {
    int optMenu;

    while ((optMenu = menu()) != 2) {
        if (optMenu == 1) {
            system("cls");

            printf("Enter the first date: ");
            
            system("pause");
        }
    }
}

#endif