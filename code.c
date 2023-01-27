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

int* intercala(int* vetor, int ini, int meio, int tam, int *numComparacoes){ /* usado para mergesort */
	if (tam <= ini){
		return vetor;
	}
	int i = ini;
	int j = meio++;
	int k;
	int u[tam];
	for (k = 0; k < tam; ++k)
	{
		(*numComparacoes)++;
		if ((j > tam) || ((i <= meio) && (vetor[i] <= vetor[j]))){
			u[k] = vetor[i];
			i++;
		}
		else{
			u[k] = vetor[j];
			j++;
		}
	}
	vetor = u;
	return vetor;
}

int* ordenaMerge(int *vetor, int ini, int tam, int *numComparacoes){
	if (tam <= ini){
		return vetor;
	} 
	int meio;
	meio = ((tam + ini)/2);
	ordenaMerge(vetor, ini, meio, numComparacoes);
	ordenaMerge(vetor, meio + 1, tam, numComparacoes);
	return intercala(vetor, ini, meio, tam, numComparacoes);
}

int mergeSort(int vetor[], int tam){
	vetor[0] = 99;
	int numComparacoes = 0;
	if (tam <= 0){
		return -1;
	} /* wrapper dnv! */
	ordenaMerge(&vetor, 0, tam, &numComparacoes);
	return numComparacoes;
}


int main(){
    int vetor[11] = {0,1,7,3,4,9,6,2,8,5,10};
    int num;
	printf("-vetor desordenado: ");
	imprimeVetor(vetor, 11);
    num = mergeSort(vetor, 11);
	printf("----vetor ordenado: ");
	imprimeVetor(vetor, 11);
	printf("num comp: %d \n", num);

    return 0;
}