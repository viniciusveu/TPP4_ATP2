#include "func_ord.h"

void bubbleSort(FILE *f){
	long int i,j;
	int a,b;
	fseek(f,0,SEEK_END);
	long int tam = ftell(f)/sizeof(int);
	long int tam2 = tam;	
	rewind(f);
	for(i=0;i<tam-1;i++){
		rewind(f);
		for(j=0;j<tam2-1;j++){
			fread(&a,sizeof(int),1,f);
			fread(&b,sizeof(int),1,f);
			if(a>b) {
				fseek(f,-2*sizeof(int),SEEK_CUR);
				fwrite(&b,sizeof(int),1,f);
				fwrite(&a,sizeof(int),1,f);
			}
			fseek(f,-sizeof(int),SEEK_CUR);
		}
		tam2--;
	}
	rewind(f);
	
}


void ordenarVetor(int vetor[], int dim){
    int i, j, aux;
    for(j=dim-1; j>=1; j--){
		for(i=0; i<j; i++){
			if(vetor[i]>vetor[i+1]){
				aux=vetor[i];
                vetor[i]=vetor[i+1];
                vetor[i+1]=aux;
            }
        }
    }

    return;
} //ordenarVetor