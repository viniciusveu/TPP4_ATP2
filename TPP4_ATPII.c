/*
Trabalho Prático de Programação 04
Algorítmos e Técnicas de Programação II
-Vinícius Vedovotto
-João Pedro Silva Baptista
Ciência da Computação - FCT/UNESP, 2017

Suponha a existência de dois arquivos de números inteiros (ordenados) com tamanho m e n, respectivamente.
Escreva um programa que lê ambos os arquivos e seja capaz de gerar um terceiro arquivo, de modo que este último também esteja ordenado 
e seja relativo a uma das operações abaixo:
-intersecção entre os dois conjuntos(1);
-união entre os dois conjuntos(2);
-diferença A-B(3);
-diferença B-A(3);
Lembrem-se, parâmetros do tipo streams(arquivos) só podem ser passados por endereço.*/ 

#include <stdio.h>
#include <stdlib.h>

FILE *f1, *f2;
const int tam = 50;

int main(int argc, char *argv[]) {
    if(!argc) {
        printf("Erro nos parâmetros de entrada!");
        return 1;
    }
    else {
        char arq1[tam], arq2[tam], arq3[tam];

        printf("Entre com o nome do 1º arquivo: ");
        fgets(arq1, tam, stdin);

        printf("Entre com o nome do 2º arquivo: ");
        fgets(arq2, tam, stdin);

        if( (f1 = fopen(arq1, "r")) == NULL ) {
            printf("Erro na abertuda do arquivo %s!", arq1);
            exit(1);
        }

        
    }
    puts("\n\n");
    system("PAUSE");
    return 0;
}
