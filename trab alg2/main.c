#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "ordenacao.h"
#include "libOrd.h"

#define TAM_VETOR1 10000 /* tamanho do vetor */
#define TAM_VETOR2 50000 /* tamanho do vetor */
#define TAM_VETOR3 100000 /* tamanho do vetor */
#define MAX_VALOR 32768 /* 2^15; valor max q um numero pode assumir */

int* vetorRand(int* vetor, int tamAtual){
	int i;
	for (i = 0; i < tamAtual; i++){
		vetor[i] = rand() % MAX_VALOR;
	}
	return vetor;
}

void testaInsertion(int* vetor){

	int tamAtual = TAM_VETOR1; /* VETOR DE 10K */
	unsigned int numComp;

	printf("Criando vetor de tamanho %d para o Insertion Sort.\n", tamAtual);
	vetor = vetorRand(vetor, tamAtual);
	clock_t start, end;//variáveis do tipo clock_t
    double total;
	start = clock();//start recebe o "ciclo" corrente
	numComp = insertionSort(vetor, tamAtual);
	end = clock();//end recebe o "ciclo" corrente
	//o tempo total é a diferença dividia pelos ciclos por segundo
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Tempo total: %f   |   Número de comparações: %d \n\n", total, numComp);

/* ================================================================================ */

	tamAtual = TAM_VETOR2; /* VETOR DE 50K */

	printf("Criando vetor de tamanho %d para o Insertion Sort.\n", tamAtual);
	vetor = vetorRand(vetor, tamAtual);
	start = clock();//start recebe o "ciclo" corrente
	numComp = insertionSort(vetor, tamAtual);
	end = clock();//end recebe o "ciclo" corrente
	//o tempo total é a diferença dividia pelos ciclos por segundo
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Tempo total: %f   |   Número de comparações: %d \n\n", total, numComp);

/* ================================================================================ */

	tamAtual = TAM_VETOR3; /* VETOR DE 100K */

	printf("Criando vetor de tamanho %d para o Insertion Sort.\n", tamAtual);
	vetor = vetorRand(vetor, tamAtual);
	start = clock();//start recebe o "ciclo" corrente
	numComp = insertionSort(vetor, tamAtual);
	end = clock();//end recebe o "ciclo" corrente
	//o tempo total é a diferença dividia pelos ciclos por segundo
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Tempo total: %f   |   Número de comparações: %d \n\n", total, numComp);

	return;
}

void testaSelection(int* vetor){

	int tamAtual = TAM_VETOR1; /* VETOR DE 10K */
	unsigned int numComp;

	printf("Criando vetor de tamanho %d para o Selection Sort.\n", tamAtual);
	vetor = vetorRand(vetor, tamAtual);
	clock_t start, end;//variáveis do tipo clock_t
    double total;
	start = clock();//start recebe o "ciclo" corrente
	numComp = selectionSort(vetor, tamAtual);
	end = clock();//end recebe o "ciclo" corrente
	//o tempo total é a diferença dividia pelos ciclos por segundo
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Tempo total: %f   |   Número de comparações: %d \n\n", total, numComp);

/* ================================================================================ */

	tamAtual = TAM_VETOR2; /* VETOR DE 50K */

	printf("Criando vetor de tamanho %d para o Selection Sort.\n", tamAtual);
	vetor = vetorRand(vetor, tamAtual);
	start = clock();//start recebe o "ciclo" corrente
	numComp = selectionSort(vetor, tamAtual);
	end = clock();//end recebe o "ciclo" corrente
	//o tempo total é a diferença dividia pelos ciclos por segundo
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Tempo total: %f   |   Número de comparações: %d \n\n", total, numComp);

/* ================================================================================ */

	tamAtual = TAM_VETOR3; /* VETOR DE 100K */

	printf("Criando vetor de tamanho %d para o Selection Sort.\n", tamAtual);
	vetor = vetorRand(vetor, tamAtual);
	start = clock();//start recebe o "ciclo" corrente
	numComp = selectionSort(vetor, tamAtual);
	end = clock();//end recebe o "ciclo" corrente
	//o tempo total é a diferença dividia pelos ciclos por segundo
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Tempo total: %f   |   Número de comparações: %d \n\n", total, numComp);

	return;
}

