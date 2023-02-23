#include <stdio.h>
#include <stdlib.h>
#include <math.h>
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

/* ============================================================================================ */

void ordenaInsertion(struct Presentes* lista_atual, int tam){
    if (tam == 0){
		return;
	}
    ordenaInsertion(lista_atual, tam-1);
 
    int ultimo_valor_s = lista_atual[tam-1].valor_s;
    struct Presentes ultimo;
    int j = tam-2;
    while (j >= 0 && lista_atual[j].valor_s > ultimo_valor_s){
        lista_atual[j+1] = lista_atual[j];
        j--;
    }
    lista_atual[j+1] = ultimo;
}

void insertionSort(struct Presentes* lista_atual, int tam){	
	if(tam == 0){
		return;
	}
	else{
		ordenaInsertion(lista_atual, tam-1);	//wrapper
	}
	return;
}

/* ============================================================================================== */

void imprimeLista(struct Presentes* lista_final, int tam){ /* eh um imprimevetor adaptado */
	int i;
	for(i = 0; i < tam; i++){
		printf("%d %d \n", lista_final[i].valor_s, lista_final[i].peso);
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
	printf("Peso medido. Valor: %d \n", total);
	return total;
}

/* imprime o valor sentimental total na lista de presentes */
void valorSentTotal (struct Presentes* lista_atual, int tam_lista){
	int i;
	int total = 0;
	for (int i = 0; i <= tam_lista; ++i){
		total = total + lista_atual[i].valor_s;
	}
	printf("%d \n", total);
	return;
}

int isSafe(int p_max, int p_atual){
	return (p_max >= p_atual); /* 1 se o p_max for igual ou maior q o peso atual (nao excedeu capacidade de peso) */
}

void papaiNoelUtil(struct Presentes* lista_final, struct Presentes* saco, int p_max, int n, int l, int num_linhas, int i, int j){

	int pesoAt = pesoAtual(lista_final, n);
	/* CASO BASE: se o peso eh menor ou igual a p_max, e chegou ao fim da arvore, retorna*/
	if ((pesoAt <= p_max) && (l == num_linhas) || (i >= n)){ 
		printf("Imprimindo a lista final de presentes enviados: \n");
		imprimeLista(saco, n);
		printf("Soma total do valor sentimental: ");
		valorSentTotal(lista_final, n);
		return;
	}
	else if (j == n){
		printf("Parando: j = n. \n");
		return;
	}
	else {
		for(i = 0; i < n; i++){
			/* se chegou ao fim e nn cumpre a expectativa, mas nn eh o fim do saco: */
			if ((pesoAt > p_max) && (l == num_linhas) && (j != n)){
				printf("Peso excedido: caso 1! Subindo. \n");
				lista_final[i].peso = 0;
				lista_final[i].valor_s = 0;
				l = l - 1; /* sobe uma linha */
				papaiNoelUtil(lista_final, saco, p_max, n, l, num_linhas, i, j); /* chama dnv e avança 1 pra frente */
			}
			/* se tiver q tirar presentes anteriores: */
			else if ((pesoAt > p_max) && (l == num_linhas) && ((i+1) == n) && (j != n)){
				printf("Peso excedido: caso 2! Subindo. \n");
				l = l - 1;
				lista_final[i].peso = 0;
				lista_final[i].valor_s = 0;
				i = i - 1;
				papaiNoelUtil(lista_final, saco, p_max, n, l, num_linhas, i, j+1);
			}

			lista_final[i].peso = saco[j].peso;
			lista_final[i].valor_s = saco[j].valor_s;
			printf("Lista atual: \n");
			imprimeLista(lista_final, n);
			l = l + 1;
			papaiNoelUtil(lista_final, saco, p_max, n, l, num_linhas, i+1, j+1);
			return;
		}
	}
}

void papaiNoel(struct Presentes* saco, int n, int p_max){

	struct Presentes* lista_final; /* o lista_final irá conter os presentes q serão enviados ao fim :P */
	lista_final = malloc(n * sizeof(struct Presentes));
	if (lista_final == NULL){
		printf("Erro na alocação! Encerrando... \n");
		return;
	}

	insertionSort(saco, n); /* ordena os presentes do saco por valor sentimental */

	int num_linhas;
	num_linhas = (int)(floor(log2((double)n))); /* altura da arvore = piso de log2 de n*/
	printf("Número de linhas na árvore: %d \n", num_linhas);

	papaiNoelUtil(lista_final, saco, p_max, n, 0, num_linhas, 0, 0);
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
	for (int i = 0; i < n; ++i){ /* inserção de todos presentes! */
		printf("Insira valor sentimental e peso do presente, em ordem:\n");
		scanf("%i %i", &saco[i].valor_s, &saco[i].peso);
	}

	printf("Imprimindo os dados inseridos: \n");
	imprimeLista(saco, n);

	papaiNoel(saco, n, p_max);

	return 0;
}
