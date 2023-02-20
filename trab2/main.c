#include <stdio.h>
#include <stdlib.h>
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

int papaiNoel(struct Presentes* saco, int n, int p_max){

	struct Presentes* lista_final; /* o lista_final irá conter os presentes q serão enviados ao fim :P */
	lista_final = malloc(n * sizeof(struct Presentes));
	if (lista_final == NULL){
		printf("Erro na alocação! Encerrando... \n");
		return -1;
	}

	insertionSort(saco, n); /* ordena os presentes do saco por valor sentimental */
	/* A FAZER AQUI: calculo da arvore? pra descobrir quantidade de linhas nela */
	return 1;
}

void papaiNoelUtil(struct Presentes* lista_final, struct Presentes* saco, int p_max, int n, int L, int linha_final_arvore){

	/* CASO BASE: se o peso eh menor ou igual a p_max, e chegou ao fim da arvore, retorna*/
	if (pesoAtual(lista_final, n) <= p_max && L == linha_final_arvore){ 
		printf("Imprimindo a lista final de presentes enviados: \n");
		imprimeLista(lista_final, n);
		printf("Soma total do valor sentimental: ");
		valorSentTotal(lista_final, n);
		return;
	}
	/* inserir um presente na lista final e testar se "cabe" */
	/* se não cabe, subir um ramo da árvore e testar o proximo presente mais valoroso */
	return;
}

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
	for (int i = 0; i <= tam_lista; ++i){
		total = total + lista_atual[i].peso;
	}
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

	if (papaiNoel) { /* roda o papaiNoel e o algoritmo*/
		printf("Rodando... \n");
	}
	else{
		printf("Algo deu errado na hora de rodar o algoritmo. \n");
	}

	return 0;
}

/* PROBLEMAS A RESOLVER: 
- implementação de fato do backtrack
- como maximizar de certeza o valor dos presentes?
	-> tentar juntar todos com o maior valor sentimental primeiro? daí tira o com menor peso conforme a arvore continua
	ATT: já fiz isso! */