#ifndef _FUNCTIONS_H
#define _FUNCTIONS_H


void comoUsar(void);
void ordenarVetor(int vetor[], int dim);
void checkFile(FILE *f1);
void printBinArc(FILE *f1);
void arcRandom(FILE *f);
void copiarArquivoBIN(FILE *f1, FILE *f2);
void copiarArquivoTXT(FILE *f1, FILE *f2);
void calculaUniao(FILE *f1, FILE *f2, FILE *ff);
void diferenzaBIN(FILE *f1, FILE *f2, FILE *f3);
void diferenzaTXT(FILE *f1, FILE *f2, FILE *f3);
void uniaoBIN(FILE *f1, FILE *f2, FILE *f3, char *nomeArq1, char *nomeArq2, char *nomeArq3);
void encontraUniao(FILE *f1, FILE *f2, FILE *f3);

#endif
