#ifndef LIBORDENACAO_H
#define LIBORDENACAO_H

void troca(int *vetor, int i, int j);
void imprimeVetor(int *vetor, int tam);

void ordenaInsertion(int vetor[], int tam, int* numComparacoes);

int minimoVetor(int vetor[], int a, int b, int *numComparacoes);
int selecionaEOrdena(int vetor[], int prim, int tam, int* numComparacoes);

void intercala(int* vetor, int ini, int meio, int tam, int *numComparacoes);
void ordenaMerge(int *vetor, int ini, int tam, int *numComparacoes);

int particiona(int vetor[], int tam, int pivo, int *numComparacoes);
void ordenaQuick(int vetor[], int ini, int tam, int *numComparacoes);

void maxHeapify(int vetor[], int tam, int ini, int *numComparacoes);
void buildMaxHeapify(int vetor[], int tam, int *numComparacoes);
void ordenaHeap(int vetor[], int tam, int *numComparacoes);


#endif