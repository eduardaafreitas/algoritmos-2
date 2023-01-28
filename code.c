#include <stdio.h>
#include <stdlib.h>

void imprimeVetor(int *vetor, int tam){
	int i;
	for(i = 0; i < tam; i++){
		printf("%d ", vetor[i]);
	}
	printf("\n");
}

void troca(int *vetor, int i, int j){
	int aux;
	aux = vetor[i];
	vetor[i] = vetor[j];
	vetor[j] = aux;
}

void maxHeapify(int vetor[], int tam, int ini, int *numComparacoes){
	int esq, dir, maior;
	maior = ini;
	esq = ((2*ini) + 1);
	dir = ((2*ini) + 2);
	if(esq < tam && vetor[esq] > vetor[maior]){
		numComparacoes++;
		maior = esq;
	}
	else {
		maior = ini;
	}

	if(dir < tam && vetor[dir] > vetor[maior]){
		numComparacoes++;
		maior = dir;
	}
	if(maior != ini){
		maxHeapify(vetor, tam, maior, numComparacoes);
		troca(vetor, ini, maior);
	}
}

void buildMaxHeapify(int vetor[], int tam, int *numComparacoes){
	int i;
	for(i = (tam/2)-1; i >= 0; i--){
		maxHeapify(vetor, tam, i, numComparacoes);
	}
}

void ordenaHeap(int vetor[], int tam, int *numComparacoes){
	buildMaxHeapify(vetor, tam, numComparacoes);
	int i;
	int meio = tam/2;
	for(i = meio-1; i>= 1; i--){
		troca(vetor, 1, i);
		maxHeapify(vetor, i, 1, numComparacoes);
	}
}

int heapSort(int vetor[], int tam){
	vetor[0] = 99;
	int numComparacoes = 0;
	if(tam <= 0){
		return -1;
	} /*wrapper aqui!*/
	ordenaHeap(vetor, tam, &numComparacoes);
	return numComparacoes;
}



int main(){
    int vetor[11] = {0,1,7,3,4,9,6,2,8,5,10};
    int num;
	printf("-vetor desordenado: ");
	imprimeVetor(vetor, 11);
    num = heapSort(vetor, 11);
	printf("----vetor ordenado: ");
	imprimeVetor(vetor, 11);
	printf("num comp: %d \n", num);

    return 0;
}