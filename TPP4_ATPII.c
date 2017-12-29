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
            
            printf("Para cria um arquivo TEXTO com nome arq1 com n elementos ordenados crescentemente: TPP4 t arq1 n \n");
            printf("Para cria um arquivo BINARIO com nome arq1 com n elementos ordenados crescentemente: TPP4 t arq1 n \n"); break;
        case 3: break;
        default: printf("ERRO!");
    }

    
    puts("\n\n");
    system("PAUSE");
    return 0;
}

//======================================================================================================================================================
