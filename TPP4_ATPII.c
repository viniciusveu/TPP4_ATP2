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

#define PULA puts("\n\n")

FILE *f1, *f2, *ff;
const int tam = 50;

//MAIN======================================================================================================================================================

int main(int argc, char *argv[]) {
    char arq1[tam], arq2[tam], arq3[tam], ch;
    int cont, val;
    switch(argc) {
        case 0:
            printf("Erro nos parâmetros de entrada!"); 
            break;
        case 1: //TPP4
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
            printf("Lista na tela os elementos pertencentes ao arquivo do tipo BINARIO arq1: TPP4 b arq1 \n");
            printf("Lista na tela uma breve descrição das funcionalidades do programa e a sintaxe de seu uso: TPP4 \n");
            break;
        case 2: //TPP4 t arq1
            if(argv[1] == t) {
                if( (f1=fopen(argv[2], "r") ) != NULL) {
                    printf("ERRO na abertura do arquivo %s!!!", nome_arq);
                    exit(1);
                }
                while ( ch = fgetc(f1) != EOF) {
                    if(ch == '\n') PULA;
                    else printf("%c ", ch);
                }
                if( fclose(F1) != 0 )   
                    printf("ERRO ao fechar o arquico %s!!!", nome_arq);
            }
            else if(argv[1] == b) {

            }
            else printf("Erro! Entre com o argumento t se o arquivo for do tipo texto, e b se for do tipo binário.");
            break;
        case 3: //TPP4 t arq1 n
            if(argv[1] == t) {
                if( (f1=fopen(argv[2], "w") ) != NULL) {
                    printf("ERRO na abertura do arquivo %s!!!", argv[2]);
                    exit(1);
                }
                for(cont=1; cont <= argv[3], cont++) {
                    printf("Entre com o %dº valor: \n", cont);
                    scanf("%d", &val);
                    fgetc(f1) = val;
                }
                if( fclose(F1) != 0 )   
                    printf("ERRO ao fechar o arquico %s!!!", argv[2]);
            }
            else if(argv[1] == b) {

            }
            else printf("Erro! Entre com o argumento t se o arquivo for do tipo texto, e b se for do tipo binário.");
            break;
        default: 
            printf("ERRO!");
            break;
    }

    
    puts("\n\n");
    system("PAUSE");
    return 0;
}

//======================================================================================================================================================
