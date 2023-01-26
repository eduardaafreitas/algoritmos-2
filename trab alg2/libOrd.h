#ifndef LIBORDENACAO_H
#define LIBORDENACAO_H

void troca(int *vetor, int i, int j);
int* insereOrdenado(int *vetor, int tam, int valor, int* numComparacoes);
void imprimeVetor(int *vetor, int tam);
int minimoVetor(int *vetor, int a, int b);
int selecionaEOrdena(int *vetor, int prim, int tam);
void ordenaMerge(int vetor[], int ini, int tam);
int* intercala(int *vetor, int ini, int meio, int tam);

#endif