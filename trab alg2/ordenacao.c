#include "ordenacao.h"
#include <string.h>
#include <stdio.h>
#include "libOrd.h"

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

int minimoVetor(int vetor[], int a, int b){ /* usando no selectionsort */
	if (a == b){
		return a;
	}
	int m = minimoVetor(vetor, a, b-1);
	if (vetor[b] < vetor[m]){
		m = b;
	}
	numComparacoes++;
	return m;
}

//FALTA FAZER ESSA MERDA DE INSERTION SORT FUNCIONAR (e tb testar todos os outros)

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
		return -1;
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

int selecionaEOrdena(int vetor[], int prim, int tam){
	if (prim >= tam){
		return numComparacoes;
	}
	troca(vetor, prim, minimoVetor(vetor, prim, tam));
	return selecionaEOrdena(vetor, prim+1, tam);
}

int selectionSort(int vetor[], int tam){
	vetor[0] = 99;
	numComparacoes = 0; /* limpa o numero de comparações feito até agora, pode apagar se achar q nn precisa */
	if (tam < 0){
		return -1;
	}
	else { /* isso aqui é um wrapper; tudo eh feito no selecionaEOrdena */
		numComparacoes = selecionaEOrdena(vetor, 0, tam);
		return numComparacoes;
	}
	return -1;
}

int* intercala(int* vetor, int ini, int meio, int tam){ /* usado para mergesort */
	if (tam <= ini){
		return vetor;
	}
	int i = ini;
	int j = meio++;
	int k;
	int u[tam];
	for (k = 0; k < tam; ++k)
	{
		numComparacoes++;
		if (j > b) || (i <= meio && vetor[i] <= vetor[j]){
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

void ordenaMerge(int vetor[], int ini, int tam){
	if (tam <= ini){
		return *vetor;
	}
	int meio;
	meio = ((tam + ini) div 2);
	ordenaMerge(vetor, ini, meio);
	ordenaMerge(vetor, meio + 1, tam);
	return intercala(vetor, ini, meio, tam);
}

int mergeSort(int vetor[], int tam){
	vetor[0] = 99;
	if (tam <= 0){
		return -1;
	} /* wrapper dnv! */
	ordenaMerge(vetor, 0, tam);
	return numComparacoes;
}

int particiona(int vetor[], int tam, int pivo){
	int meio;
	int i, ini;
	ini = 1; // começo do vetor
	meio = ini - 1;
	for(i = ini; i < tam; i++){
		if(vetor[i] <= pivo){
			meio++;
			troca(&vetor, meio, i);
			numComparacoes++;
		}
	}
	return meio;
}

void ordenaQuick(int vetor[], int ini, int tam){
	if (tam <= ini){
		return *vetor;
	}
	int meio
	meio = particiona(vetor, ini, tam, vetor[tam]);
	ordenaQuick(vetor, ini, meio-1);
	ordenaQuick(vetor, meio+1, tam);
}

int quickSort(int vetor[], int tam){
	vetor[0] = 99;
	if(tam <= 0){
		return -1
	} /*wrapper aqui!*/
	ordenaQuick(vetor, 0, tam);
	return numComparacoes;
}

void maxHeapify(int vetor[], int tam, int ini){
	int esq, dir, maior;
	maior = ini;
	esq = ((2*ini) + 1);
	dir = ((2*ini) + 2);
	if(esq < dir && vetor[esq] > vetor[maior]){
		numComparacoes++;
		maior = esq;
	}
	if(dir < tam && vetor[dir] > vetor[maior]){
		numComparacoes++;
		maior = dir;
	}
	if(maior != ini){
		troca(vetor, ini, maior);
		maxHeapify(vetor, tam, maior);
	}
}

void buildMaxHeapify(int vetor[], int tam){
	int i;
	for(i = (tam/2)-1; i >= 1; i--){
		maxHeapify(vetor, tam, i);
	}
}

void ordenaHeap(int vetor[], int tam){
	buildMaxHeapify(vetor, tam);
	int i;
	for(i = n-1; i>= 1; i--){
		troca(vetor, 1, i);
		maxHeapify(vetor, i, 1);
	}
}

int heapSort(int vetor[], int tam){
	vetor[0] = 99;
	if(tam <= 0){
		return -1
	} /*wrapper aqui!*/
	ordenaHeap(vetor, tam);
	return numComparacoes;
}