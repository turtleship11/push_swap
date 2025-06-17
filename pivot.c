#include "push_swap.h"

int find_low_pivot(t_stack *stack, int size)
{
    int *tmp = malloc(sizeof(int) * size);
    if (!tmp)
        exit(1);

    int i = 0;
    while (i < size)
    {
        tmp[i] = stack->arr[i]; 
        i++;
    }

    i = 0;
    while (i < size - 1)
    {
        int j = i + 1;
        while (j < size)
        {
            if (tmp[i] > tmp[j])
            {
                int t = tmp[i];
                tmp[i] = tmp[j];
                tmp[j] = t;
            }
            j++;
        }
        i++;
    }

    int pivot = tmp[size / 4]; 

    free(tmp);
    return pivot;
}

int find_upper_pivot(t_stack *stack, int size)
{
    int *tmp = malloc(sizeof(int) * size);
    if (!tmp)
        exit(1);

    int i = 0;
    while (i < size)
    {
        tmp[i] = stack->arr[i]; 
        i++;
    }

    i = 0;
    while (i < size - 1)
    {
        int j = i + 1;
        while (j < size)
        {
            if (tmp[i] > tmp[j])
            {
                int t = tmp[i];
                tmp[i] = tmp[j];
                tmp[j] = t;
            }
            j++;
        }
        i++;
    }

    int pivot = tmp[(size * 3)/ 4]; 

    free(tmp);
    return pivot;
}


int find_pivot(t_stack *stack, int size)
{
    int *tmp = malloc(sizeof(int) * size);
    if (!tmp)
        exit(1);

    int i = 0;
    while (i < size)
    {
        tmp[i] = stack->arr[i]; 
        i++;
    }

    i = 0;
    while (i < size - 1)
    {
        int j = i + 1;
        while (j < size)
        {
            if (tmp[i] > tmp[j])
            {
                int t = tmp[i];
                tmp[i] = tmp[j];
                tmp[j] = t;
            }
            j++;
        }
        i++;
    }

    int pivot = tmp[size / 2];  // 중간값 (median)

    free(tmp);
    return pivot;
}
