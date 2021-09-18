#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  int cod;
  char nome[40];
  int idade;
} SProduto;

typedef struct STipoFila
{
  SProduto info;
  struct STipoFila *pNext;
} STipoFila;

typedef struct
{
  STipoFila *pFirst;
  STipoFila *pLast;
  int elem;
} SFila;

int menu();
SFila *createQueue();
STipoFila *createProduct(int cod);
SProduto createInfo(int cod);
void push(SFila *queue, STipoFila *product);
void pop(SFila *queue, STipoFila *product);
void list(SFila *queue, STipoFila *product);
void clear(SFila *queue, STipoFila *product);

int main()
{
  int escolha;
  SFila *queue = createQueue();
  STipoFila *product = NULL;

  for (;;)
  {
    escolha = menu();
    switch (escolha)
    {
    case 0:
      product = createProduct(queue->elem);
      push(queue, product);
      break;
    case 1:
      pop(queue, product);
      break;
    case 2:
      list(queue, product);
      break;
    case 3:
      clear(queue, product);
      break;
    case 4:
      clear(queue, product);
      free(queue);
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
    printf("\n0 - Insere pessoa");
    printf("\n1 - Deleta pessoa");
    printf("\n2 - Lista fila");
    printf("\n3 - Limpar fila");
    printf("\n4 - Sair do programa");
    printf("\nEscolha uma opcao: ");
    scanf("%d", &menu);
  } while (menu < 0 || menu > 4);

  return menu;
}

SFila *createQueue()
{
  SFila *queue = NULL;
  queue = (SFila *)malloc(sizeof(SFila));
  if (queue == NULL)
  {
    printf("Sem memoria disponivel!\n");
  }
  queue->pFirst = NULL;
  queue->pLast = NULL;
  queue->elem = 0;

  return queue;
}

STipoFila *createProduct(int cod)
{
  STipoFila *product = NULL;
  product = (STipoFila *)malloc(sizeof(STipoFila));
  if (product == NULL)
  {
    printf("Sem memoria disponivel!\n");
  }
  product->info = createInfo(cod);
  product->pNext = NULL;

  return product;
}

SProduto createInfo(int cod)
{
  SProduto info;

  info.cod = cod;
  printf("\n----DADOS DA PESSOA----");
  printf("\nDigite o nome: ");
  scanf("%s", &info.nome);
  printf("Digite a idade: ");
  scanf("%d", &info.idade);

  return info;
}

void push(SFila *queue, STipoFila *product)
{
  if (queue->pFirst == NULL)
  {
    queue->pFirst = product;
  }
  else
  {
    queue->pLast->pNext = product;
  }
  queue->pLast = product;
  queue->elem++;
}

void pop(SFila *queue, STipoFila *product)
{
  if (queue->pFirst == NULL)
  {
    printf("\nFila vazia!\n");
  }
  else
  {
    product = queue->pFirst;
    queue->pFirst = queue->pFirst->pNext;

    free(product);
  }
}

void list(SFila *queue, STipoFila *product)
{
  product = queue->pFirst;

  printf("\n---------LISTA----------");
  for (; product != NULL; product = product->pNext)
  {
    printf("\nNome: %s", product->info.nome);
    printf("\nIdade: %d", product->info.idade);
  }
  if (queue->pFirst == NULL) {
    printf("\nLista vazia!");
  }
}

void clear(SFila *queue, STipoFila *product) {
  STipoFila *next = NULL;
  product = queue->pFirst;

  for (; product != NULL; product = next)
  {
    next = product->pNext;
    free(product);
  }
  queue->pFirst = NULL;
  queue->pLast = NULL;
}