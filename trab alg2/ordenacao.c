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
//---------------------------------------------------------------------------------------------------------
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

//---------------------------------------------------------------------------------------------------------
int buscaSequencial(int vetor[], int tam, int valor, int* numComparacoes){
	if (tam == 0){
		return -1;
	}
	else {
		*numComparacoes = *numComparacoes + 1;
		if (valor == vetor[tam]){
			return tam;
		}
		else {
			return buscaSequencial(vetor, tam-1, valor, numComparacoes);
		}
	}

}

// -----------------------------------------------------------------------------------------------

int buscaBinIniFim(int *vetor, int valor, int ini, int fim, int* numComp){
	if (fim < ini){
		return -1;
	}
	int meio = (ini + fim) / 2;
	*numComp = *numComp + 1; /*fazendo antes da comparação p garantir que conta*/
	if (valor == vetor[meio]){
		return meio;
	}
	*numComp = *numComp + 1;
	if (valor < vetor[meio]){
		return buscaBinIniFim(vetor, valor, ini, meio-1, numComp);
	}
	return buscaBinIniFim(vetor, valor, meio+1, fim, numComp);
}

int buscaBinaria(int vetor[], int tam, int valor, int* numComparacoes){			//colocar alg ordenação
	/* vai ser wrapper */
	if (tam <=0){
		return -1;
	}
	return buscaBinIniFim(vetor, valor, 0, tam, numComparacoes);
}

//---------------------------------------------------------------------------------------------------------
void ordenaInsertion(int vetor[], int tam, int* numComparacoes){
    if (tam == 0){
		return;
	}
    ordenaInsertion(vetor, tam-1, numComparacoes);
 
    int ultimo = vetor[tam-1];
    int j = tam-2;
    while (j >= 0 && vetor[j] > ultimo){
        vetor[j+1] = vetor[j];
		(*numComparacoes)++;
        j--;
    }
    vetor[j+1] = ultimo;
}

int insertionSort(int vetor[], int tam){	
	int numComparacoes = 0;
	if(tam == 0){
		return -1;
	}
	else{
		ordenaInsertion(vetor, tam-1, &numComparacoes);	//wrapper
		return numComparacoes;
	}
	return -1;
}
//---------------------------------------------------------------------------------------------------------
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
	if (tam < 0){
		return -1;
	}
	else { /* isso aqui é um wrapper; tudo eh feito no selecionaEOrdena */
		vetor[0] = 99;
		int numComparacoes = 0; 
		int num;
		num = selecionaEOrdena(vetor, 0, tam, &numComparacoes);
		return num;
	}
	return -1;
}
//---------------------------------------------------------------------------------------------------------
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
//---------------------------------------------------------------------------------------------------------
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
//---------------------------------------------------------------------------------------------------------
int particiona(int vetor[], int tam, int pivo, int *numComparacoes){
	int meio;
	int i, ini;
	ini = 1; // começo do vetor
	meio = ini - 1;
	for(i = ini; i < tam; i++){
		if(vetor[i] <= pivo){
			meio++;
			troca(vetor, meio, i);
			(*numComparacoes)++;
		}
	}
	return meio;
}

void ordenaQuick(int vetor[], int ini, int tam, int *numComparacoes){
	if (ini >= tam){
		return;
	}
	int meio = particiona(vetor, tam+1, vetor[tam], numComparacoes);
	ordenaQuick(vetor, ini, meio-1, numComparacoes);
	ordenaQuick(vetor, meio+1, tam, numComparacoes);
}

int quickSort(int vetor[], int tam){
	vetor[0] = 99;
	int numComparacoes = 0;
	if(tam <= 0){
		return -1;
	} /*wrapper aqui!*/
	ordenaQuick(vetor, 1, tam, &numComparacoes);
	return numComparacoes;
}
//---------------------------------------------------------------------------------------------------------
void maxHeapify(int vetor[], int tam, int ini, int *numComparacoes){
	int esq, dir, maior;
	maior = ini;
	esq = ((2*ini) + 1);
	dir = ((2*ini) + 2);
	if(esq < tam && vetor[esq] > vetor[maior]){
		(*numComparacoes)++;
		maior = esq;
	}
	else {
		maior = ini;
	}

	if(dir < tam && vetor[dir] > vetor[maior]){
		(*numComparacoes)++;
		maior = dir;
	}
	if(maior != ini){
		troca(vetor, ini, maior);
		maxHeapify(vetor, tam, maior, numComparacoes);
	}
}

void buildMaxHeapify(int vetor[], int tam, int *numComparacoes){
	int i;
	int meio = tam/2;
	for(i = meio; i >= 0; i--){
		maxHeapify(vetor, tam, i, numComparacoes);
	}
}

void ordenaHeap(int vetor[], int tam, int *numComparacoes){
	buildMaxHeapify(vetor, tam, numComparacoes);
	int i;
	for(i = tam-1; i>= 1; i--){
		troca(vetor, 0, i);
		maxHeapify(vetor, i, 0, numComparacoes);
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