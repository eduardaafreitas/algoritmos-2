#include "biblioteca.h"

/* -------------------------------------------------------------------------- */
/* ordena v[a..b] pelo m�todo da sele��o e devolve v */
/* N�o conseguimos implementar a vers�o inteiramente recursiva */
int *insercao(int v[], unsigned int a, unsigned int b) {
    if(compara(a, b) == 1 || a == b) /* a >= b */
  	return v;
  insercao(v, a, b - 1);
  int ultimo = v[b - a];
  int j = b - a - 1;
  while((compara(j, 0) == 1 || j == 0) && compara(v[j], ultimo) == 1){ /* j >= 0 && v[j] > ultimo */
  	v[j + 1] = v[j];
  	j--;
  }
  v[j + 1] = ultimo;
  return v;
}
