#include "ordenacao.h"

#include <string.h>

void getNome(char nome[]){
	//bota teu nome ai
	strncpy(nome, "Camila Carta Campos", MAX_CHAR_NOME);
	nome[MAX_CHAR_NOME-1] = '\0';//adicionada terminação manual para caso de overflow
}

//adiciona teu grr tb
unsigned int getGRR(){
	return 20211764;
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

int buscaBinaria(int vetor[], int tam, int valor, int* numComparacoes){
	*numComparacoes = 99;
	return -1;
}

int insertionSort(int vetor[], int tam){	
	vetor[0] = 99;
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