#include <stdio.h>
#include <stdlib.h>

int menu();
int **criaMatriz(int m, int n);
void leiaMatriz(int **mat, int m, int n);
int somaMatriz(int **mat, int m, int n);
int *colunaMatriz(int **mat, int m, int n, int ncoluna);
void imprimeMatriz(int **mat, int m, int n);
void imprimeVetor(int *vet, int n);
int **realocarMatriz(int **mat, int m, int n);
void **liberaMatriz(int **mat, int m);

int main()
{
  int **matriz = NULL, *vet = NULL, escolha, m = 0, n = 0, soma = 0, nColuna = 0;

  for (;;)
  {
    escolha = menu();
    switch (escolha)
    {
    case 1:
      if (matriz == NULL)
      {
        printf("\nDigite o número de linhas: ");
        scanf("%d", &m);
        printf("Digite o número de colunas: ");
        scanf("%d", &n);
        matriz = criaMatriz(m, n);
      }
      else
      {
        printf("\nMatriz já criada!\n");
      }
      break;
    case 2:
      printf("\nDigite o número de linhas: ");
      scanf("%d", &m);
      printf("Digite o número de colunas: ");
      scanf("%d", &n);
      matriz = realocarMatriz(matriz, m, n);
      break;
    case 3:
      leiaMatriz(matriz, m, n);
      break;
    case 4:
      soma = somaMatriz(matriz, m, n);
      printf("Resultado da soma: %d\n", soma);
      break;
    case 5:
      printf("Digite o número da coluna: ");
      scanf("%d", &nColuna);
      vet = colunaMatriz(matriz, m, n, nColuna);
      imprimeVetor(vet, m);
      break;
    case 6:
      imprimeMatriz(matriz, m, n);
      break;
    case 7:
      liberaMatriz(matriz, m);
      free(vet);
      exit(0);
      break;
    }
  }

  return 0;
}

int menu()
{
  int menu;
  do
  {
    printf("\n----------MENU----------");
    printf("\n1 - Criar matriz");
    printf("\n2 - Redimencionar matriz");
    printf("\n3 - Preencher elementos da matriz");
    printf("\n4 - Soma dos elementos da matriz");
    printf("\n5 - Listar elementos de uma coluna da matriz");
    printf("\n6 - Lista elementos da matriz");
    printf("\n7 - Sair");
    printf("\nEscolha uma opcao: ");
    scanf("%d", &menu);
  } while (menu <= 0 || menu > 7);

  return menu;
}

int **criaMatriz(int m, int n)
{
  int **matriz = NULL;

  matriz = (int **)malloc(m * sizeof(int *));
  for (size_t i = 0; i < m; i++)
  {
    matriz[i] = (int *)malloc(n * sizeof(int));
  }

  if (matriz == NULL)
  {
    printf("Nao foi possivel alocar memoria!");
    exit(1);
  }
  return matriz;
}

void leiaMatriz(int **mat, int m, int n)
{
  printf("\n");
  for (size_t i = 0; i < m; i++)
  {
    for (size_t j = 0; j < n; j++)
    {
      printf("Digite um número: ");
      scanf("%d", &mat[i][j]);
    }
  }
}

int somaMatriz(int **mat, int m, int n)
{
  int soma = 0;

  for (size_t i = 0; i < m; i++)
  {
    for (size_t j = 0; j < n; j++)
    {
      soma += mat[i][j];
    }
  }
  printf("\n");
  return soma;
}

void imprimeMatriz(int **mat, int m, int n)
{
  for (size_t i = 0; i < m; i++)
  {
    for (size_t j = 0; j < n; j++)
    {
      printf("\nPosicao[%ld][%ld]: %d", i, j, mat[i][j]);
    }
    printf("\n");
  }
}

int *colunaMatriz(int **mat, int m, int n, int ncoluna)
{
  int *vetor = NULL;
  vetor = (int *)calloc(m, sizeof(int));

  for (size_t i = 0; i < m; i++)
  {
    vetor[i] = mat[i][ncoluna];
  }
  return vetor;
}

void imprimeVetor(int *vet, int n)
{
  for (size_t i = 0; i < n; i++)
  {
    printf("\nPosicao[%ld]: %d", i, vet[i]);
  }
  printf("\n");
}

int **realocarMatriz(int **mat, int m, int n)
{
  mat = (int **)calloc(m, sizeof(int *));
  for (int i = 0; i < m; i++)
  {
    mat[i] = (int *)calloc(n, sizeof(int));
  }
  return mat;
}

void **liberaMatriz(int **mat, int m)
{
  for (size_t i = 0; i < m; i++)
  {
    free(mat[i]);
  }
  free(mat);
}