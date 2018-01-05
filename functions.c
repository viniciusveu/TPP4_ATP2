/*Funções:
    -Entrar com valores aleatórios nos arquivos;
    -Impressão
*/

//============================================================================================================================

/*Lista na tela uma breve descrição das funcionalidades do
programa e a sintaxe de seu uso.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
   
    printf("Cria o arquivo TEXTO com nome arq3 que é 0 resultado da intersecção dos elementos dos arquivos TEXTOS arq1 e arq2: \n");
    printf("\t\t===========================\n");
    printf("\t\t= TPP4 t 1 arq1 arq2 arq3 =\n");
    printf("\t\t===========================\n\n");   
   
    printf("Cria o arquivo BINARIO com nome arq3 que é 0 resultado da intersecção dos elementos dos arquivos BINARIOS arq1 e arq2: \n");
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

/*Função para gerar valores aleatórios.*/

/*int geraNum(int dim) {
    time_t t;
    int i;

    srand((unsigned) time(&t));
    for(i=0; i<dim; i++)    {

    }
}*/

//============================================================================================================================