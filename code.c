#include <stdio.h>
#include <stdlib.h>

int buscaBinaria(int vetor[], int tam, int valor, int* numComparacoes){
	int meio;
	meio = tam/2;
	if (tam == 0){
		return -1;
	}
	else {
		numComparacoes++;
		if (valor == vetor[meio]){
			return meio;
		}
		else if (valor < vetor[meio]){
			numComparacoes++;
			meio--;
			return buscaBinaria(vetor, meio, valor, numComparacoes);
		}
		else if (valor > vetor[meio]){
			numComparacoes++;
			meio++;
			return buscaBinaria(vetor, meio, valor, numComparacoes);
		}
	}
	return -1;
}

int main(){
    int vetor[10] = {1,2,3,4,5,6,7,8,9,10};
    int n;
    int numComparacoes = 0;
    int num = 0;
    scanf("%d", &n);
    int divisao = buscaBinaria(vetor, 10, n, &numComparacoes);
    printf("%d", num);

    return 0;
}