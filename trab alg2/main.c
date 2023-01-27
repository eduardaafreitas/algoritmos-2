#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "ordenacao.h"
#include "libOrd.h"

#define TAM_VETOR1 10000 /* tamanho do vetor */
#define TAM_VETOR2 50000 /* tamanho do vetor */
#define TAM_VETOR3 100000 /* tamanho do vetor */
#define MAX_VALOR 32768 /* 2^15; valor max q um numero pode assumir */

int* vetorRand(int* vetor){
	int i;
	for (int i = 0; i < TAM_VETOR; ++i){
		vetor[i] = rand() % MAX_VALOR;
	}
	return vetor;
}

void testaInsertion(int* vetor){

	int tamAtual = TAM_VETOR1; /* VETOR DE 10K */

	printf("Criando vetor de tamanho %d para o Insertion Sort.\n", tamAtual);
	vetor = vetorRand(vetor);
	clock_t start, end;//variáveis do tipo clock_t
    double total;
	start = clock();//start recebe o "ciclo" corrente
	numComp = insertionSort(vetor, tamAtual);
	end = clock();//end recebe o "ciclo" corrente
	//o tempo total é a diferença dividia pelos ciclos por segundo
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Tempo total: %f   | Número de comparações: %d \n", total, numComp);

/* ================================================================================ */

	tamAtual = TAM_VETOR2; /* VETOR DE 50K */

	printf("Criando vetor de tamanho %d para o Insertion Sort.\n", tamAtual);
	vetor = vetorRand(vetor);
	clock_t start, end;//variáveis do tipo clock_t
	start = clock();//start recebe o "ciclo" corrente
	numComp = insertionSort(vetor, tamAtual);
	end = clock();//end recebe o "ciclo" corrente
	//o tempo total é a diferença dividia pelos ciclos por segundo
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Tempo total: %f   | Número de comparações: %d \n", total, numComp);

/* ================================================================================ */

	tamAtual = TAM_VETOR3; /* VETOR DE 100K */

	printf("Criando vetor de tamanho %d para o Insertion Sort.\n", tamAtual);
	vetor = vetorRand(vetor);
	clock_t start, end;//variáveis do tipo clock_t
	start = clock();//start recebe o "ciclo" corrente
	numComp = insertionSort(vetor, tamAtual);
	end = clock();//end recebe o "ciclo" corrente
	//o tempo total é a diferença dividia pelos ciclos por segundo
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Tempo total: %f   | Número de comparações: %d \n", total, numComp);

	return;
}

void testaSelection(int* vetor){

	int tamAtual = TAM_VETOR1; /* VETOR DE 10K */

	printf("Criando vetor de tamanho %d para o Selection Sort.\n", tamAtual);
	vetor = vetorRand(vetor);
	clock_t start, end;//variáveis do tipo clock_t
    double total;
	start = clock();//start recebe o "ciclo" corrente
	numComp = selectionSort(vetor, tamAtual);
	end = clock();//end recebe o "ciclo" corrente
	//o tempo total é a diferença dividia pelos ciclos por segundo
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Tempo total: %f   | Número de comparações: %d \n", total, numComp);

/* ================================================================================ */

	tamAtual = TAM_VETOR2; /* VETOR DE 50K */

	printf("Criando vetor de tamanho %d para o Selection Sort.\n", tamAtual);
	vetor = vetorRand(vetor);
	clock_t start, end;//variáveis do tipo clock_t
	start = clock();//start recebe o "ciclo" corrente
	numComp = selectionSort(vetor, tamAtual);
	end = clock();//end recebe o "ciclo" corrente
	//o tempo total é a diferença dividia pelos ciclos por segundo
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Tempo total: %f   | Número de comparações: %d \n", total, numComp);

/* ================================================================================ */

	tamAtual = TAM_VETOR3; /* VETOR DE 100K */

	printf("Criando vetor de tamanho %d para o Selection Sort.\n", tamAtual);
	vetor = vetorRand(vetor);
	clock_t start, end;//variáveis do tipo clock_t
	start = clock();//start recebe o "ciclo" corrente
	numComp = selectionSort(vetor, tamAtual);
	end = clock();//end recebe o "ciclo" corrente
	//o tempo total é a diferença dividia pelos ciclos por segundo
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Tempo total: %f   | Número de comparações: %d \n", total, numComp);

	return;
}

void testaMerge(int* vetor){

	int tamAtual = TAM_VETOR1; /* VETOR DE 10K */

	printf("Criando vetor de tamanho %d para o Merge Sort.\n", tamAtual);
	vetor = vetorRand(vetor);
	clock_t start, end;//variáveis do tipo clock_t
    double total;
	start = clock();//start recebe o "ciclo" corrente
	numComp = mergeSort(vetor, tamAtual);
	end = clock();//end recebe o "ciclo" corrente
	//o tempo total é a diferença dividia pelos ciclos por segundo
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Tempo total: %f   | Número de comparações: %d \n", total, numComp);

/* ================================================================================ */

	tamAtual = TAM_VETOR2; /* VETOR DE 50K */

	printf("Criando vetor de tamanho %d para o Merge Sort.\n", tamAtual);
	vetor = vetorRand(vetor);
	clock_t start, end;//variáveis do tipo clock_t
	start = clock();//start recebe o "ciclo" corrente
	numComp = mergeSort(vetor, tamAtual);
	end = clock();//end recebe o "ciclo" corrente
	//o tempo total é a diferença dividia pelos ciclos por segundo
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Tempo total: %f   | Número de comparações: %d \n", total, numComp);

/* ================================================================================ */

	tamAtual = TAM_VETOR3; /* VETOR DE 100K */

	printf("Criando vetor de tamanho %d para o Merge Sort.\n", tamAtual);
	vetor = vetorRand(vetor);
	clock_t start, end;//variáveis do tipo clock_t
	start = clock();//start recebe o "ciclo" corrente
	numComp = mergeSort(vetor, tamAtual);
	end = clock();//end recebe o "ciclo" corrente
	//o tempo total é a diferença dividia pelos ciclos por segundo
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Tempo total: %f   | Número de comparações: %d \n", total, numComp);

	return;
}

