//ENUNCIADO======================================================================================================================================================
/*
Trabalho Prático de Programação 04
Algorítmos e Técnicas de Programação II
-Vinícius Vedovotto
-João Pedro Silva Baptista
Ciência da Computação - FCT/UNESP, 2017
Suponha a existência de dois arquivos de números inteiros
(ordenados) com tamanho m e n, respectivamente.
Escreva um programa que lê ambos os arquivos e seja capaz
de gerar um terceiro arquivo, de modo que este último também 
esteja ordenado e seja relativo a uma das operações abaixo:
-intersecção entre os dois conjuntos(1);
-união entre os dois conjuntos(2);
-diferença A-B(3);
-diferença B-A(3); 
*/
//======================================================================================================================================================

#include <stdio.h>
#include <stdlib.h>

FILE *f1, *f2, *ff;
const int tam = 50;

//MAIN======================================================================================================================================================

int main(int argc, char *argv[]) {
    switch(argc) {
        case 0: printf("Erro nos parâmetros de entrada!"); break;
        case 1: 
            printf("O programa TPP4 calcula: \n\n");
            printf("-intersecção entre os dois conjuntos(1); \n");
            printf("-união entre os dois conjuntos(2); \n");
            printf("-diferença A-B(3); \n");
            printf("-diferença B-A(3); \n\n");
            
            printf("Para criar um arquivo TEXTO com nome arq1 com n elementos ordenados crescentemente: TPP4 t arq1 n \n");
            printf("Para criar um arquivo BINARIO com nome arq1 com n elementos ordenados crescentemente: TPP4 b arq1 n \n"); 
            printf("Cria o arquivo TEXTO com nome arq3 que é 0 resultado da intersecção dos elementos dos arquivos TEXTOS arq1 e arq2: TPP4 t 1 arq1 arq2 arq3 \n");
            printf("Cria o arquivo BINARIO com nome arq3 que é 0 resultado da intersecção dos elementos dos arquivos BINARIOS arq1 e arq2: TPP4 b 1 arq1 arq2 arq3 \n");
            printf("Cria o arquivo TEXTO com nome arq3 que é resultado da união dos elementos dos arquivos TEXTOS arq1 e arq2: TPP4 t 2 arq1 arq2 arq3 \n");               
            printf("Cria o arquivo BINARIO com nome arq3 que é resultado da união dos elementos dos arquivos BINARIOS arq1 e arq2: TPP4 b 2 arq1 arq2 arq3 \n");
            printf("Cria o arquivo TEXTO com nome arq3 que é resultado da diferença dos elementos do arquivo TEXTO arq1, menos os elementos do arquivo TEXTO arq2: TPP4 t 3 arq1 arq2 arq3");
            printf("Cria o arquivo BINARIO com nome arq3 que é resultado da diferença dos elementos do arquivo BINARIO arq1, menos os elementos do arquivo BINARIO arq2: TPP4 b 3 arq1 arq2 arq3");
            printf("Lista na tela os elementos pertencentes ao arquivo do tipo TEXTO arq1: TPP4 t arq1 \n");
            printf("Lista na tela os elementos pertencentes ao arquivo do tipo BINARIO arq1: TPP4 B arq1 \n");
            printf("Lista na tela uma breve descrição das funcionalidades do programa e a sintaxe de seu uso: TPP4 \n");
            break;
        case 2: 
            if()
            break;
        default: printf("ERRO!");
    }

    
    puts("\n\n");
    system("PAUSE");
    return 0;
}

//======================================================================================================================================================
