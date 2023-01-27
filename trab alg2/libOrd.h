#ifndef LIBORDENACAO_H
#define LIBORDENACAO_H

void troca(int *vetor, int i, int j);
void imprimeVetor(int *vetor, int tam);
int minimoVetor(int *vetor, int a, int b);

int* insereOrdenado(int *vetor, int tam, int valor, int* numComparacoes);

int selecionaEOrdena(int *vetor, int prim, int tam);

void ordenaMerge(int vetor[], int ini, int tam);
int* intercala(int *vetor, int ini, int meio, int tam);

int particiona(int vetor[], int tam, int pivo);
void ordenaQuick(int vetor[], int ini, int tam);

void maxHeapify(int vetor[], int tam, int ini);
void buildMaxHeapify(int vetor[], int tam);
void ordenaHeap(int vetor[], int tam);


#endif