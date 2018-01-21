/*Funções:
    -Entrar com valores aleatórios nos arquivos;
    -Impressão
*/

//============================================================================================================================

/*Lista na tela uma breve descrição das funcionalidades do
programa e a sintaxe de seu uso.*/

#include "functions.h"
#define ERROR "ERRO NA ABERTURA DO ARQUIVO!\n"

void comoUsar(void) {
    printf("O programa TPP4 calcula: \n\n");
    printf("-intersecção entre os dois conjuntos(1); \n");
    printf("-união entre os dois conjuntos(2); \n");
    printf("-diferença A-B(3); \n");
    printf("-diferença B-A(3); \n\n");
    
    printf("Para criar um arquivo TEXTO com nome arq1 com n elementos ordenados crescentemente: \n");
    printf("\t\t=================\n");
    printf("\t\t= TPP4 t arq1 n =\n");
    printf("\t\t=================\n\n");
   
    printf("Para criar um arquivo BINARIO com nome arq1 com n elementos ordenados crescentemente: \n"); 
    printf("\t\t=================\n");
    printf("\t\t= TPP4 b arq1 n =\n");
    printf("\t\t=================\n\n");
   
    printf("Cria o arquivo TEXTO com nome arq3 que é o resultado da intersecção dos elementos dos arquivos TEXTOS arq1 e arq2: \n");
    printf("\t\t===========================\n");
    printf("\t\t= TPP4 t 1 arq1 arq2 arq3 =\n");
    printf("\t\t===========================\n\n");   
   
    printf("Cria o arquivo BINARIO com nome arq3 que é o resultado da intersecção dos elementos dos arquivos BINARIOS arq1 e arq2: \n");
    printf("\t\t===========================\n");
    printf("\t\t= TPP4 b 1 arq1 arq2 arq3 =\n");
    printf("\t\t===========================\n\n"); 

    printf("Cria o arquivo TEXTO com nome arq3 que é resultado da união dos elementos dos arquivos TEXTOS arq1 e arq2: \n");               
    printf("\t\t===========================\n");
    printf("\t\t= TPP4 t 2 arq1 arq2 arq3 =\n");
    printf("\t\t===========================\n\n"); 

    printf("Cria o arquivo BINARIO com nome arq3 que é resultado da união dos elementos dos arquivos BINARIOS arq1 e arq2: \n");
    printf("\t\t===========================\n");
    printf("\t\t= TPP4 b 2 arq1 arq2 arq3 =\n");
    printf("\t\t===========================\n\n");

    printf("Cria o arquivo TEXTO com nome arq3 que é resultado da diferença dos elementos do arquivo TEXTO arq1, menos os elementos do arquivo TEXTO arq2: \n");
    printf("\t\t===========================\n");
    printf("\t\t= TPP4 t 3 arq1 arq2 arq3 =\n");
    printf("\t\t===========================\n\n");

    printf("Cria o arquivo BINARIO com nome arq3 que é resultado da diferença dos elementos do arquivo BINARIO arq1, menos os elementos do arquivo BINARIO arq2: \n");
    printf("\t\t===========================\n");
    printf("\t\t= TPP4 b 2 arq1 arq2 arq3 =\n");
    printf("\t\t===========================\n\n");   
    
    printf("Lista na tela os elementos pertencentes ao arquivo do tipo TEXTO arq1: \n");
    printf("\t\t===============\n");
    printf("\t\t= TPP4 t arq1 =\n");
    printf("\t\t===============\n\n");

    printf("Lista na tela os elementos pertencentes ao arquivo do tipo BINARIO arq1: \n");
    printf("\t\t===============\n");
    printf("\t\t= TPP4 b arq1 =\n");
    printf("\t\t===============\n\n");

    printf("Lista na tela uma breve descrição das funcionalidades do programa e a sintaxe de seu uso: \n");
    printf("\t\t========\n");
    printf("\t\t= TPP4 =\n");
    printf("\t\t========\n\n");

    printf("-> Escolha um comando e corra pro abraço! =)\n");

    return;
}

//============================================================================================================================

void checkFile(FILE *f1){
    if(f1 == NULL){
        printf(ERROR);
        exit(1);
    }
}

void printBinArc(FILE *f1){
    double n;
    while(1){
	    fread(&n,sizeof(double),1, f1);
		if(feof(f1)) break;
		printf("%.2f \n",n);
	}
}

void arcRandom(FILE *f){
	double temp;
    int M = 10, i;
	srand(time(NULL));
	for(i=0;i<M;i++){
		temp = rand()%100;
		fwrite(&temp,sizeof(double),1,f);
	}
	return;
}

void copiarArquivoTXT(FILE *f1, FILE *f2){ // Copia para tipo texto
    char arq1[1000];
    while(fgets(arq1, 1000, f1))
        fputs(arq1, f2);
}

void copiarArquivoBIN(FILE *f1, FILE *f2){
    double arq1[sizeof(double)];
    while(fread(arq1, sizeof(double), 1, f1))
        fwrite(arq1, sizeof(double), 1, f2);
    
}

void diferenzaBIN(FILE *f1, FILE *f2, FILE *f3){
    //diferença f1 - f2
    int aux = 0, aux2 = -1, i, j;
    rewind(f1);
    rewind(f2);
    while(!feof(f1)){
        fread(&i, sizeof(int), 1, f1);
        while(!feof(f2)){
            fread(&j, sizeof(int), 1, f2);
            if(i == j || aux2 == i) {
                aux = 1;
                //*aux2 = i; 
                break;
            }
        }
        if(aux == 1) 
            aux = 0;
        else if(aux == 0){
            printf("\n \n IMPRIMINDO \n \n");
            fwrite(&i, sizeof(int), 1, f3);
        }
        rewind(f2);
    }
}

void diferenzaTXT(FILE *f1, FILE *f2, FILE *f3){
    while(!feof(f1)){
        fscanf(f1, "%d", &i);
        while(!feof(f2)){
            fscanf(f2, "%d", &j);
            if(i == j || aux2 == i){
                aux = 1;
                break;
            } 
        }
        if(aux == 1)
            aux = 0;
        else if(aux == 0)
            fprintf(f3, "%d ", i);
        rewind(f2);
    }
}


//============================================================================================================================

/*Função para gerar valores aleatórios.*/

/*int geraNum(int dim) {
    time_t t;
    int i;
    srand((unsigned) time(&t));
    for(i=0; i<dim; i++)    {
    }
}*/

//============================================================================================================================
//Abrir arquivos:

/*short abrirArq(FILE *f, char nomeArq[], char modAcess) {
    f = fopen(nomeArq, modAcess);
    if( (f == NULL) {
        printf("ERRO na abertura do arquivo %s!!!\n", argv[2]);
        return 0;
    }
    return 1;
}
*/