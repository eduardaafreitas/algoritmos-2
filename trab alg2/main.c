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

	printf("Criando vetor de tamanho %d para o Insertion Sort.\n", TAM_VETOR);
	vetor = vetorRand(vetor);
	clock_t start, end;//variáveis do tipo clock_t
    double total;
	start = clock();//start recebe o "ciclo" corrente
	numComp = insertionSort(vetor, TAM_VETOR);
	end = clock();//end recebe o "ciclo" corrente
	//o tempo total é a diferença dividia pelos ciclos por segundo
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Tempo total: %f", total);

	*numComparacoes = 0;

	printf("Criando vetor de tamanho %d para o Insertion Sort.\n", TAM_VETOR);
	vetor = vetorRand(vetor);
	clock_t start, end;//variáveis do tipo clock_t
    double total;
	start = clock();//start recebe o "ciclo" corrente
	numComp = selectionSort(vetor, TAM_VETOR);


	numComp = mergeSort(vetor, TAM_VETOR);


	numComp = quickSort(vetor, TAM_VETOR);
	

	numComp = heapSort(vetor, TAM_VETOR);

	for(int i=0; i < 3; i++){
		printf("%d ", vetor[i]);
	}
	idxBusca = buscaSequencial(vetor, 3, 10, &numComp);
	idxBusca = buscaBinaria(vetor, 3, 10, &numComp);

	printf("\n%d %d", idxBusca, numComp);
	printf("\n");

	//É obrigatório que você libere a memória alocada dinamicamente via free
	free(vetor);

	return 0;
}
