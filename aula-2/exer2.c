#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Pessoa
{
  char nome[30];
  int idade;
  int altura;
  struct Pessoa *prox;
} Pessoa;

int menu();
Pessoa *cria_lista();
void insere(Pessoa *head);
void listar(Pessoa *head);
void deletar(Pessoa *head);

int main()
{
  Pessoa *head = NULL;
  int escolha;

  head = cria_lista();
  for (;;)
  {
    escolha = menu();
    switch (escolha)
    {
    case 1:
      insere(head);
      break;
    case 2:
      listar(head);
      break;
    case 3:
      deletar(head);
      break;
    case 4:
      while (head != NULL)
      {
        Pessoa *del = head;
        head = head->prox;
        free(del);
      }
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
    printf("\n1 - Inserir novo usuario");
    printf("\n2 - Listar usuarios");
    printf("\n3 - Deletar usuario");
    printf("\n4 - Sair ");
    printf("\nEscolha uma opcao: ");
    scanf("%d", &menu);
  } while (menu <= 0 || menu > 4);

  return menu;
}

Pessoa *cria_lista()
{
  Pessoa *novo = NULL;
  novo = (Pessoa *)(malloc(sizeof(Pessoa)));
  if (novo == NULL)
  {
    printf("Nao foi possivel alocar memoria!");
    exit(1);
  }
  novo->prox = NULL;

  return novo;
}

void insere(Pessoa *head)
{
  Pessoa *novo = NULL;

  novo = (Pessoa *)(malloc(sizeof(Pessoa)));

  printf("\n------NOVO USUARIO------");
  printf("\nDigite seu nome: ");
  scanf("%s", &novo->nome);
  printf("Digite sua idade: ");
  scanf("%d", &novo->idade);
  printf("Digite sua altura: ");
  scanf("%d", &novo->altura);

  novo->prox = head->prox;
  head->prox = novo;
}

void listar(Pessoa *head)
{
  Pessoa *elem = NULL;

  printf("\n----LISTA DE USUARIOS---");
  for (elem = head->prox; elem != NULL; elem = elem->prox)
  {
    printf("\nNome: %s", elem->nome);
    printf("\nIdade: %d", elem->idade);
    printf("\nAltura: %d", elem->altura);
    printf("\n");
  }
}

void deletar(Pessoa *head)
{
  Pessoa *elem = NULL;
  char nome[30];
  bool encontrado = false;

  printf("\n----DELETAR USUARIO-----");
  printf("\nDigite um nome: ");
  scanf("%s", &nome);

  for (elem = head; elem != NULL; elem = elem->prox)
  {
    if (elem->prox)
    {
      if (strcmp(elem->prox->nome, nome) == 0)
      {
        encontrado = true;
        elem->prox = elem->prox->prox;
        printf("\nUsuario deletado!");
      }
    }
  }

  if (!encontrado)
  {
    printf("\nUsuario nao encontrado!");
  }
  printf("\n");
}