void testaMerge(int* vetor){

	int tamAtual = TAM_VETOR1; /* VETOR DE 10K */
	unsigned int numComp;

	printf("Criando vetor de tamanho %d para o Merge Sort.\n", tamAtual);
	vetor = vetorRand(vetor, tamAtual);
	clock_t start, end;//variáveis do tipo clock_t
    double total;
	start = clock();//start recebe o "ciclo" corrente
	numComp = mergeSort(vetor, tamAtual);
	end = clock();//end recebe o "ciclo" corrente
	//o tempo total é a diferença dividia pelos ciclos por segundo
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Tempo total: %f   |   Número de comparações: %d \n\n", total, numComp);

/* ================================================================================ */

	tamAtual = TAM_VETOR2; /* VETOR DE 50K */

	printf("Criando vetor de tamanho %d para o Merge Sort.\n", tamAtual);
	vetor = vetorRand(vetor, tamAtual);
	start = clock();//start recebe o "ciclo" corrente
	numComp = mergeSort(vetor, tamAtual);
	end = clock();//end recebe o "ciclo" corrente
	//o tempo total é a diferença dividia pelos ciclos por segundo
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Tempo total: %f   |   Número de comparações: %d \n\n", total, numComp);

/* ================================================================================ */

	tamAtual = TAM_VETOR3; /* VETOR DE 100K */

	printf("Criando vetor de tamanho %d para o Merge Sort.\n", tamAtual);
	vetor = vetorRand(vetor, tamAtual);
	start = clock();//start recebe o "ciclo" corrente
	numComp = mergeSort(vetor, tamAtual);
	end = clock();//end recebe o "ciclo" corrente
	//o tempo total é a diferença dividia pelos ciclos por segundo
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Tempo total: %f   |   Número de comparações: %d \n\n", total, numComp);

	return;
}

void testaQuick(int* vetor){

	int tamAtual = TAM_VETOR1; /* VETOR DE 10K */
	unsigned int numComp;

	printf("Criando vetor de tamanho %d para o Quick Sort.\n", tamAtual);
	vetor = vetorRand(vetor, tamAtual);
	clock_t start, end;//variáveis do tipo clock_t
    double total;
	start = clock();//start recebe o "ciclo" corrente
	numComp = quickSort(vetor, tamAtual);
	end = clock();//end recebe o "ciclo" corrente
	//o tempo total é a diferença dividia pelos ciclos por segundo
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Tempo total: %f   |   Número de comparações: %d \n\n", total, numComp);

/* ================================================================================ */

	tamAtual = TAM_VETOR2; /* VETOR DE 50K */

	printf("Criando vetor de tamanho %d para o Quick Sort.\n", tamAtual);
	vetor = vetorRand(vetor, tamAtual);
	start = clock();//start recebe o "ciclo" corrente
	numComp = quickSort(vetor, tamAtual);
	end = clock();//end recebe o "ciclo" corrente
	//o tempo total é a diferença dividia pelos ciclos por segundo
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Tempo total: %f   |   Número de comparações: %d \n\n", total, numComp);

/* ================================================================================ */

	tamAtual = TAM_VETOR3; /* VETOR DE 100K */

	printf("Criando vetor de tamanho %d para o Quick Sort.\n", tamAtual);
	vetor = vetorRand(vetor, tamAtual);
	start = clock();//start recebe o "ciclo" corrente
	numComp = quickSort(vetor, tamAtual);
	end = clock();//end recebe o "ciclo" corrente
	//o tempo total é a diferença dividia pelos ciclos por segundo
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Tempo total: %f   |   Número de comparações: %d \n\n", total, numComp);

	return;
}

