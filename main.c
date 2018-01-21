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
#include "func_ord.c"

#define ESPACO '\0'
#define PULA puts("\n")
#define TAM 1000

FILE *f1, *f2, *ff;

//MAIN======================================================================================================================================================

int main(int argc, char *argv[]) {
    char ch, t='t', b='b';
    int *aux=NULL, i, n, x, num, n1, n2, vetor[TAM];

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

                printf("Os números do arquivo texto são os sequintes: \n");
                while( (ch = fgetc(f1)) != EOF)
                        printf("%c", ch);
                PULA;
                fclose(f1);
                //if( fclose(f1) != 0 )
                //    printf("ERRO ao fechar o arquivo %s!!!\n", argv[2]);
            }
            else if(*argv[1] == b) {
                if( (f1=fopen(argv[2], "rb") ) == NULL) {
                    printf("ERRO na abertura do arquivo %s!!! O arquivo está criado? \n", argv[2]);
                    exit(1);
                }
                printf("Os números do arquivo binário são os sequintes: \n");
                while(1) {
                    fread(&num, sizeof(int), 1, f1);
                    if(feof(f1)) break;
                    printf("%d ", num);
                }
                PULA;
                fclose(f1);
            }
            else printf("Erro! Entre com o argumento t se o arquivo for do tipo texto, e b se for do tipo binário.\n");
        break;

        case 4: //TPP4 t arq1 n
            if(*argv[1] == t) {
                if( (f1=fopen(argv[2], "w") ) == NULL) {
                    printf("ERRO na abertura do arquivo %s!!!\n", argv[2]);
                    exit(1);
                }
                //srand((unsigned) time(&tim));

                printf("Entre com os valores do arquivo: [Aperte ENTER após entrar com cada valor]\n");
                n = atoi(argv[3]);
                for(i=0; i<n; i++) {
                    scanf("%d", &num);
                    vetor[i] = num;
                }
                ordenarVetor(vetor, n);
                for(i=0; i<n; i++)
                    fprintf(f1, "%d ", vetor[i]);

                printf("Arquivo criado e ordenado com sucesso! :D");
                fclose(f1);
            }
            else if(*argv[1] == b) {
                if( (f1=fopen(argv[2], "w+b") ) == NULL) {
                    printf("ERRO na abertura do arquivo %s!!! O arquivo está criado? \n", argv[2]);
                    exit(1);
                }
                printf("Entre com os valores do arquivo: [Aperte ENTER após entrar com cada valor]\n");
                n = atoi(argv[3]);
                for(i=0; i<n; i++) {
                    scanf("%d", &num);
                    fwrite(&num, sizeof(int), 1, f1);
                }
                rewind(f1);
                bubbleSort(f1);
                printf("Arquivo binário criado e ordenado com sucesso! :D");
                fclose(f1);
            }
            else printf("Erro! Entre com o argumento t se o arquivo for do tipo texto, e b se for do tipo binário.\n");
        break;

        case 6: //Casos de 1 a 3
         //Cria o arquivo TEXTO/BINARIO com nome arq3 que é o resultado da intersecção dos elementos dos arquivos BINARIOS arq1 e arq2
                if(*argv[1] == t) {
                    if(*argv[2] == '1') {
                        if( (f1=fopen(argv[3], "r") ) == NULL) {
                            printf("ERRO na abertura do arquivo: %s!!! O arquivo está criado? \n", argv[3]);
                            exit(1);
                        }
                        if( (f2=fopen(argv[4], "r") ) == NULL) {
                            printf("ERRO na abertura do arquivo: %s!!! O arquivo está criado? \n", argv[4]);
                            exit(1);
                        }
                        if( (ff=fopen(argv[5], "w") ) == NULL) {
                            printf("ERRO na abertura do arquivo: %s!!! O arquivo está criado? \n", argv[5]);
                            exit(1);
                        }

                        printf("Calcular a intersecção entre dois arquivos tipo texto. \n");
                        aux=NULL;
                        while(1) {
                            fscanf(f1, "%d", &n1);
                            if(feof(f1)) break;
                            if(*aux != n1) {
                                while(1) {
                                    fscanf(f2, "%d", &n2);
                                    if(feof(f2)) break;
                                    if(n1 == n2) {
                                        fprintf(ff, "%d ", n1);
                                        break;
                                    }
                                }
                            }
                            *aux = n1;
                            rewind(f2);
                        }
                        printf("O arquivo %s com a intersecção foi criado!\n", argv[5]);

                        fclose(f1);
                        fclose(f2);
                        fclose(ff);
                    }
                    else if(*argv[2] == '2') { //Cria o arquivo TEXTO com nome arq3 que é resultado da união dos elementos dos arquivos TEXTOS arq1 e arq2

                        if( (f1=fopen(argv[3], "r") ) == NULL) {
                            printf("ERRO na abertura do arquivo: %s!!! O arquivo está criado? \n", argv[3]);
                            exit(1);
                        }
                        if( (f2=fopen(argv[4], "r") ) == NULL) {
                            printf("ERRO na abertura do arquivo: %s!!! O arquivo está criado? \n", argv[4]);
                            exit(1);
                        }
                        if( (ff=fopen(argv[5], "w") ) == NULL) {
                            printf("ERRO na abertura do arquivo: %s!!! O arquivo está criado? \n", argv[5]);
                            exit(1);
                        }  

                        printf("Calcular a união de %s com %s.\n", argv[3], argv[4]);
                        
                        encontraUniao(f1, f2, ff);
                        while(1) {
                            fscanf(ff, "%d %d", &n1, &n2);
                            if( n1==n2 ) 
                        }
                       
                        printf("Arquivo com a união foi criado com sucesso! :D\n");

                        fclose(f1);
                        fclose(f2);
                        fclose(ff);
                    }
                    else if(*argv[2] == '3') { //Cria o arquivo TEXTO com nome arq3 que é resultado da diferença dos elementos do arquivo TEXTO arq1, menos os elementos do arquivo TEXTO arq2

                        if( (f1=fopen(argv[3], "r") ) == NULL) {
                            printf("ERRO na abertura do arquivo: %s!!! O arquivo está criado? \n", argv[3]);
                            exit(1);
                        }
                        if( (f2=fopen(argv[4], "r") ) == NULL) {
                            printf("ERRO na abertura do arquivo: %s!!! O arquivo está criado? \n", argv[4]);
                            exit(1);
                        }
                        if( (ff=fopen(argv[5], "w") ) == NULL) {
                            printf("ERRO na abertura do arquivo: %s!!! O arquivo está criado? \n", argv[5]);
                            exit(1);
                        }  
                        


                        fclose(f1);
                        fclose(f2);
                        fclose(ff);

                    }
                    else printf("Entre com a opção 1, 2 ou 3!\n");
                }
                //Caso Binário: =======================================================================
                else if(*argv[1] == b) {
                    if(*argv[2] == '1') {
                        if( (f1=fopen(argv[3], "rb") ) == NULL) {
                            printf("ERRO na abertura do arquivo: %s!!! O arquivo está criado? \n", argv[3]);
                            exit(1);
                        }
                        if( (f2=fopen(argv[4], "rb") ) == NULL) {
                            printf("ERRO na abertura do arquivo: %s!!! O arquivo está criado? \n", argv[4]);
                            exit(1);
                        }
                        if( (ff=fopen(argv[5], "wb") ) == NULL) {
                            printf("ERRO na abertura do arquivo: %s!!! O arquivo está criado? \n", argv[5]);
                            exit(1);
                        }

                        printf("Calcular a intersecção entre dois arquivos tipo binário. \n");
                        aux=NULL;
                        while(1) {
                            fread(&n1, sizeof(int), 1, f1);
                            if(feof(f1)) break;
                            if(*aux != n1) {
                                while(1) {
                                    fread(&n2, sizeof(int), 1, f2);
                                    if(feof(f2)) break;
                                    if(n1 == n2) {
                                        fwrite(&n1, sizeof(int), 1, ff);
                                        break;
                                    }
                                }
                            }
                            *aux = n1;
                            rewind(f2);
                        }
                        printf("O arquivo %s com a intersecção foi criado!\n", argv[5]);

                        fclose(f1);
                        fclose(f2);
                        fclose(ff);
                    }
                    else if(*argv[2] == '2') { //Cria o arquivo TEXTO com nome arq3 que é resultado da união dos elementos dos arquivos TEXTOS arq1 e arq2
                        
                        
                        uniaoBIN(f1, f2, ff, argv[3], argv[4], argv[5]);

                    }

                    else if(*argv[2] == '3') { //Cria o arquivo TEXTO com nome arq3 que é resultado da diferença dos elementos do arquivo TEXTO arq1, menos os elementos do arquivo TEXTO arq2

                    }
                    else printf("Entre com a opção 1, 2 ou 3!\n");
                }

                else printf("Erro! Entre com o argumento t se o arquivo for do tipo texto, e b se for do tipo binário.\n");
                break;
        default:
            printf("ERRO! :(\n");
        break;
    }


    puts("\n\n");
    //system("PAUSE");
    return 0;
}

//======================================================================================================================================================
