#include <stdio.h>


void preenche(int *a, int valor) {
  int i = 0;
  
  do {
    *a = valor;
    *a++;
    i++;
  } while (i < 5);
}

void lista(int *a) {
  for (size_t i = 0; i < 5; i++)
  {
    printf("%d ", *a);
    *a++;
  }
}

int main() {
  int array[5], valor = 5;

  preenche(array, valor);
  lista(array);
  
  return 0;
}