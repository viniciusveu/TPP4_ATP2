#ifndef _FUNCTIONS_H
#define _FUNCTIONS_H

//texto = t

void comoUsar(void);
void ordenarVetor(int vetor[], int dim);
void checkFile(FILE *f1);
void printBinArc(FILE *f1);
void arcRandom(FILE *f);
void copiarArquivoBIN(FILE *f1, FILE *f2);
void copiarArquivoTXT(FILE *f1, FILE *f2);
void diferenzaBIN(FILE *f1, FILE *f2, FILE *f3);
void diferenzaTXT(FILE *f1, FILE *f2, FILE *f3);

#endif
