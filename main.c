#include <stdio.h>
#include <stdlib.h>
/*
n: presentes disponiveis
p_max: capacidade
v: valor sentimental
p: peso
*/

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

void isSafe(){

}

int main(){
	int n;
	int p_max;
	int seletor; /*ver qual das entradas usa*/
	printf("Selecione qual das entradas (1-10) utilizar: \n");
	scanf("%i", &seletor);

	int* saco;
	saco = malloc(n * sizeof(int));
	if (saco == NULL){
		printf("Erro na alocação!\n")
		return -1;
	}


	return 0;
}