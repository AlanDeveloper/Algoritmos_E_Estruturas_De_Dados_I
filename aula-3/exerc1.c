#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct
{
  char nome[50];
  int idade;
} Pessoa;

typedef struct
{
  Pessoa *pessoas;
  int topo;
  int base;
  int limite;
} Pilha;

int menu();
Pilha *create();
Pessoa *createPerson();
void push(Pilha *stack, Pessoa *person);
void pop(Pilha *stack, Pessoa *person);
void list(Pilha *stack, Pessoa *person);
void clear(Pilha *stack, Pessoa *person);
void morePersons(Pilha *stack);

int main()
{
  int escolha;
  Pilha *stack = create();
  Pessoa *person = NULL;

  for (;;)
  {
    escolha = menu();
    switch (escolha)
    {
    case 0:
      person = createPerson();
      push(stack, person);
      break;
    case 1:
      pop(stack, person);
      break;
    case 2:
      list(stack, person);
      break;
    case 3:
      clear(stack, person);
      break;
    case 4:
      clear(stack, person);
      free(stack);
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
    printf("\n1 - Deleta pessoa do topo");
    printf("\n2 - Lista pilha");
    printf("\n3 - Limpa a pilha");
    printf("\n4 - Sair do programa");
    printf("\nEscolha uma opcao: ");
    scanf("%d", &menu);
  } while (menu < 0 || menu > 4);

  return menu;
}

Pilha *create()
{
  Pilha *stack = NULL;
  stack = (Pilha *)malloc(sizeof(Pilha));
  if (stack == NULL)
  {
    printf("Sem memoria disponivel!\n");
  }

  stack->pessoas = (Pessoa *)malloc(sizeof(Pessoa));
  stack->topo = 0;
  stack->base = 0;
  stack->limite = 1;
  return stack;
}

Pessoa *createPerson()
{
  Pessoa *person = NULL;
  person = (Pessoa *)malloc(sizeof(Pessoa));
  if (person == NULL)
  {
    printf("Sem memoria disponivel!\n");
  }

  printf("\nDigite seu nome: ");
  scanf("%s", &person->nome);
  printf("Digite sua idade: ");
  scanf("%d", &person->idade);

  return person;
}

void push(Pilha *stack, Pessoa *person)
{
  *(stack->pessoas + stack->topo) = *person;
  stack->topo++;

  if(stack->topo == stack->limite) morePersons(stack);
}

void pop(Pilha *stack, Pessoa *person)
{
  if (stack->topo == 0)
    return;

  stack->topo--;
  person = (stack->pessoas + stack->topo);
  free(person);
}

void list(Pilha *stack, Pessoa *person)
{
  for (size_t i = 0; i < stack->topo; i++)
  {
    person = (stack->pessoas + i);
    printf("\nNome: %s\n", person->nome);
    printf("Idade: %d\n", person->idade);
  }
}

void clear(Pilha *stack, Pessoa *person)
{
  for (size_t i = 0; i < stack->topo; i++)
  {
    person = (stack->pessoas + i);
    free(person);
  }
  stack->topo = 0;
}

void morePersons(Pilha *stack)
{
  stack->limite++;
  stack->pessoas = (Pessoa *)realloc(stack->pessoas, sizeof(Pessoa) * stack->limite);
}