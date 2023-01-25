#include "ordenacao.h"
#include <string.h>


void getNome(char nome[], char nome2[]){
	strncpy(nome, "Camila Carta Campos", MAX_CHAR_NOME);
	strncpy(nome2, "Eduarda de Aguiar Freitas", MAX_CHAR_NOME);
	nome[MAX_CHAR_NOME-1] = '\0'; 					//adicionada terminação manual para caso de overflow
	nome2[MAX_CHAR_NOME-1] = '\0';
}

unsigned int getGRR1(){
	return 20211764;
}
unsigned int getGRR2(){
	return 20211799;
}

void troca(int *vetor, int i, int j){
	int aux;
	aux = vetor[i];
	vetor[i] = vetor[j];
	vetor[j] = aux;
}

int* insereOrdenado(int *vetor, int tam, int valor, int* numComparacoes){
	int p, i;
	p = buscaSequencial(vetor, tam-1, valor, numComparacoes);
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

int buscaBinaria(int vetor[], int tam, int valor, int* numComparacoes){			//colocar alg ordenação
	int meio;
	meio = tam/2;
	if (tam == 0){
		return -1;
	}
	else {
		numComparacoes++;
		if (valor == vetor[meio]){
			return meio;
		}
		else if (valor < vetor[meio]){
			numComparacoes++;
			meio--;
			buscaBinaria(vetor, meio, valor, numComparacoes);
		}
		else if (valor > vetor[meio]){
			numComparacoes++;
			meio++;
			buscaBinaria(vetor, meio, valor, numComparacoes);
		}
	}
	return -1;
}


int insertionSort(int vetor[], int tam){	
	vetor[0] = 99;
	if(tam == 0){
		return -1
	}
	else{
		numComparacoes++;
		insertionSort(vetor, tam-1, valor, numComparacoes);
		insereOrdenado(&vetor, tam, valor, numComparacoes);
		imprimeVetor(vetor, tam);
		return numComparacoes;
	}
	return -1;
}


int selectionSort(int vetor[], int tam){
	vetor[0] = 99;
	return -1;
}

int mergeSort(int vetor[], int tam){
	vetor[0] = 99;
	return -1;
}

int quickSort(int vetor[], int tam){
	vetor[0] = 99;
	return -1;
}

int heapSort(int vetor[], int tam){
	vetor[0] = 99;
	return -1;
}