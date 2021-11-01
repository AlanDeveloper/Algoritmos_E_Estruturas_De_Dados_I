#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <time.h>

int menu();
int *init_list(int len);
void fill_list(int *list, int len);
void show_list(int *list, int len);
void quick_sort(int *list, int left, int right);

int main()
{
    int choice, *list = NULL, len;

    for (;;)
    {
        choice = menu();
        switch (choice)
        {
        case 0:
            if (list == NULL)
            {
                printf("Digite o tamanho: ");
                scanf("%d", &len);
                list = init_list(len);
                fill_list(list, len);
            }
            else
            {
                printf("\nLista ja iniciada!\n");
            }
            break;
        case 1:
            if (list != NULL)
            {
                quick_sort(list, 0, len);
            }
            else
            {
                printf("\nCrie uma lista!\n");
            }
            break;
        case 2:
            if (list != NULL)
            {
                show_list(list, len);
            }
            else
            {
                printf("\nCrie uma lista!\n");
            }
            break;
        case 3:
            if (list != NULL)
            {
                free(list);
                list = NULL;
            }
            break;
        case 4:
            if (list != NULL)
            {
                free(list);
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
        printf("\n0 - Criar lista");
        printf("\n1 - Ordenar lista");
        printf("\n2 - Listar lista");
        printf("\n3 - Limpar lista");
        printf("\n4 - Sair do programa");
        printf("\nEscolha uma opcao: ");
        scanf("%d", &menu);
    } while (menu < 0 || menu > 4);

    return menu;
}

int *init_list(int len)
{
    int *list = NULL;
    list = (int *)malloc(sizeof(int) * len);

    if (list == NULL)
    {
        printf("Nao foi possivel alocar memoria!");
        exit(1);
    }
    return list;
}

void fill_list(int *list, int len)
{
    srand(time(NULL));
    for (size_t i = 0; i < len; i++)
    {
        list[i] = rand();
    }
}

void show_list(int *list, int len)
{
    printf("\n");
    for (size_t i = 0; i < len; i++)
    {
        printf("%d: %d\n", i, list[i]);
    }
}

void quick_sort(int *list, int left, int right)
{
    int mid, tmp, i, j;
    i = left;
    j = right;
    mid = list[(left + right) / 2];
    do
    {
        while (list[i] < mid)
            i++;
        while (mid < list[j])
            j--;
        if (i <= j)
        {
            tmp = list[i];
            list[i] = list[j];
            list[j] = tmp;
            i++;
            j--;
        }
    } while (i <= j);
    if (left < j)
    {
        quick_sort(list, left, j);
    }
    if (i < right)
    {
        quick_sort(list, i, right);
    }
}