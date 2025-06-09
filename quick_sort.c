
#include "push_swap.h"

void sort_a_quick(t_stack *a, t_stack *b, int size)
{
    if (size <= 3)
    {
        if (size == 2 && a->arr[0] > a->arr[1])
            sa(a);
        else if (size == 3)
            sort_three(a); 
        return;
    }
    int p_i = a->size / 2;
    int pivot = a->arr[p_i];
    int i = 0, pushed = 0, rotated = 0;

    while (i < size)
    {
        if (a->arr[0] <= pivot)
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
    while (rotated-- > 0)
        rra(a);

    sort_a_quick(a, b, size - pushed);
    sort_b_quick(a, b, pushed);
}

void sort_b_quick(t_stack *a, t_stack *b, int size)
{
    if (size <= 3)
    {
        if (size == 2 && b->arr[0] < b->arr[1])
            sb(b);
        else if (size == 3)
            sort_three_b(b); 
        while (size-- > 0)
            pa(a, b);
        return;
    }
    int p_i = b->size / 2;
    int pivot = b->arr[p_i];
    int i = 0, pushed = 0, rotated = 0;

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
            rotated++;
        }
        i++;
    }
    while (rotated-- > 0)
        rrb(b);

    sort_a_quick(a, b, pushed);
    sort_b_quick(a, b, size - pushed);
}