void testaHeap(int* vetor){

	int tamAtual = TAM_VETOR1; /* VETOR DE 10K */
	unsigned int numComp;

	printf("Criando vetor de tamanho %d para o Heap Sort.\n", tamAtual);
	vetor = vetorRand(vetor, tamAtual);
	clock_t start, end;//variáveis do tipo clock_t
    double total;
	start = clock();//start recebe o "ciclo" corrente
	numComp = heapSort(vetor, tamAtual);
	end = clock();//end recebe o "ciclo" corrente
	//o tempo total é a diferença dividia pelos ciclos por segundo
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Tempo total: %f   |   Número de comparações: %d \n\n", total, numComp);

/* ================================================================================ */

	tamAtual = TAM_VETOR2; /* VETOR DE 50K */

	printf("Criando vetor de tamanho %d para o Heap Sort.\n", tamAtual);
	vetor = vetorRand(vetor, tamAtual);
	start = clock();//start recebe o "ciclo" corrente
	numComp = heapSort(vetor, tamAtual);
	end = clock();//end recebe o "ciclo" corrente
	//o tempo total é a diferença dividia pelos ciclos por segundo
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Tempo total: %f   |   Número de comparações: %d \n\n", total, numComp);

/* ================================================================================ */

	tamAtual = TAM_VETOR3; /* VETOR DE 100K */

	printf("Criando vetor de tamanho %d para o Heap Sort.\n", tamAtual);
	vetor = vetorRand(vetor, tamAtual);
	start = clock();//start recebe o "ciclo" corrente
	numComp = heapSort(vetor, tamAtual);
	end = clock();//end recebe o "ciclo" corrente
	//o tempo total é a diferença dividia pelos ciclos por segundo
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Tempo total: %f   |   Número de comparações: %d \n\n", total, numComp);

	return;
}

void testaBuscaSeq(int* vetor, int numComp){
	int tamAtual = TAM_VETOR1;
	int idxBusca;

	printf("Criando vetor de tamanho %d para a busca sequencial.\n", tamAtual);
	vetor = vetorRand(vetor, tamAtual);

	int valorAlvo;
	valorAlvo = rand() % MAX_VALOR; /* gera um valor aleatório possível para a busca */
	printf("Valor alvo: %d\n", valorAlvo);

	clock_t start, end;//variáveis do tipo clock_t
    double total;
	start = clock();//start recebe o "ciclo" corrente
	idxBusca = buscaSequencial(vetor, tamAtual, valorAlvo, &numComp);
	end = clock();//end recebe o "ciclo" corrente
	//o tempo total é a diferença dividia pelos ciclos por segundo
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Tempo total: %f   |   Número de comparações: %d\n", total, numComp);
	if (idxBusca < 0){
		printf("Valor não encontrado\n\n");
	}
	else {
		printf("Valor encontrado no índice %d\n\n", idxBusca);
	}

/* =========================================================================================== */

	tamAtual = TAM_VETOR2;
	numComp = 0;

	printf("Criando vetor de tamanho %d para a busca sequencial.\n", tamAtual);
	vetor = vetorRand(vetor, tamAtual);

	valorAlvo = rand() % MAX_VALOR;
	printf("Valor alvo: %d\n", valorAlvo);

	start = clock();//start recebe o "ciclo" corrente
	idxBusca = buscaSequencial(vetor, tamAtual, valorAlvo, &numComp);
	end = clock();//end recebe o "ciclo" corrente
	//o tempo total é a diferença dividia pelos ciclos por segundo
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Tempo total: %f   |   Número de comparações: %d\n", total, numComp);
	if (idxBusca < 0){
		printf("Valor não encontrado\n\n");
	}
	else {
		printf("Valor encontrado no índice %d\n\n", idxBusca);
	}

/* =========================================================================================== */

	tamAtual = TAM_VETOR3;
	numComp = 0;

	printf("Criando vetor de tamanho %d para a busca sequencial.\n", tamAtual);
	vetor = vetorRand(vetor, tamAtual);

	valorAlvo = rand() % MAX_VALOR;
	printf("Valor alvo: %d\n", valorAlvo);

	start = clock();//start recebe o "ciclo" corrente
	idxBusca = buscaSequencial(vetor, tamAtual, valorAlvo, &numComp);
	end = clock();//end recebe o "ciclo" corrente
	//o tempo total é a diferença dividia pelos ciclos por segundo
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Tempo total: %f   |   Número de comparações: %d\n", total, numComp);
	if (idxBusca < 0){
		printf("Valor não encontrado\n\n");
	}
	else {
		printf("Valor encontrado no índice %d\n\n", idxBusca);
	}
}

