#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

typedef struct app{
char nome[15];
int id;
int tam;
}tApp;

void cabecalho();
void inicializa(tApp vetor[50]);
void remover(tApp vetor[50], int id);
void copiar(tApp aplicd[50], tApp aplico[50], int id);
void StoreED(tApp aplic[50], tApp MyApps[50], tApp worka[9]);
int indexist(tApp aplics[50], int ind);
void mostrarApps(tApp aplics[50]);
void MyAppsED(tApp vetor[50], tApp vetorr[50], tApp worka[9]);
void AppRumED(tApp vetorexe[50]);
void mostrarWork(tApp vetor[9]);

int main(){
setlocale(LC_ALL, "");
int opcao, i;
tApp aplic[50];
tApp MyApps[50];
tApp AppRum[50];
tApp worka[9];



//inicializando os vetores com um valor de índice inválido -1.
inicializa(aplic);
inicializa(MyApps);
inicializa(AppRum);
inicializa(worka);


/*
 MobileED
 1 - StoreED
    1.0 - lista de apps
    1.1 - Instalar
 2 - MeusAppsED
    2.1 - Executar
    2.2 - Desinstalar
 3 - AppRumED
    3.1 - Parar App
 0 - Sair
*/

do{
    cabecalho();
    mostrarWork(worka);
    printf("|| 1 - StoreED |");
    printf("| 2 - MeusAppsED |");
    printf("| 3 - AppRumED ||");
    printf("0 - Sair\n");

    printf("Digite uma opção: ");
    scanf("%d", &opcao);

    switch(opcao){
        case 1:
        StoreED(aplic, MyApps, worka);
        break;


        case 2:
        MyAppsED(MyApps, AppRum, worka);

        break;


        case 3:
        AppRumED(AppRum);
        break;

        case 0:
            printf("\n\nObrigado por utilizar os nossos serviços!\n\n");
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
    printf("MobileED\n");
    printf("---------------------------------------\n\n");
}


void StoreED(tApp aplic[50], tApp MyApp[50], tApp worka[9]){
    tApp aux;
    int count = 0, i=0, id;
    char instalar;

    FILE *arquivo;

    arquivo = fopen("apps.txt", "rb");

    if(arquivo == NULL){
            //nesse caso nao foi possível ler o arquivo.
        printf("Não foi possível abrir o arquivo! ");
        return;
    }
    else{
        //nesse caso o arquivo foi lido com sucesso.
        cabecalho();
        printf("\n------StoreED----------\n");
        while(fread(&aux, sizeof(tApp), 1, arquivo) == 1){
            aplic[count].id = aux.id;
            strcpy(aplic[count].nome, aux.nome);
            aplic[count].tam = aux.tam;



            count++;
        }
            mostrarApps(aplic);


        printf("\nDeseja instalar algum App?(s/n): ");
        scanf(" %c", &instalar);

        if(instalar == 's'){
            printf("Digite o índice do App: ");
            scanf("%d", &id);


            if(indexist(aplic, id) == 1){

                    if(indexist(MyApp, id) == 1){
                        printf("\n\nApp já instalado. Não é possível instalar novamente.\n\n");
                        getch();
                    }

                    else if(indexist(MyApp, id) == 0){
                        copiar(MyApp, aplic, id); //install();
                        int k;
                        for(k = 0; k< 9; k++){
                            if(worka[k].id == -1){
                                copiar(worka, aplic, id);
                                break;
                            }
                        }
                        printf("\n\n%s foi instalado com sucesso!\n\n", aplic[id-1].nome);
                        getch();
                    }

            }
            if(indexist(aplic, id) == 0){
                printf("Indice de App inexistente!!! \n\n\n");
                getch();
                StoreED(aplic, MyApp, worka);

            }


        }


    }
    fclose(arquivo);
}

int indexist(tApp vetor[50], int ind){
    int i;
    for(i=0; i<50; i++){
        if(vetor[i].id == ind){
            return 1; //nesse caso o indice existe
        }
    }
            return 0; //nesse caso o indice nao existe

}


void copiar(tApp vetord[50], tApp vetoro[50], int id){
    int pos=0, i;

    for(i=0; i<50; i++){
        if(vetord[i].id != -1){
            pos++;
        }
        else{
            break;
        }
    }

    vetord[pos].id = vetoro[id-1].id;
    strcpy(vetord[pos].nome, vetoro[id-1].nome);
    vetord[pos].tam = vetoro[id-1].tam;

}


void mostrarApps(tApp vetor[50]){
    int i=0;
        for(i=0; i<50; i++){
            if((vetor[i].id != -1) && vetor[i].tam != 72){
            printf("id do App: %d   || ", vetor[i].id);
            printf("Nome do App: %s || ", vetor[i].nome);
            printf("Tamanho: %d", vetor[i].tam);
            printf("\n--------------------------------------------------\n");
            }
        }

}

void mostrarWork(tApp vetor[9]){
    int i=0;
        for(i=0; i<50; i++){
            if(vetor[i].id != -1){
            printf("|| %s || ", vetor[i].nome);
            printf("\n----------------------\n");
            }
        }

}


void MyAppsED(tApp vetor[50], tApp vetorr[50], tApp worka[9]){
    int quant, opcao, id;


        do{

            cabecalho();
    printf("\n------MyAppsED----------\n");

    mostrarApps(vetor);

                printf("1 - Executar\n");
                printf("2 - Desinstalar\n");
                printf("0 - voltar\n");

                printf("Digite uma opção: ");
                scanf("%d", &opcao);

                    if(opcao == 1){

                        printf("Digite o id para executar do App: ");
                        scanf("%d", &id);

                    if(indexist(vetor, id) == 1){

                            if(indexist(vetorr, id) == 1){
                                printf("O App já está em execução.");
                                getch();
                            }

                            else if(indexist(vetorr, id) == 0){
                            copiar(vetorr, vetor, id); //executar();
                            printf("Executando app...");
                            getch();

                            }


                        }
                    if(indexist(vetor, id) == 0){
                    printf("Indice de App inexistente!!! \n\n\n");

                        }
                    }

                    if(opcao == 2){

                        printf("Digite o id do App: ");
                        scanf("%d", &id);

                        if(indexist(vetor, id) == 1){


                        remover(vetor, id);
                        remover(vetorr, id);
                        remover(worka, id);
                            }
                        else if(indexist(vetor, id) == 0){
                        printf("Indice de App inexistente!!! \n\n\n");
                        getch();
                        break;

                            }
                    }
                    if(opcao == 0){
                    break;
                    }



        }while(1);

}

void inicializa(tApp vetor[50]){
    int i;
    for(i=0; i<50; i++){
        vetor[i].id = -1;
    }


}




void remover(tApp vetor[50], int id){
    int i;
    for(i=0; i<50; i++){
        if(vetor[i].id == id){
                printf("O App %s vai ser removido!\n", vetor[i].nome);
                getch();
                fflush(stdin);
            vetor[i].id = -1;
            break;
        }
    }

    printf("Operação realizada com sucesso!");
    getche();


}

void AppRumED(tApp vetorexe[50]){
    int opcao, id;
    char opc;

    do{
        cabecalho();
        printf("\n------AppRumED----------\n");
        mostrarApps(vetorexe);

        printf("\n1 - Remover App da RAM.");
        printf("\n2 - Limpar toda a RAM.");
        printf("\n0 - Sair\n");
        printf("Digite uma opção: ");
        scanf("%d", &opcao);
            if(opcao == 0){
                break;
            }
            if(opcao == 1){
                    printf("Digite o id do App: ");
                        scanf("%d", &id);

                        if(indexist(vetorexe, id) == 1){


                        remover(vetorexe, id);
                            }
                        else if(indexist(vetorexe, id) == 0){
                        printf("Indice de App inexistente!!! \n\n\n");
                        getch();
                        break;

                            }
            }
            if(opcao == 2){
                fflush(stdin);
                printf("Parar todos os APP?(s/n): ");
                scanf("%c", &opc);
                if(opc == 's'){
                    inicializa(vetorexe);
                }
                if(opc == 'n'){
                    break;
                }

            }

    }while(1);

}



