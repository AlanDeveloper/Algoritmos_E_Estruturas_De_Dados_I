#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int menu();
int *init_list(int len);
void fill_list(int *list, int len);
void show_list(int *list, int len);
void merge_sort(int *list, int init, int len);
void merge(int *list, int init, int middle, int len);

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
                merge_sort(list, 0, len);
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

void merge_sort(int *list, int init, int len)
{
    int middle;
    if (init < len)
    {
        middle = floor((init + len) / 2);
        merge_sort(list, init, middle);
        merge_sort(list, middle + 1, len);
        merge(list, init, middle, len);
    }
}

void merge(int *list, int init, int middle, int len)
{
    int *temp, p1, p2, len2, i, j, k;
    int end1 = 0, end2 = 0;
    len2 = len - init + 1;
    p1 = init;
    p2 = middle + 1;
    temp = (int *)malloc(len2 * sizeof(int));
    if (temp != NULL)
    {
        for (i = 0; i < len2; i++)
        {
            if (!end1 && !end2)
            {
                if (list[p1] < list[p2])
                    temp[i] = list[p1++];
                else
                    temp[i] = list[p2++];
                if (p1 > middle)
                    end1 = 1;
                if (p2 > len)
                    end2 = 1;
            }
            else
            {
                if (!end1)
                    temp[i] = list[p1++];
                else
                    temp[i] = list[p2++];
            }
        }
        for (j = 0, k = init; j < len2; j++, k++)
            list[k] = temp[j];
    }
    free(temp);
}