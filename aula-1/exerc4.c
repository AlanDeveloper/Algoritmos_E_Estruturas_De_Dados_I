#include <stdio.h>

int main() {
  int l = 3, c = 3;
  float matriz[l][c], *p = NULL;

  for (size_t i = 0; i < l; i++)
  {
    for (size_t j = 0; j < c; j++)
    {
      p = &matriz[i][j];
      printf("Endereço da posição %dx%d: %p\n", i, j, p);
    }
    
  }
  return 0;
}