#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct No
{
    int conteudo;
    struct No *prox;
} No;

int menu();
void *create_List();
void insert_elem(No *head);
void print_elem(No *head);
void delete_elem(No *head);
No *clear_list(No *head);

int main()
{
    int choice;
    No *head = create_List();

    for (;;)
    {
        choice = menu();
        switch (choice)
        {
        case 0:
            insert_elem(head);
            break;
        case 1:
            delete_elem(head);
            break;
        case 2:
            print_elem(head);
            break;
        case 3:
            head = clear_list(head);
            break;
        case 4:
            clear_list(head);
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
        printf("\n0 - Inserir elemento");
        printf("\n1 - Deletar elemento");
        printf("\n2 - Listar elementos");
        printf("\n3 - Limpar lista");
        printf("\n4 - Sair do programa");
        printf("\nEscolha uma opcao: ");
        scanf("%d", &menu);
    } while (menu < 0 || menu > 4);

    return menu;
}

void *create_List()
{
    No *p = NULL;
    p = (No *)malloc(sizeof(No));
    if (p == NULL)
    {
        printf("Sem memoria disponivel!\n");
    }
    p->prox = NULL;
    return p;
}

void insert_elem(No *head) {
    No *new = NULL;
    new = (No *)(malloc(sizeof(No)));

    printf("\nDigite um numero: ");
    scanf("%d", &new->conteudo);

    new->prox = head->prox;
    head->prox = new;
}

void print_elem(No *head) {
    No *p = NULL;
    int i = 0;

    printf("\n");
    for (p = head->prox; p != NULL; p = p->prox, i++)
    {
        printf("Registro %d | Valor: %d\n", i, p->conteudo);
    }
    if (head->prox == NULL) {
        printf("\nLista vazia!\n");
    }
}

void delete_elem(No *head) {
    No *p = NULL;
    int n;
    bool found = false;

    printf("\nValor a ser deletado: ");
    scanf("%d", &n);

    for (p = head; p != NULL; p = p->prox)
    {
        if (p->prox)
        {
            if (p->prox->conteudo == n)
            {
                found = true;
                p->prox = p->prox->prox;
                printf("\nValor deletado!");
            }
        }
    }

    if (!found)
    {
        printf("\nValor nao encontrado!");
    }
    printf("\n");
}

No *clear_list(No *head) {
    No *p = NULL, *aux = NULL;

    for (p = head->prox; aux != NULL; p = aux)
    {
        aux = p->prox;
        free(p);
    }
    head->prox = NULL;
    return head;
}