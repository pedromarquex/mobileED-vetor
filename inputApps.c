#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

typedef struct app{
char nome[15];
int id;
int tam;
}tApp;

void cabecalho();
void inputApps();

int main(){
    int opcao;
    setlocale(LC_ALL, "");

do{
    cabecalho();
    printf("1 - Inserir Apps na loja.\n");
    printf("0 - Sair do App.\n");
    printf("\nDigite uma opção: ");
    scanf("%d", &opcao);

    switch(opcao){

    case 1:
        inputApps();
    break;

    case 0:
        printf("\n\nObrigado por utilizar os nossos serviços! *---*\n\n ");
        getch();
        exit(0);
    break;
    }




}while(opcao != 0);

return 0;
}


void cabecalho(){
    system("cls");
    printf("---------------------------------------\n");
    printf("Input Apps *---* \n");
    printf("---------------------------------------\n\n");
}


void inputApps(){
    FILE *arquivo;
    tApp aplics;

    arquivo = fopen("apps.txt", "ab");

    if(arquivo == NULL){
        printf("Não foi possível abrir o arquivo! ");
        return 0;
    }
    else{
        do{
            cabecalho();
            printf("Entre com o nome do App: ");
            scanf("%s", aplics.nome);

            printf("Entre com o tamanho do App: ");
            scanf("%d", &aplics.tam);

            printf("Entre com o id do App: ");
            scanf("%d", &aplics.id);

            printf("id do App: %d\n", aplics.id);
            printf("Nome do App: %s\n", aplics.nome);
            printf("tamanho do App: %d\n\n", aplics.tam);

            fwrite(&aplics, sizeof(tApp), 1, arquivo);

            printf("\n\nDeseja continuar digitando Apps? (s/n)");


        }while(getche() == 's');

        fclose(arquivo);
    }

}
