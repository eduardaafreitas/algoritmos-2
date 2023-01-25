#include <stdio.h>
#include <stdlib.h>

void troca(int *vetor, int i, int j){
	int aux;
	aux = vetor[i];
	vetor[i] = vetor[j];
	vetor[j] = aux;
}

int* insereOrdenado(int *vetor, int tam, int valor, int* numComparacoes){
	int p, i;
	p = buscaSequencial(vetor, tam-1, valor, numComparacoes);
	while(i > p+1){
		troca(vetor, i, i-1);
		i--;
	}
	return vetor;
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

int main(){
    int vetor[10] = {1,2,3,4,5,6,7,8,9,10};
    int n, x;
	int i;
    int numComparacoes = 0;
    int num = 0;
	for(i=0, i < 10; i++){
		printf("%d ", vetor[i]);
	}
    scanf("%d", &n);
	scanf("%d", &x);
    troca(vetor, n, x);
    printf("primeiro %d, segundo %d \n", vetor[n], vetor[x]);

    return 0;
}