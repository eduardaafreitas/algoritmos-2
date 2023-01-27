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

int minimoVetor(int vetor[], int a, int b, int *numComparacoes){ /* usando no selectionsort */
	if (a == b){
		return a;
	}
	int m = minimoVetor(vetor, a, b-1, numComparacoes);
	if (vetor[b] < vetor[m]){
		m = b;
	}
	(*numComparacoes)++;
	return m;
}

int selecionaEOrdena(int vetor[], int prim, int tam, int* numComparacoes){
	if (prim >= tam){
		return *numComparacoes;
	}
	int min = minimoVetor(vetor, prim, tam, numComparacoes);
	troca(vetor, prim, min);
	return selecionaEOrdena(vetor, prim+1, tam, numComparacoes);
}

int selectionSort(int vetor[], int tam){
	vetor[0] = 99;
	int num = 0;
	int numComparacoes = 0; /* limpa o numero de comparações feito até agora, pode apagar se achar q nn precisa */
	if (tam < 0){
		return -1;
	}
	else { /* isso aqui é um wrapper; tudo eh feito no selecionaEOrdena */
		num = selecionaEOrdena(vetor, 0, tam, &numComparacoes);
		return numComparacoes;
	}
	return -1;
}


int main(){
    int vetor[11] = {0,1,7,3,4,9,6,2,8,5,10};
    int num;
	printf("-vetor desordenado: ");
	imprimeVetor(vetor, 11);
    num = selectionSort(vetor, 11);
	printf("----vetor ordenado: ");
	imprimeVetor(vetor, 11);
	printf("num comp: %d \n", num);

    return 0;
}