void testaQuick(int* vetor){

	int tamAtual = TAM_VETOR1; /* VETOR DE 10K */

	printf("Criando vetor de tamanho %d para o Quick Sort.\n", tamAtual);
	vetor = vetorRand(vetor);
	clock_t start, end;//variáveis do tipo clock_t
    double total;
	start = clock();//start recebe o "ciclo" corrente
	numComp = quickSort(vetor, tamAtual);
	end = clock();//end recebe o "ciclo" corrente
	//o tempo total é a diferença dividia pelos ciclos por segundo
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Tempo total: %f   | Número de comparações: %d \n", total, numComp);

/* ================================================================================ */

	tamAtual = TAM_VETOR2; /* VETOR DE 50K */

	printf("Criando vetor de tamanho %d para o Quick Sort.\n", tamAtual);
	vetor = vetorRand(vetor);
	clock_t start, end;//variáveis do tipo clock_t
	start = clock();//start recebe o "ciclo" corrente
	numComp = quickSort(vetor, tamAtual);
	end = clock();//end recebe o "ciclo" corrente
	//o tempo total é a diferença dividia pelos ciclos por segundo
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Tempo total: %f   | Número de comparações: %d \n", total, numComp);

/* ================================================================================ */

	tamAtual = TAM_VETOR3; /* VETOR DE 100K */

	printf("Criando vetor de tamanho %d para o Quick Sort.\n", tamAtual);
	vetor = vetorRand(vetor);
	clock_t start, end;//variáveis do tipo clock_t
	start = clock();//start recebe o "ciclo" corrente
	numComp = quickSort(vetor, tamAtual);
	end = clock();//end recebe o "ciclo" corrente
	//o tempo total é a diferença dividia pelos ciclos por segundo
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Tempo total: %f   | Número de comparações: %d \n", total, numComp);

	return;
}

void testaHeap(int* vetor){

	int tamAtual = TAM_VETOR1; /* VETOR DE 10K */

	printf("Criando vetor de tamanho %d para o Heap Sort.\n", tamAtual);
	vetor = vetorRand(vetor);
	clock_t start, end;//variáveis do tipo clock_t
    double total;
	start = clock();//start recebe o "ciclo" corrente
	numComp = heapSort(vetor, tamAtual);
	end = clock();//end recebe o "ciclo" corrente
	//o tempo total é a diferença dividia pelos ciclos por segundo
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Tempo total: %f   | Número de comparações: %d \n", total, numComp);

/* ================================================================================ */

	tamAtual = TAM_VETOR2; /* VETOR DE 50K */

	printf("Criando vetor de tamanho %d para o Heap Sort.\n", tamAtual);
	vetor = vetorRand(vetor);
	clock_t start, end;//variáveis do tipo clock_t
	start = clock();//start recebe o "ciclo" corrente
	numComp = heapSort(vetor, tamAtual);
	end = clock();//end recebe o "ciclo" corrente
	//o tempo total é a diferença dividia pelos ciclos por segundo
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Tempo total: %f   | Número de comparações: %d \n", total, numComp);

/* ================================================================================ */

	tamAtual = TAM_VETOR3; /* VETOR DE 100K */

	printf("Criando vetor de tamanho %d para o Heap Sort.\n", tamAtual);
	vetor = vetorRand(vetor);
	clock_t start, end;//variáveis do tipo clock_t
	start = clock();//start recebe o "ciclo" corrente
	numComp = heapSort(vetor, tamAtual);
	end = clock();//end recebe o "ciclo" corrente
	//o tempo total é a diferença dividia pelos ciclos por segundo
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Tempo total: %f   | Número de comparações: %d \n", total, numComp);

	return;
}


int main(){
	char nome[MAX_CHAR_NOME];
	char nome2[MAX_CHAR_NOME];
	int idxBusca;
	int numComp;
	//int numComparacoes;

	//Dica: somente é posśivel criar vetores grandes utilizando alocação dinâmica de memória
	//Veja um exemplo de alocação dinâmica a seguir
	int* vetor = malloc(TAM * sizeof(int));
	if(vetor == NULL){
		printf("Falha fatal. Impossível alocar memoria.");
		return -1;
	}
	//Depois de alocado, o vetor pode ser utilizado normalmente
	//Não esqueça de desalocar no final do programa via free


	getNome(nome);
	getNome(nome2);
	printf("Trabalho de %s e %s \n", nome, nome2);
	printf("GRR %u, GRR %u \n", getGRR1(), getGRR2());

/*	getNome(nome2);
	printf("Trabalho de %s\n", nome2);
	printf("GRR %u\n", getGRR());*/
	testaInsertion(vetor);
	testaSelection(vetor);
	testaMerge(vetor);
	testaQuick(vetor);
	testaHeap(vetor);

	idxBusca = buscaSequencial(vetor, 3, 10, &numComp);
	idxBusca = buscaBinaria(vetor, 3, 10, &numComp);

	printf("\n%d %d", idxBusca, numComp);
	printf("\n");

	//É obrigatório que você libere a memória alocada dinamicamente via free
	free(vetor);

	return 0;
}
