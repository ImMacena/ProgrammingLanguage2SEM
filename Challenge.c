#include <stdio.h>

char filme1[20], filme2[20], filme3[20];
int qntdFilme1, qntdFilme2, qntdFilme3, cdMenu;
FILE *fp;

int comparaStrings(char *str1, char *str2);
void EntradaDeDados();
void ListarDados();
void PesquisaFilme();
void AlteraDados();
void PesquisaLetra();
void ExcluirDados();

int main(int argc,char *argv[]) {
    do{
    printf("\n\n1 - Entrada de dados.\n2 - Listar todos os dados.\n3 - Pesquisa um filme pelo nome completo e mostra os resultados na tela.\n4 - Pesquisa o filme pela 1. letra.\n5 - Altera dados.\n6 - Exclui dados.\n7 - Saida.\n-->");
    scanf("%d", &cdMenu);
        switch(cdMenu)
        {
        case 1:
            EntradaDeDados();
            break;
        case 2:
            ListarDados();
            break;
        case 3:
            PesquisaFilme();
            break;
        case 4:
            PesquisaLetra();
            break;
        case 5:
            AlteraDados();
            break;
        case 6:
            ExcluirDados();
            break;
        case 7:
            printf("Saindo......");
            break;
        }
    }while(cdMenu != 7);
    return 0;
}
int comparaStrings(char *str1, char *str2) {
    int i = 0;

    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return 0;
        }
        i++;
    }

    if (str1[i] == '\0' && str2[i] == '\0') {
        return 1;
    }

    return 0;
}
void EntradaDeDados()
{
    if ((fp=fopen ("arq.txt","w"))==NULL)
            printf ("Erro na abertura/criacao do arquivo.");
        printf("\n\n====Entrada de dados====");
        for(int i = 0; i< 3 ; i ++){
            printf("\n\n===Filme %d===\n", i+1);
            printf("Digite o nome: ");
            fflush(stdin);

            switch(i)
            {
            case 0:
                gets(filme1);
                break;
            case 1:
                gets(filme2);
                while(comparaStrings(filme1, filme2)){
                    printf("Filme ja adicionado...\nDigite outro: ");
                    gets(filme2);
                }
                break;
            case 2:
                gets(filme3);
                while(comparaStrings(filme1, filme3) || comparaStrings(filme2, filme3)){
                    printf("Filme ja adicionado...\nDigite outro: ");
                    gets(filme3);
                }
                break;
            }
            printf("Digite a quantidade: ");
            fflush(stdin);

            switch(i)
            {
            case 0:
                scanf("%d", &qntdFilme1);
                break;
            case 1:
                scanf("%d", &qntdFilme2);
                break;
            case 2:
                scanf("%d", &qntdFilme3);
                break;
            }
            getchar();

            fwrite((i == 0 ? filme1 : (i == 1 ? filme2 : filme3)), sizeof(filme1), 1, fp);
            fwrite((i == 0 ? &qntdFilme1: (i == 1 ? &qntdFilme2 : &qntdFilme3)), sizeof(int), 1, fp);

        }
        fclose(fp);
}
void ListarDados() {
    int qntdAtual;
    if ((fp = fopen("arq.txt", "r")) == NULL) {
        printf("Erro na abertura/criacao do arquivo.\n");
        return;
    }
    printf("\n\n===Listagem de filmes===\n");
    for (int i = 0; i < 3; i++) {
    int filmeExcluido = 1;
        switch (i) {
            case 0:
                fread(filme1, 20, 1, fp);
                for (int j = 0; j < 20; j++) {
                    if (filme1[j] != ' ' && filme1[j] != '\0') {
                    filmeExcluido = 0;
                    break;
                    }
                }
                fread(&qntdFilme1, sizeof(int), 1, fp);
                qntdAtual = qntdFilme1;
                if (!filmeExcluido && qntdAtual > 0) {
                    printf("\n\nFilme: %s\n", filme1);
                    printf("Quantidade: %d\n\n", qntdAtual);
                }
                break;
            case 1:
                fread(filme2, 20, 1, fp);
                for (int j = 0; j < 20; j++) {
                    if (filme2[j] != ' ' && filme2[j] != '\0') {
                    filmeExcluido = 0;
                    break;
                    }
                }
                fread(&qntdFilme2, sizeof(int), 1, fp);
                qntdAtual = qntdFilme2;
                if (!filmeExcluido && qntdAtual > 0) {
                    printf("Filme: %s\n", filme2);
                    printf("Quantidade: %d\n\n", qntdAtual);
                }
                break;
            case 2:
                fread(filme3, 20, 1, fp);
                for (int j = 0; j < 20; j++) {
                    if (filme3[j] != ' ' && filme3[j] != '\0') {
                    filmeExcluido = 0;
                    break;
                    }
                }
                fread(&qntdFilme3, sizeof(int), 1, fp);
                qntdAtual = qntdFilme3;
                if (!filmeExcluido && qntdAtual > 0) {
                    printf("Filme: %s\n", filme3);
                    printf("Quantidade: %d\n\n", qntdAtual);
                }
                break;
        }
    }

    fclose(fp);
}
void PesquisaFilme()
{
    char filmePesquisa[20];
    int i;
    if ((fp=fopen ("arq.txt","r"))==NULL)
        printf ("Erro na abertura/criacao do arquivo.");
    printf("\n\n====Pesquisa por nome completo====\n\n");
    for(i = 0; i<3; i++){
        switch(i)
        {
            case 0:
                fread(filme1, 20 , 1, fp);
                fread(&qntdFilme1, sizeof(int), 1, fp);
                break;
            case 1:
                fread(filme2, 20 , 1, fp);
                fread(&qntdFilme2, sizeof(int), 1, fp);
                break;
            case 2:
                fread(filme3, 20 , 1, fp);
                fread(&qntdFilme3, sizeof(int), 1, fp);
                break;
        }
    }
    printf("Digite: ");
    fflush(stdin);
    gets(filmePesquisa);

    for(i = 0;i<3;i++){
        switch(i)
        {
            case 0:
                if(comparaStrings(filme1, filmePesquisa)){
                    printf("\n\n---Filme encontrado---");
                    printf("\nFilme: %s\nQuantidade: %d\n", filme1, qntdFilme1);
                }
                break;
            case 1:
                if(comparaStrings(filme2, filmePesquisa))
                    printf("Filme: %s\nQuantidade: %d\n", filme2, qntdFilme2);
                break;
            case 2:
                if(comparaStrings(filme3, filmePesquisa))
                    printf("Filme: %s\nQuantidade: %d\n", filme3, qntdFilme3);
                break;
        }
    }
    if((comparaStrings(filme1, filmePesquisa) == 0) && (comparaStrings(filme2, filmePesquisa) == 0) && (comparaStrings(filme3, filmePesquisa) == 0))
        printf("\n\n***Filme nao econtrado***\n");

    fclose(fp);
}
void AlteraDados()
{
    char filmePesquisa[20];
    int i, opcaoAltera;
    if ((fp=fopen ("arq.txt","w+"))==NULL)
        printf ("Erro na abertura/criacao do arquivo.");
    for(i = 0; i<3; i++){
        switch(i)
        {
            case 0:
                fread(filme1, 20 , 1, fp);
                fread(&qntdFilme1, sizeof(int), 1, fp);
                break;
            case 1:
                fread(filme2, 20 , 1, fp);
                fread(&qntdFilme2, sizeof(int), 1, fp);
                break;
            case 2:
                fread(filme3, 20 , 1, fp);
                fread(&qntdFilme3, sizeof(int), 1, fp);
                break;
        }
    }
    printf("Digite o filme que deseja Alterar dados: ");
    fflush(stdin);
    gets(filmePesquisa);

    if((comparaStrings(filme1, filmePesquisa) == 0) && (comparaStrings(filme2, filmePesquisa) == 0) && (comparaStrings(filme3, filmePesquisa) == 0))
        printf("Filme nao econtrado\n");

    for(i = 0;i<3;i++){
        switch(i)
        {
            case 0:
                if(comparaStrings(filme1, filmePesquisa)){
                    printf("====== %s =======\n", filme1);
                    printf("1- Alterar nome do filme\n2- Alterar quantidade do filme\n===>");
                    scanf("%d", &opcaoAltera);
                    switch (opcaoAltera)
                    {
                        case 1:
                            do{
                                printf("Digite o novo nome do filme: ");
                                fflush(stdin);
                                gets(filme1);
                                if(comparaStrings(filme1, filme2) || comparaStrings(filme1, filme3)){
                                    printf("Digitou o nome de um filme ja existente no arquivo...\nTente novamente\n");
                                }
                            }while(comparaStrings(filme1, filme2) || comparaStrings(filme1, filme3));
                        break;
                        case 2:
                            printf("Digite a nova quantidade do filme: ");
                            fflush(stdin);
                            scanf("%d", &qntdFilme1);
                        break;
                    }
                }
                break;
            case 1:
                if(comparaStrings(filme2, filmePesquisa)){
                    printf("====== %s =======\n", filme2);
                    printf("1- Alterar nome do filme\n2- Alterar quantidade do filme\n===>");
                    scanf("%d", &opcaoAltera);
                    switch (opcaoAltera)
                    {
                        case 1:
                            do{
                                printf("Digite o novo nome do filme: ");
                                fflush(stdin);
                                gets(filme2);
                                if(comparaStrings(filme2, filme1) || comparaStrings(filme2, filme3)){
                                    printf("Digitou o nome de um filme ja existente no arquivo...\nTente novamente\n");
                                }
                            }while(comparaStrings(filme2, filme1) || comparaStrings(filme2, filme3));
                        break;
                        case 2:
                            printf("Digite a nova quantidade do filme: ");
                            fflush(stdin);
                            scanf("%d", &qntdFilme2);
                        break;
                    }
                }
                break;
            case 2:
                if(comparaStrings(filme3, filmePesquisa)){
                    printf("====== %s =======\n", filme3);
                    printf("1- Alterar nome do filme\n2- Alterar quantidade do filme\n===>");
                    scanf("%d", &opcaoAltera);
                    switch (opcaoAltera)
                    {
                        case 1:
                            do{
                                printf("Digite o novo nome do filme: ");
                                fflush(stdin);
                                gets(filme3);
                                if(comparaStrings(filme3, filme1) || comparaStrings(filme3, filme2)){
                                    printf("Digitou o nome de um filme ja existente no arquivo...\nTente novamente\n");
                                }
                            }while(comparaStrings(filme3, filme1) || comparaStrings(filme3, filme2));
                        break;
                        case 2:
                            printf("Digite a nova quantidade do filme: ");
                            fflush(stdin);
                            scanf("%d", &qntdFilme3);
                        break;
                    }
                }
                break;
        }
        fwrite((i == 0 ? filme1 : (i == 1 ? filme2 : filme3)), sizeof(filme1), 1, fp);
        fwrite((i == 0 ? &qntdFilme1: (i == 1 ? &qntdFilme2 : &qntdFilme3)), sizeof(int), 1, fp);
    }
    fclose(fp);
}
void PesquisaLetra()
{
    int i;
    char letraPesquisa;
    if ((fp=fopen ("arq.txt","r"))==NULL)
        printf ("Erro na abertura/criacao do arquivo.");
    printf("====Pesquisa por primeira letra====\n\n");
    for(i = 0; i<3; i++){
        switch(i)
        {
            case 0:
                fread(filme1, 20 , 1, fp);
                fread(&qntdFilme1, sizeof(int), 1, fp);
                break;
            case 1:
                fread(filme2, 20 , 1, fp);
                fread(&qntdFilme2, sizeof(int), 1, fp);
                break;
            case 2:
                fread(filme3, 20 , 1, fp);
                fread(&qntdFilme3, sizeof(int), 1, fp);
                break;
        }
    }
    printf("Digite: ");
    fflush(stdin);
    scanf("%c", &letraPesquisa);

    for(i = 0;i<3;i++){
        if(i == 0){
            if(filme1[0] == letraPesquisa)
                    printf("\n\nFilme: %s\nQuantidade: %d\n", filme1, qntdFilme1);
        }
        if(i == 1){
            if(filme2[0] == letraPesquisa)
                printf("\n\nFilme: %s\nQuantidade: %d\n", filme2, qntdFilme2);
        }
        if(i == 2){
            if(filme3[0] == letraPesquisa)
                printf("\n\nFilme: %s\nQuantidade: %d\n", filme3, qntdFilme3);
        }
    }
    if((filme1[0] != letraPesquisa) && (filme2[0] != letraPesquisa) && (filme3[0] != letraPesquisa))
        printf("\\n\n***Filme nao encontrado***\n");
}
void ExcluirDados() {
    char filmePesquisa[20];
    int i, opcaoAltera;

    if ((fp = fopen("arq.txt", "r")) == NULL) {
        printf("Erro na abertura/criacao do arquivo.");
        return;
    }

    for (i = 0; i < 3; i++) {
        switch (i) {
            case 0:
                fread(filme1, 20, 1, fp);
                fread(&qntdFilme1, sizeof(int), 1, fp);
                break;
            case 1:
                fread(filme2, 20, 1, fp);
                fread(&qntdFilme2, sizeof(int), 1, fp);
                break;
            case 2:
                fread(filme3, 20, 1, fp);
                fread(&qntdFilme3, sizeof(int), 1, fp);
                break;
        }
    }
    fclose(fp);

    printf("Digite o filme que deseja Excluir: ");
    fflush(stdin);
    gets(filmePesquisa);

    if ((comparaStrings(filme1, filmePesquisa) == 0) && (comparaStrings(filme2, filmePesquisa) == 0) && (comparaStrings(filme3, filmePesquisa) == 0)) {
        printf("Filme nao encontrado\n");
        return;
    }

    if ((fp = fopen("arq.txt", "w")) == NULL) {
        printf("Erro na abertura/criacao do arquivo.");
        return;
    }

    for (i = 0; i < 3; i++) {
        switch (i) {
            case 0:
                if (comparaStrings(filme1, filmePesquisa)) {
                    printf("====== %s =======\n", filme1);
                    printf("1- Confirma\n2- Cancela\n===>");
                    scanf("%d", &opcaoAltera);
                    if (opcaoAltera == 1) {
                        for (int j = 0; j < sizeof(filme1); j++) {
                            filme1[j] = ' ';
                        }
                        qntdFilme1 = 0; // Zera a quantidade também
                    } else {
                        printf("Exclusao cancelada\n");
                        return;
                    }
                }
                break;
            case 1:
                if (comparaStrings(filme2, filmePesquisa)) {
                    printf("====== %s =======\n", filme2);
                    printf("1- Confirma\n2- Cancela\n===>");
                    scanf("%d", &opcaoAltera);
                    if (opcaoAltera == 1) {
                        for (int j = 0; j < sizeof(filme2); j++) {
                            filme2[j] = ' ';
                        }
                        qntdFilme2 = 0;
                    } else {
                        printf("Exclusao cancelada\n");
                        return;
                    }
                }
                break;
            case 2:
                if (comparaStrings(filme3, filmePesquisa)) {
                    printf("====== %s =======\n", filme3);
                    printf("1- Confirma\n2- Cancela\n===>");
                    scanf("%d", &opcaoAltera);
                    if (opcaoAltera == 1) {
                        for (int j = 0; j < sizeof(filme3); j++) {
                            filme3[j] = ' ';
                        }
                        qntdFilme3 = 0;
                    } else {
                        printf("Exclusao cancelada\n");
                        return;
                    }
                }
                break;
        }
        fwrite((i == 0 ? filme1 : (i == 1 ? filme2 : filme3)), sizeof(filme1), 1, fp);
        fwrite((i == 0 ? &qntdFilme1 : (i == 1 ? &qntdFilme2 : &qntdFilme3)), sizeof(int), 1, fp);
    }
    fclose(fp);
}
