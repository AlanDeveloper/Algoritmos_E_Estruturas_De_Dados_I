#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
  char nome[50];
  int idade;
} SDado;

typedef struct SNodo
{
  SDado *info;
  struct SNodo *pNext;
} SNodo;

typedef struct
{
  SNodo *pFirst;
} SLista;

int menu();
SLista *createList();
SNodo *createNodo();
SDado *createDado();
int push(SLista *list, SNodo *nodo, unsigned int nIndex);
int pop(SLista *list, SNodo *nodo, unsigned int nIndex);
int popName(SLista *list, SNodo *nodo, char *name);
void print(SLista *list, SNodo *nodo);
void clear(SLista *list, SNodo *nodo);

int main()
{
  char name[50];
  int choice, pos;
  SLista *list = createList();
  SNodo *nodo = NULL;

  for (;;)
  {
    choice = menu();
    switch (choice)
    {
    case 0:
      printf("\nInforme a posicao: ");
      scanf("%d", &pos);

      nodo = createNodo();
      push(list, nodo, pos);
      break;
    case 1:
      printf("\nInforme a posicao: ");
      scanf("%d", &pos);

      pop(list, nodo, pos);
      break;
    case 2:
      printf("\nDigite seu nome: ");
      scanf("%s", &name);

      popName(list, nodo, name);
      break;
    case 3:
      print(list, nodo);
      break;
    case 4:
      clear(list, nodo);
      break;
    case 5:
      clear(list, nodo);
      free(list);
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
    printf("\n2 - Deleta pessoa por nome");
    printf("\n3 - Imprime toda a lista");
    printf("\n4 - Limpa a lista");
    printf("\n5 - Sair do programa");
    printf("\nEscolha uma opcao: ");
    scanf("%d", &menu);
  } while (menu < 0 || menu > 5);

  return menu;
}

SLista *createList()
{
  SLista *list = NULL;
  list = (SLista *)malloc(sizeof(SLista));
  if (list == NULL)
  {
    printf("Sem memoria disponivel!\n");
  }
  list->pFirst = NULL;

  return list;
}

SNodo *createNodo()
{
  SNodo *nodo = NULL;
  nodo = (SNodo *)malloc(sizeof(SNodo));
  if (nodo == NULL)
  {
    printf("Sem memoria disponivel!\n");
  }
  nodo->info = createDado();

  return nodo;
}

SDado *createDado()
{
  SDado *dado = NULL;
  dado = (SDado *)malloc(sizeof(SDado));
  if (dado == NULL)
  {
    printf("Sem memoria disponivel!\n");
  }
  printf("\nDigite seu nome: ");
  scanf("%s", &dado->nome);
  printf("Digite sua idade: ");
  scanf("%d", &dado->idade);

  return dado;
}

int push(SLista *list, SNodo *nodo, unsigned int nIndex)
{
  SNodo *pAtual = NULL, *pAnterior = NULL;

  if (list->pFirst == NULL && nIndex != 0)
  {
    return 0;
  }
  else if (list->pFirst == NULL && nIndex == 0)
  {
    list->pFirst = nodo;
    list->pFirst->pNext = NULL;
    return 1;
  }
  else if (nIndex == 0)
  {
    nodo->pNext = list->pFirst;
    list->pFirst = nodo;
    return 1;
  }
  pAtual = list->pFirst;
  for (int nPos = 0; nPos < nIndex && pAtual != NULL; nPos++)
  {
    pAnterior = pAtual;
    pAtual = pAtual->pNext;
  }

  if (!pAtual)
    return 0;

  nodo->pNext = pAtual;
  pAnterior->pNext = nodo;
  return 1;
}

int pop(SLista *list, SNodo *nodo, unsigned int nIndex)
{
  SNodo *pAnterior = NULL, *pAtual = NULL;
  if (list->pFirst == NULL)
    return 0;
  if (nIndex == 0)
  {
    nodo = list->pFirst;
    list->pFirst = list->pFirst->pNext;
    return 1;
  }

  pAtual = list->pFirst;
  for (int nPos = 0; nPos < nIndex && pAtual != NULL; nPos++)
  {
    pAnterior = pAtual;
    pAtual = pAtual->pNext;
  }

  if (!pAtual)
    return 0;

  pAnterior->pNext = pAtual->pNext;
  nodo = pAtual;

  return 1;
}

int popName(SLista *list, SNodo *nodo, char *name)
{
  SNodo *pAnterior = NULL, *pAtual = NULL;


  if (!list->pFirst)
    return 0;

  if (strcmp(list->pFirst->info->nome, name) == 0 && list->pFirst->pNext != NULL) {
    list->pFirst = list->pFirst->pNext;
    return 1;
  } else if (strcmp(list->pFirst->info->nome, name) == 0) {
    list->pFirst = NULL;
    return 1;
  }

  pAtual = list->pFirst;
  for (; pAtual != NULL && !strcmp(pAtual->info->nome, name) == 0;)
  {
    pAnterior = pAtual;
    pAtual = pAtual->pNext;
  }

   if (!pAtual)
    return 0;

  pAnterior->pNext = pAtual->pNext;
  nodo = pAtual;

  return 1;
}

void print(SLista *list, SNodo *nodo)
{
  SDado *dado = NULL;
  nodo = list->pFirst;

  for (; nodo != NULL;)
  {
    dado = nodo->info;
    printf("\nNome: %s", dado->nome);
    printf("\nIdade: %d\n", dado->idade);
    nodo = nodo->pNext;
  }
}

void clear(SLista *list, SNodo *nodo) {
  SNodo *next = NULL;
  nodo = list->pFirst;

  for (; nodo != NULL;)
  {
    next = nodo->pNext;
    free(nodo->info);
    free(nodo);
    nodo = next;
  }
  list->pFirst = NULL;
}