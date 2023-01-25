#include <stdio.h>
#include <stdlib.h>

void troca(int *vetor, int i, int j){
	int aux;
	aux = vetor[i];
	vetor[i] = vetor[j];
	vetor[j] = aux;
}

int buscaSequencial(int vetor[], int tam, int valor, int* numComparacoes){

	if (tam == 0){
		return -1;
	}
	else {
		numComparacoes++;
		if (valor == vetor[tam]){
			return tam;
		}
		else {
			return buscaSequencial(vetor, tam-1, valor, numComparacoes);
		}
	}

}

int* insereOrdenado(int* vetor, int tam, int* numComparacoes){
	int p;
	int i = tam-1;
	p = buscaSequencial(vetor, tam-1, i, numComparacoes);
	while(i > p+1){
		troca(vetor, i, i-1);
		i--;
	}
	return vetor;
}


void imprimeVetor(int *vetor, int tam){
	int i;
	for(i = 0; i < tam; i++){
		printf("%d ", vetor[i]);
	}
	printf("\n");
}


int insertionSort(int vetor[], int tam){	
	vetor[0] = 99;
	int* numComparacoes = 0;
	if(tam == 0){
		return -1;
	}
	else{
		numComparacoes++;
		insertionSort(vetor, tam-1);
		insereOrdenado(vetor, tam, numComparacoes);
		return *numComparacoes;
	}
	return -1;
}

int main(){
    int vetor[10] = {1,7,3,4,9,6,2,8,5,10};
    //int n, x;
	//int i;
    int numComparacoes = 0;
    //int num = 0;
    //scanf("%d", &n);
	//scanf("%d", &x);
    insertionSort(vetor, 10);
    printf("num comp: %d \n", numComparacoes);
	imprimeVetor(vetor, 10);

    return 0;
}