#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct
{
  char nome[30];
  int idade;
  int altura;
} Pessoa;

int menu();
Pessoa *cria_lista();
int livre(Pessoa *lista);
void inserir(Pessoa *lista);
void listar(Pessoa *lista);
void deletar(Pessoa *lista);

int main()
{
  int escolha;
  Pessoa *lista = cria_lista();

  for (;;)
  {
    escolha = menu();
    switch (escolha)
    {
    case 1:
      inserir(lista);
      break;
    case 2:
      listar(lista);
      break;
    case 3:
      deletar(lista);
      break;
    case 4:
      exit(0);
      break;
    }
  }
  free(lista);

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
  Pessoa *lista = NULL;
  lista = (Pessoa *)(malloc(sizeof(Pessoa)));

  if (lista == NULL)
  {
    printf("Nao foi possivel alocar memoria!");
    exit(1);
  }
  strcpy(lista->nome, "\0");

  return lista;
}

int livre(Pessoa *lista)
{
  int i;
  for (i = 0; strcmp((lista + i)->nome, "\0") != 0; i++)
    ;
  return i;
}

void inserir(Pessoa *lista)
{
  int i = livre(lista);

  printf("\nDigite seu nome: ");
  scanf("%s", &(lista + i)->nome);
  printf("Digite sua idade: ");
  scanf("%d", &(lista + i)->idade);
  printf("Digite sua altura: ");
  scanf("%d", &(lista + i)->altura);

  i++;
  lista = (Pessoa *)(realloc(lista, sizeof(Pessoa) * (i + 1)));
  strcpy((lista + i)->nome, "\0");
}

void listar(Pessoa *lista)
{
  for (size_t i = 0; strcmp((lista + i)->nome, "\0") != 0; i++)
  {
    printf("\nNome: %s", (lista + i)->nome);
    printf("\nIdade: %d", (lista + i)->idade);
    printf("\nAltura: %d", (lista + i)->altura);
  }
}

void deletar(Pessoa *lista)
{
  char nome[30];
  bool encontrado = false;

  printf("Digite um nome: ");
  scanf("%s", &nome);
  for (size_t i = 0; strcmp((lista + i)->nome, "\0") != 0; i++)
  {
    if (strcmp((lista + i)->nome, nome) == 0)
    {
      for (size_t j = i; strcmp((lista + j)->nome, "\0") != 0; j++)
      {
        strcpy((lista + j)->nome, (lista + j + 1)->nome);
        (lista + j)->idade = (lista + j + 1)->idade;
        (lista + j)->altura = (lista + j + 1)->altura;
      }
      encontrado = true;
      printf("\nUsuário deletado!");
    }
  }

  if (!encontrado)
  {
    printf("\nUsuário não encontrado!");
  }
}