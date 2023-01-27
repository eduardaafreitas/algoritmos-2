#include <stdio.h>
#include <stdlib.h>

void imprimeVetor(int *vetor, int tam){
	int i;
	for(i = 0; i < tam; i++){
		printf("%d ", vetor[i]);
	}
	printf("\n");
}

void intercala(int* vetor, int ini, int meio, int tam, int *numComparacoes){ /* usado para mergesort */
	if (tam <= ini){
		return;
	}
	int i = ini;
	int j = meio+1;
	int k = 0;
	int fimU = tam - ini+1;
	int u[fimU];
	for (k = 0; k < fimU; k++){
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
	for (k = 0; k < tam - ini + 1; k++){
        vetor[ini + k] = u[k];
	}
}

void ordenaMerge(int *vetor, int ini, int tam, int *numComparacoes){
	if (ini >= tam){
		return;
	} 
	int meio;
	meio = ((tam + ini)/2);
	ordenaMerge(vetor, ini, meio, numComparacoes);
	ordenaMerge(vetor, meio + 1, tam, numComparacoes);
	intercala(vetor, ini, meio, tam, numComparacoes);
}

int mergeSort(int vetor[], int tam){
	vetor[0] = 99;
	int numComparacoes = 0;
	if (tam <= 0){
		return -1;
	} /* wrapper dnv! */
	ordenaMerge(vetor, 1, tam-1, &numComparacoes);
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