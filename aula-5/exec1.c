#include <stdio.h>
#include <stdlib.h>

typedef struct key
{
    int num;
} Key;

typedef struct tree
{
    struct key *key;
    struct tree *right;
    struct tree *left;
} Tree;

int menu();
Tree *createTree();
Key *createKey();
void insert(Tree **t, Key *k);
void print(Tree *t);
void delete (Tree **t, Key *k);
void Antecessor(Tree *q, Tree **r);
Tree *clear(Tree *t);

int main()
{
    int choice;
    Tree *t = createTree();
    Key *k = NULL;

    for (;;)
    {
        choice = menu();
        switch (choice)
        {
        case 0:
            k = createKey();
            insert(&t, k);
            break;
        case 1:
            k = createKey();
            delete (&t, k);
            break;
        case 2:
            print(t);
            break;
        case 3:
            t = clear(t);
            break;
        case 4:
            clear(t);
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
        printf("\n0 - Insere numero");
        printf("\n1 - Deletar numero");
        printf("\n2 - Listar arvore");
        printf("\n3 - Limpar arvore");
        printf("\n4 - Sair do programa");
        printf("\nEscolha uma opcao: ");
        scanf("%d", &menu);
    } while (menu < 0 || menu > 4);

    return menu;
}

Tree *createTree()
{
    return NULL;
}

Key *createKey()
{
    Key *p = NULL;
    p = (Key *)malloc(sizeof(Key));
    if (p == NULL)
    {
        printf("Sem memoria disponivel!\n");
    }
    printf("Digite um numero: ");
    scanf("%d", &p->num);

    return p;
}

void insert(Tree **t, Key *k)
{
    if (*t == NULL)
    {
        *t = (Tree *)malloc(sizeof(Tree));
        (*t)->left = NULL;
        (*t)->right = NULL;
        (*t)->key = k;
    }
    else
    {
        if (k->num < (*t)->key->num)
        {
            insert(&(*t)->left, k);
        }
        if (k->num > (*t)->key->num)
        {
            insert(&(*t)->right, k);
        }
    }
}

void print(Tree *t)
{
    if (t == NULL)
    {
        printf("\nArvore vazia!\n");
    }
    else
    {
        printf("%d", t->key->num);
        print(t->left);
        print(t->right);
    }
}

void delete (Tree **t, Key *k)
{
    Tree *aux;
    if (*t == NULL)
    {
        printf("Erro : Registro nao esta na arvore\n");
        return;
    }
    if (k->num < (*t)->key->num)
    {
        delete (&(*t)->left, k);
        return;
    }
    if (k->num > (*t)->key->num)
    {
        delete (&(*t)->right, k);
        return;
    }
    if ((*t)->right == NULL)
    {
        aux = *t;
        *t = (*t)->left;
        free(aux);
        return;
    }
    if ((*t)->left != NULL)
    {
        Antecessor(*t, &(*t)->left);
        return;
    }
    if ((*t)->left == NULL)
    {
        aux = *t;
        *t = (*t)->right;
        free(aux);
    }
}

void Antecessor(Tree *q, Tree **r)
{
    Tree *aux;
    if ((*r)->right != NULL)
    {
        Antecessor(q, &(*r)->right);
        return;
    }
    q->key = (*r)->key;
    aux = *r;
    *r = (*r)->left;
    free(aux);
}

Tree *clear(Tree *t)
{
    if (t != NULL)
    {
        clear(t->left);
        clear(t->right);
        free(t);
    }
    return NULL;
}