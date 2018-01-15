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

#define ESPACO '\0'
#define PULA puts("\n")
#define TAM 50

FILE *f1, *f2, *ff;

//MAIN======================================================================================================================================================

int main(int argc, char *argv[]) {
    char ch, t='t', b='b';
    int cont, val, i, j, n, n1, n2, vetor[TAM];
    
    time_t tim;
    setlocale(LC_ALL, "Portuguese");
    switch(argc) {
        
        case 1: //TPP4
            comoUsar();
        break;
        
        case 3: //TPP4 t arq1
            if(*argv[1] == t) {
                if( (f1=fopen(argv[2], "r") ) == NULL) {
                    printf("ERRO na abertura do arquivo %s!!! O arquivo está criado? \n", argv[2]);
                    exit(1);
                }
                
                printf("Os números do arquivo são os sequintes: \n");
                while( (ch = fgetc(f1)) != EOF)
                        printf("%c", ch);
                
                fclose(f1);
                //if( fclose(f1) != 0 )   
                //    printf("ERRO ao fechar o arquivo %s!!!\n", argv[2]);
            }
            else if(*argv[1] == b) {
                if( (f1=fopen(argv[2], "rb") ) == NULL) {
                    printf("ERRO na abertura do arquivo %s!!! O arquivo está criado? \n", argv[2]);
                    exit(1);
                }
            }
            else printf("Erro! Entre com o argumento t se o arquivo for do tipo texto, e b se for do tipo binário.\n");
        break;
        
        case 4: //TPP4 t arq1 n
            if(*argv[1] == t) {
                if( (f1=fopen(argv[2], "w+") ) == NULL) {
                    printf("ERRO na abertura do arquivo %s!!!\n", argv[2]);
                    exit(1);
                }
                //srand((unsigned) time(&tim));
                
                printf("Entre com os valores do arquivo: \n");
                for(n = atoi(argv[3]); 0 < n; n--) {
                    scanf("%d", &i);
                    fflush(stdin);
                    fprintf(f1, "%d ", i);
                }
                n = atoi(argv[3]);
                for(i=0; i<n; i++) {
                    fscanf(f1, "%d ", &n1);
                    fflush(stdin);                   
                    vetor[i] = n1;
                }
                ordenarVetor(vetor, n);
                rewind(f1);
                for(i=0; i<n; i++) {
                    fprintf(f1, "%d", *(vetor+i));
                }

                printf("Arquivo criado com sucesso!!!");
                fclose(f1);
            }
            else if(*argv[1] == b) {
                if( (f1=fopen(argv[2], "rb") ) == NULL) {
                    printf("ERRO na abertura do arquivo %s!!! O arquivo está criado? \n", argv[2]);
                    exit(1);
                }
            }
            else printf("Erro! Entre com o argumento t se o arquivo for do tipo texto, e b se for do tipo binário.\n");
        break;

        case 6: //Casos de 1 a 3
            switch(*argv[2]) {
                case 1: //Cria o arquivo TEXTO/BINARIO com nome arq3 que é o resultado da intersecção dos elementos dos arquivos BINARIOS arq1 e arq2
                    if(*argv[1] == t) {
                        if(*argv[2] == 1) {
                            if( (f1=fopen(argv[3], "r") ) == NULL) {
                                printf("ERRO na abertura do arquivo %s!!! O arquivo está criado? \n", argv[3]);
                                exit(1);
                            }
                            if( (f2=fopen(argv[4], "r") ) == NULL) {
                                printf("ERRO na abertura do arquivo %s!!! O arquivo está criado? \n", argv[4]);
                                exit(1);
                            }
                            if( (ff=fopen(argv[5], "w+") ) == NULL) {
                                printf("ERRO na abertura do arquivo %s!!! O arquivo está criado? \n", argv[5]);
                                exit(1);
                            }

                            for(i=0; i != EOF; i++) {
                                n1 = fgetc(f1);
                                for(j=0; j != EOF; j++){
                                    if(n1 == fgetc(f2)) fputc(n1, ff);
                                }
                            }

                            fclose(f1);
                            fclose(f2);
                            fclose(ff);
                        }
                        if(*argv[2] == 2) {

                        }
                        if(*argv[2] == 3) {

                        }
                        else printf("Entre com a opção 1, 2 ou 3!\n");
                    }
                    else if(*argv[1] == b) {

                    }
                    else printf("Erro! Entre com o argumento t se o arquivo for do tipo texto, e b se for do tipo binário.\n");
                break;
                
                case 2: //Cria o arquivo TEXTO com nome arq3 que é resultado da união dos elementos dos arquivos TEXTOS arq1 e arq2

                break; 

                case 3: //Cria o arquivo TEXTO com nome arq3 que é resultado da diferença dos elementos do arquivo TEXTO arq1, menos os elementos do arquivo TEXTO arq2

                break;

                default:
                    printf("Entre com as opções 1, 2 ou 3! '-' \n");
                break;
            } //Swith
        default: 
            printf("ERRO! :(\n");
        break;
    }

    
    puts("\n\n");
    //system("PAUSE");
    return 0;
}

//======================================================================================================================================================
