#include <stdio.h>
#include <stdlib.h>

void imprimeVetor(int *vetor, int tam){
	int i;
	for(i = 0; i < tam; i++){
		printf("%d ", vetor[i]);
	}
	printf("\n");
}

int buscaBinIniFim(int *vetor, int valor, int ini, int fim, int* numComp){
	if (fim < ini){
		return -1;
	}
	int meio = (ini + fim) / 2;
	*numComp = *numComp + 1; /*fazendo antes da comparação p garantir que conta*/
	if (valor == vetor[meio]){
		return meio;
	}
	*numComp = *numComp + 1;
	if (valor < vetor[meio]){
		return buscaBinIniFim(vetor, valor, ini, meio-1, numComp);
	}
	return buscaBinIniFim(vetor, valor, meio+1, fim, numComp);
}

int buscaBinaria(int vetor[], int tam, int valor, int* numComparacoes){			//colocar alg ordenação
	/* vai ser wrapper */
	if (tam <=0){
		return -1;
	}
	return buscaBinIniFim(vetor, valor, 0, tam, numComparacoes);
}

int main(){
    int vetor[11] = {0,1,2,3,4,5,6,7,8,9,10};
    int pesquisa = 0;
    int numcomp;
    int num;
	printf("-vetor: ");
	imprimeVetor(vetor, 11);
    num = buscaBinaria(vetor, 11, pesquisa, &numcomp);
	printf("---- achou: %d\n", num);
	printf("num comp: %d \n", numcomp);

    return 0;
}