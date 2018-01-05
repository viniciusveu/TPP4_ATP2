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
#include <locale.h>
#include <time.h>

#include "functions.c"

#define PULA puts("\n")
#define TAM 50

FILE *f1, *f2, *ff;

//MAIN======================================================================================================================================================

int main(int argc, char *argv[]) {
    char arq1[TAM], arq2[TAM], arq3[TAM], ch;
    int cont, val;
    time_t t;
    setlocale(LC_ALL, "Portuguese");
    switch(argc) {
        case 0:
            printf("Erro nos parâmetros de entrada!"); 
            break;
        case 1: //TPP4
            comoUsar();
            break;
        case 2: //TPP4 t arq1
            if(argv[1] == "t") {
                if( (f1=fopen(argv[2], "r") ) != NULL) {
                    printf("ERRO na abertura do arquivo %s!!!", argv[2]);
                    exit(1);
                }
                while ( ch = fgetc(f1) != EOF) {
                    if(ch == '\n') PULA;
                    else printf("%c ", ch);
                }
                if( fclose(f1) != 0 )   
                    printf("ERRO ao fechar o arquivo %s!!!", argv[2]);
            }
            else if(argv[1] == "b") {

            }
            else printf("Erro! Entre com o argumento t se o arquivo for do tipo texto, e b se for do tipo binário.");
            break;
        case 3: //TPP4 t arq1 n
            if(argv[1] == "t") {
                if( (f1=fopen(argv[2], "w") ) != NULL) {
                    printf("ERRO na abertura do arquivo %s!!!", argv[2]);
                    exit(1);
                }
                srand((unsigned) time(&t));
                for(cont=1; cont <= *argv[3]; cont++)
                    val = rand()%1000;
                    fputc(val, f1);
                if( fclose(f1) != 0 )   
                    printf("ERRO ao fechar o arquivo %s!!!", argv[2]);
            }
            else if(argv[1] == "b") {

            }
            else printf("Erro! Entre com o argumento t se o arquivo for do tipo texto, e b se for do tipo binário.");
            break;

        default: 
            printf("ERRO! :(");
            break;
    }

    
    puts("\n\n");
    //system("PAUSE");
    return 0;
}

//======================================================================================================================================================