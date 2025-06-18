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

    int pivot = tmp[(size)/ 3]; 

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
    int pivot = tmp[(size * 5)/ 8]; 

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

int find_third_largest_pivot(t_stack *stack, int size)
{
    if (size < 3)
    {
        // 사이즈가 3보다 작으면 그대로 최대값 반환 (예외처리)
        int max = stack->arr[0];
        for (int i = 1; i < size; i++)
        {
            if (stack->arr[i] > max)
                max = stack->arr[i];
        }
        return max;
    }

    int *tmp = malloc(sizeof(int) * size);
    if (!tmp)
        exit(1);

    // 스택의 배열 복사
    for (int i = 0; i < size; i++)
        tmp[i] = stack->arr[i];

    // 단순 버블 정렬 (오름차순)
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (tmp[i] > tmp[j])
            {
                int t = tmp[i];
                tmp[i] = tmp[j];
                tmp[j] = t;
            }
        }
    }

    int pivot = tmp[size - 3];  // 3번째로 큰 값

    free(tmp);
    return pivot;
}
