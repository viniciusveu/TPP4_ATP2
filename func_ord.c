#include "func_ord.h"

void bubbleSort(FILE *f){
	long double i,j;
	double a,b;
	fseek(f,0,SEEK_END);
	long double tam = ftell(f)/sizeof(double);
	long double tam2 = tam;	
	rewind(f);
	for(i=0;i<tam-1;i++){
		rewind(f);
		for(j=0;j<tam2-1;j++){
			fread(&a,sizeof(double),1,f);
			fread(&b,sizeof(double),1,f);
			if(a>b) {
				fseek(f,-2*sizeof(double),SEEK_CUR);
				fwrite(&b,sizeof(double),1,f);
				fwrite(&a,sizeof(double),1,f);
			}
			fseek(f,-sizeof(double),SEEK_CUR);
		}
		tam2--;
	}
	rewind(f);
	
}