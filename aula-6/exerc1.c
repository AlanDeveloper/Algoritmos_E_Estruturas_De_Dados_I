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
int insert(Tree **t, Key *k);
void print(Tree *t);
void delete (Tree **t, Key *k);
void Antecessor(Tree *q, Tree **r);
Tree *clear(Tree *t);
int FB(Tree *t);
void RSE(Tree **t);
void RSD(Tree **t);
int balancing(Tree **t);
int balancingLeft(Tree **t);
int balancingRight(Tree **t);
int height(Tree *t);
int EhArvoreArvl(Tree *t);

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
            if (EhArvoreArvl(t)) {
                printf("\nE arvore AVL\n");
            } else {
                printf("\nNao e arvore AVL\n");
            }
            break;
        case 5:
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
        printf("\n4 - Verificar se e arvore");
        printf("\n5 - Sair do programa");
        printf("\nEscolha uma opcao: ");
        scanf("%d", &menu);
    } while (menu < 0 || menu > 5);

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

int insert(Tree **t, Key *k)
{
    if (*t == NULL)
    {
        *t = (Tree *)malloc(sizeof(Tree));
        (*t)->left = NULL;
        (*t)->right = NULL;
        (*t)->key = k;
        return 1;
    }
    else if (k->num < (*t)->key->num)
    {
        if (insert(&(*t)->left, k))
        {
            if (balancing(t))
            {
                return 0;
            }
            else
            {
                return 1;
            }
        }
    }
    else if (k->num > (*t)->key->num)
    {
        if (insert(&(*t)->right, k))
        {
            if (balancing(t))
            {
                return 0;
            }
            else
            {
                return 1;
            }
        }
    }
    else
    {
        return 0;
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

int FB(Tree *t)
{
    if (t == NULL)
    {
        return 0;
    }
    return height(t->left) - height(t->right);
}

int height(Tree *t)
{
    int left, right;
    if (t == NULL)
    {
        return 0;
    }

    left = height(t->left);
    right = height(t->right);

    if (left > right)
    {
        return left + 1;
    }
    else
    {
        return right + 1;
    }
}

void RSE(Tree **t)
{
    Tree *aux;
    aux = (*t)->right;
    (*t)->right = aux->left;
    aux->left = (*t);
    (*t) = aux;
}

void RSD(Tree **t)
{
    Tree *aux;
    aux = (*t)->left;
    (*t)->left = aux->right;
    aux->right = (*t);
    (*t) = aux;
}

int balancing(Tree **t)
{
    int fb = FB(*t);
    if (fb > 1)
    {
        return balancingLeft(t);
    }
    else if (fb < -1)
    {
        return balancingRight(t);
    }
    else
    {
        return 0;
    }
}

int balancingLeft(Tree **t)
{
    int fbe = FB((*t)->left);
    if (fbe > 0)
    {
        RSD(t);
        return 1;
    }
    else if (fbe < 0)
    {
        RSE(&((*t)->left));
        RSD(t);
        return 1;
    }
    return 0;
}

int balancingRight(Tree **t)
{
    int fbd = FB((*t)->right);
    if (fbd < 0)
    {
        RSE(t);
        return 1;
    }
    else if (fbd > 0)
    {
        RSD(&((*t)->right));
        RSE(t);
        return 1;
    }
    return 0;
}

int EhArvoreArvl(Tree *t)
{
    int fb;
    if (t == NULL)
    {
        return 1;
    }
    if (!EhArvoreArvl(t->left))
    {
        return 0;
    }
    if (!EhArvoreArvl(t->right))
    {
        return 0;
    }
    fb = FB(t);
    if ((fb > 1) || (fb < -1))
    {
        return 0;
    }
    else
    {
        return 1;
    }
}