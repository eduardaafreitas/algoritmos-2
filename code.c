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