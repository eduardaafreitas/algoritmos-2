#include "ordenacao.h"
#include <string.h>


void getNome(char nome[]){
	//bota teu nome ai
	strncpy(nome, "Camila Carta Campos", MAX_CHAR_NOME);
	strncpy(nome, "Eduarda de Aguiar Freitas", MAX_CHAR_NOME);
	nome[MAX_CHAR_NOME-1] = '\0'; 					//adicionada terminação manual para caso de overflow
}

//adiciona teu grr tb
unsigned int getGRR1(){
	return 20211764;
}
/*unsigned int getGRR2(){
	return 20211799;
}*/

int troca(int vetor[], int i, int j){
	int aux;
	aux = vetor[i];
	vetor[i] = vetor[j];
	vetor[j] = aux;
	return 0;
}

int insere(int vetor[], int tam, int valor){
	int i;
	for (i = tam; i > 0 && vetor[i-1] > valor; i--){
		vetor[i] = vetor[i-1];
	}
	vetor[i] = valor;
	return 0;
}

int insereOrdenado(int vetor[], int tam, int valor){
	int i = valor;
	
	while(i > p+1){
		troca(vetor, i, i-1);
		i--;
	}

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
			return buscaBinaria(vetor, meio-1, valor, numComparacoes);
		}
		else if (valor > vetor[meio]){
			numComparacoes++;
			return buscaBinaria(vetor, meio+1, valor, numComparacoes);
		}
	}
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