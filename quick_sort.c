#include "push_swap.h"

void reverse_rotate_multiple(t_stack *stack, void (*rr_func)(t_stack *), int times)
{
    while (times-- > 0)
        rr_func(stack);
}


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




void sort_a_quick(t_stack *a, t_stack *b, int size)
{
    if (size == 2 && a->arr[0] > a->arr[1])
    {
        sa(a);
        return;
    }    
    if (size <= 1 || is_sorted_size(a, size))
        return;

    if (size == 3)
    {
        int original_size = a->size;
        a->size = 3;
        sort_three_a(a);
        a->size = original_size;
        return;
    }
    int pivot = find_pivot(a, size);
    // ft_printf("pivot (a) = %i\n", pivot);
    int pushed = 0, rotated = 0;
    int i = 0;
    while (i < size)
    {
        if (a->arr[0] < pivot)
        {
            pb(a, b);
            pushed++;
        }
        else
        {
            ra(a);
            rotated++;
        }
        i++;
    }
    i = 0;
	while(i < a->size)
	{
		// ft_printf("a[%d] = %i\n",i, a->arr[i]);
		i++;
	}
    reverse_rotate_multiple(a, rra, rotated);
if (size - pushed > 0)
    sort_a_quick(a, b, size - pushed);
if (pushed > 0)
    {
    sort_b_quick(a, b, pushed);
    }
}

void sort_b_quick(t_stack *a, t_stack *b, int size)
{
    if (size <= 0)
        return;

    if (size == 1)
    {
        pa(a, b);
        return;
    }
    if (size == 2)
    {
        if (b->arr[0] < b->arr[1])
            sb(b);
        pa(a, b);
        pa(a, b);
        return;
    }
    if (size == 3)
    {
        int original_size = b->size;
        b->size = 3;
        sort_three_b(b);
        b->size = original_size;
        pa(a,b);
        pa(a,b);
        pa(a,b);
        return;
    }
    int pivot = find_pivot(b, size);
    // ft_printf("pivot (b) = %i\n", pivot);
    int i = 0, pushed = 0; int rotate = 0;
    while (i < size)
    {
        if (b->arr[0] >= pivot)
        {
            pa(a, b);
            pushed++;
        }
        else
        {
            rb(b);
            rotate++;
        }
        i++;
    }
    while (rotate-- > 0)
        rrb(b);
    if (pushed > 0)
    {
        sort_a_quick(a, b, pushed);
    }
    if (size - pushed > 0)
        sort_b_quick(a, b, size - pushed);
}


// void sort_three_al(t_stack *stack)
// {
//     if (stack->size < 3)
//     {
//         if (stack->size == 2 && stack->arr[0] > stack->arr[1])
//             sa(stack);
//         return;
//     }
//     int a;
//     int b;
//     int c;
//     a = stack->arr[0];
//     b = stack->arr[1];
//     c = stack->arr[2];
    
//     if(a > b && b < c && c > a)
//     {
//         sa(stack);
//     }
//     else if (a < b && b > c && a > c)
//     {
//         pb(a,b);
//         sa(a);
//         pa(a,b);
//         sa(a);
//     }
//     else if (a > b && b > c && a > c)
//     {
//         pb(a,b);
//         pb(a,b);
//         sb(b);
//         ra(a);
//         pa(a,b);
//         pa(a,b);
//         rra(a);
//     }
//     else if (a < b && b > c && a < c)
//     {
//         ra(a);
//         sa(a);
//         rra(a);
//     }
//     else if (a > b && b < c && a > c )
//     {    
//         ra(stack);
//         pb(a,b);
//         pb(a,b);
//         rra(a);
//         sb(b);
//         pa(a,b);
//         pa(a,b);
//     }
// }

// void sort_three_bl(t_stack *b)
// {
//     int a = b->arr[0];
//     int b_ = b->arr[1];
//     int c = b->arr[2];
//     if (a > b_ && b_ > c) // already sorted
//         return;
//     else if (a > c && c > b_) // a > c > b_
//     {
//         sb(b);
//         rb(b);
//     }
//     else if (b_ > a && a > c) // b_ > a > c
//         sb(b);
//     else if (b_ > c && c > a) // b_ > c > a
//         rb(b);
//     else if (c > a && a > b_) // c > a > b_
//         rrb(b);
//     else if (c > b_ && b_ > a) // c > b_ > a
//     {
//         sb(b);
//         rrb(b);
//     }
// }