void testaBuscaBinaria(int* vetor, int numComp){
	int tamAtual = TAM_VETOR1;
	int idxBusca;

	printf("Criando vetor de tamanho %d para a busca binária.\n", tamAtual);
	vetor = vetorRand(vetor, tamAtual);

	int valorAlvo;
	valorAlvo = rand() % MAX_VALOR; /* gera um valor aleatório possível para a busca */
	printf("Valor alvo: %d\n", valorAlvo);

	clock_t start, end;//variáveis do tipo clock_t
    double total;
	start = clock();//start recebe o "ciclo" corrente
	if (mergeSort(vetor, tamAtual)){
		idxBusca = buscaBinaria(vetor, tamAtual, valorAlvo, &numComp);
	}
	end = clock();//end recebe o "ciclo" corrente
	//o tempo total é a diferença dividia pelos ciclos por segundo
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Tempo total: %f   |   Número de comparações: %d\n", total, numComp);
	if (idxBusca < 0){
		printf("Valor não encontrado.\n\n");
	}
	else {
		printf("Valor encontrado.\n\n");
	}

/* =========================================================================================== */

	tamAtual = TAM_VETOR2;
	numComp = 0;

	printf("Criando vetor de tamanho %d para a busca binária.\n", tamAtual);
	vetor = vetorRand(vetor, tamAtual);

	valorAlvo = rand() % MAX_VALOR;
	printf("Valor alvo: %d\n", valorAlvo);

	start = clock();//start recebe o "ciclo" corrente
	if (mergeSort(vetor, tamAtual)){
		idxBusca = buscaBinaria(vetor, tamAtual, valorAlvo, &numComp);
	}
	end = clock();//end recebe o "ciclo" corrente
	//o tempo total é a diferença dividia pelos ciclos por segundo
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Tempo total: %f   |   Número de comparações: %d\n", total, numComp);
	if (idxBusca < 0){
		printf("Valor não encontrado.\n\n");
	}
	else {
		printf("Valor encontrado.\n\n");
	}

/* =========================================================================================== */

	tamAtual = TAM_VETOR3;
	numComp = 0;

	printf("Criando vetor de tamanho %d para a busca binária.\n", tamAtual);
	vetor = vetorRand(vetor, tamAtual);

	valorAlvo = rand() % MAX_VALOR;
	printf("Valor alvo: %d\n", valorAlvo);

	start = clock();//start recebe o "ciclo" corrente
	if (mergeSort(vetor, tamAtual)){
		idxBusca = buscaBinaria(vetor, tamAtual, valorAlvo, &numComp);
	}
	end = clock();//end recebe o "ciclo" corrente
	//o tempo total é a diferença dividia pelos ciclos por segundo
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Tempo total: %f   |   Número de comparações: %d\n", total, numComp);
	if (idxBusca < 0){
		printf("Valor não encontrado.\n\n");
	}
	else {
		printf("Valor encontrado.\n\n");
	}
}

int main(){
	char nome[MAX_CHAR_NOME];
	char nome2[MAX_CHAR_NOME];
	unsigned int numComp = 0;
	srand(clock()); // gera seeds diferentes sempre q rodar
	//int numComparacoes;

	//Dica: somente é posśivel criar vetores grandes utilizando alocação dinâmica de memória
	//Veja um exemplo de alocação dinâmica a seguir
	int* vetor = malloc(TAM_VETOR3 * sizeof(int));
	if(vetor == NULL){
		printf("Falha fatal. Impossível alocar memoria.");
		return -1;
	}
	//Depois de alocado, o vetor pode ser utilizado normalmente
	//Não esqueça de desalocar no final do programa via free


	getNome(nome, nome2);
	printf("Trabalho de %s e %s \n", nome, nome2);
	printf("GRR %u, GRR %u \n\n", getGRR1(), getGRR2());

/*	getNome(nome2);
	printf("Trabalho de %s\n", nome2);
	printf("GRR %u\n", getGRR());*/
	testaInsertion(vetor);
	testaSelection(vetor);
	testaMerge(vetor);
	testaQuick(vetor);
	testaHeap(vetor);

	testaBuscaSeq(vetor, numComp);
	testaBuscaBinaria(vetor, numComp);

	//É obrigatório que você libere a memória alocada dinamicamente via free
	free(vetor);

	return 0;
}
