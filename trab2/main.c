#include <stdio.h>
#include <stdlib.h>
/*
n: presentes disponiveis
p_max: capacidade
v: valor sentimental
p: peso
*/

struct presentes{
	int valor_s;
	int peso;
} presente;

int papaiNoel(int n, int p_max){

}

void papaiNoelUtil(){
/* backtracking aqui */
}

void imprimeVetor(int *vetor, int tam){
	int i;
	for(i = 0; i < tam; i++){
		printf("%d ", vetor[i]);
	}
	printf("\n");
}

int isSafe(int p_max, int p_atual){
	return (p_max >= p_atual); /* 1 se o p_max for igual ou maior q o peso atual (n excedeu capacidade de peso) */
}

int main(){
	int n;
	int p_max;
	printf("Insira quantidade de presentes a ser inserida: \n");
	scanf("%i", &n);
	printf("Insira capacidade máxima: \n");
	scanf("%i", &p_max);

	presente* saco; /* alocando o saco do papai noel! */
	saco = malloc(n * sizeof(presente));
	if (saco == NULL){
		printf("Erro na alocação! Encerrando...\n");
		return -1;
	}

	int i = 0;
	for (int i = 0; i < n; ++i){ /* inserção de todos presentes! */
		printf("Insira valor sentimental e peso do presente, em ordem:\n");
		scanf("%i %i", &saco[i]->valor_s, &saco[i]->peso);
	}

	presente* lista_final; /* o lista_final irá conter os presentes q serão enviados ao fim :P */
	lista_final = malloc(n * sizeof(presente));
	if (lista_final == NULL){
		printf("Erro na alocação! Encerrando... \n")
		return -1;
	}

	printf("Imprimindo os dados inseridos: \n");
	imprimeVetor(saco, n);


	printf("Imprimindo a lista final de presentes enviados: \n");
	imprimeVetor(lista_final, n);

	return 0;
}

/* PROBLEMAS A RESOLVER: 
- implementação de fato do backtrack
- como maximizar de certeza o valor dos presentes?
	-> tentar juntar todos com o maior valor sentimental primeiro? daí tira o com menor peso conforme a arvore continua */