#include <stdio.h>
#include <stdlib.h>

void troca(int *vetor, int i, int j){
	int aux;
	aux = vetor[i];
	vetor[i] = vetor[j];
	vetor[j] = aux;
}

void imprimeVetor(int *vetor, int tam){
	int i;
	for(i = 0; i < tam; i++){
		printf("%d ", vetor[i]);
	}
	printf("\n");
}

void ordenaInsertion(int vetor[], int tam, int* numComparacoes){
    if (tam == 0){
		return;
	}
    ordenaInsertion(vetor, tam-1, numComparacoes);
 
    int ultimo = vetor[tam-1];
    int j = tam-2;
    while (j >= 0 && vetor[j] > ultimo){
        vetor[j+1] = vetor[j];
		(*numComparacoes)++;
        j--;
    }
    vetor[j+1] = ultimo;
}

int insertionSort(int vetor[], int tam){	
	int numComparacoes = 0;
	if(tam == 0){
		return -1;
	}
	else{
		ordenaInsertion(vetor, tam-1, &numComparacoes);	//wrapper
		return numComparacoes;
	}
	return -1;
}



int main(){
    int vetor[10] = {1,7,3,4,9,6,2,8,5,10};
    int num;
	printf("-vetor desordenado: ");
	imprimeVetor(vetor, 10);
    num = insertionSort(vetor, 10);
	printf("----vetor ordenado: ");
	imprimeVetor(vetor, 10);
	printf("num comp: %d \n", num);

    return 0;
}