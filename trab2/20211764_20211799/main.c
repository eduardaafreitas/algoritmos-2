#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
/*
n: presentes disponiveis
p_max: capacidade
v: valor sentimental
p: peso
*/

struct Presentes {
	int valor_s;
	int peso;
} presente;


/* ============================================================================================== */

void imprimeLista(struct Presentes* lista_final, int tam){ /* eh um imprimevetor adaptado */
	int i;
	for(i = 0; i < tam; i++){
		if(lista_final[i].valor_s != 0 && lista_final[i].peso != 0){
			printf("%d %d \n", lista_final[i].valor_s, lista_final[i].peso);
		}
	}
	printf("\n");
	return;
}

/* teste do peso atual do saco */
int pesoAtual (struct Presentes* lista_atual, int tam_lista){
	int i;
	int total = 0;
	for (int i = 0; i < tam_lista; ++i){
		total = total + lista_atual[i].peso;
	}
	//printf("Peso medido. Valor: %d \n", total);
	return total;
}

/* imprime o valor sentimental total na lista de presentes */
int valorSentTotal (struct Presentes* lista_atual, int tam_lista){
	int i;
	int total = 0;
	for (int i = 0; i < tam_lista; ++i){
		total = total + lista_atual[i].valor_s;
	}
	//printf("%d \n", total);
	return total;
}

int isSafe(int p_max, int p_atual){
	return (p_atual <= p_max); /* 1 se o p_max for igual ou maior q o peso atual (nao excedeu capacidade de peso) */
}

void papaiNoelUtil(struct Presentes* lista_final, struct Presentes* saco, int p_max, int n, struct Presentes* solucao){

	int pesoAt = pesoAtual(lista_final, n);
	/* CASO BASE: se o peso eh menor ou igual a p_max, e chegou ao fim da arvore, retorna*/
	if ((isSafe(p_max, pesoAt) == 0)){ 
		return;
	}
	else {
		for(int i = 0; i < n; i++){
			if ((lista_final[i].valor_s == 0) && (lista_final[i].peso == 0)){
				lista_final[i].valor_s = saco[i].valor_s;
				lista_final[i].peso = saco[i].peso;
				papaiNoelUtil(lista_final, saco, p_max, n, solucao);		//backtracking
				lista_final[i].valor_s = 0;
				lista_final[i].peso = 0;	
			}
		}
	}
	if (valorSentTotal(solucao, n) < valorSentTotal(lista_final, n)){
		memcpy(solucao, lista_final, n * sizeof(struct Presentes));
	}
}

void papaiNoel(struct Presentes* saco, int n, int p_max, struct Presentes* solucao){

	struct Presentes* lista_final; /* o lista_final irá conter os presentes q serão enviados ao fim :P */
	lista_final = calloc(n, sizeof(struct Presentes));
	if (lista_final == NULL){
		printf("Erro na alocação! Encerrando... \n");
		return;
	}

	papaiNoelUtil(lista_final, saco, p_max, n, solucao);
	return;
}


int main(){
	int n;
	int p_max;
	printf("Insira quantidade de presentes a ser inserida: \n"); /*inserção dos dados n e p_max*/
	scanf("%i", &n);
	printf("Insira capacidade máxima: \n");
	scanf("%i", &p_max);

	struct Presentes* saco; /* alocando o saco do papai noel! */
	saco = malloc(n * sizeof(struct Presentes));
	if (saco == NULL){
		printf("Erro na alocação! Encerrando...\n");
		return -1;
	}

	int i = 0;
	printf("Insira valor sentimental e peso do presente, em ordem:\n");
	for (int i = 0; i < n; ++i){ /* inserção de todos presentes! */
		scanf("%i %i", &saco[i].valor_s, &saco[i].peso);
	}
	struct Presentes* solucao;
	solucao = calloc(n, sizeof(struct Presentes));
	printf("Imprimindo os dados inseridos: \n");
	imprimeLista(saco, n);

	papaiNoel(saco, n, p_max, solucao);
	printf("Solucao encontrada: \n");
	imprimeLista(solucao, n);

	return 0;
}
