#include "push_swap.h"



int check_a(t_stack *a, t_stack *b, int size)
{
    if (size == 2 && a->arr[0] > a->arr[1])
    {
        if (b->arr[0] < b->arr[1])
            ss(a,b);
        else
            sa(a);
        return(1);
    }    
    if (size <= 1 || is_sorted_size(a, size))
        return(1);

    if (a->size == 3)
    {
        sort_three_a(a);
        return(1);
    }
    if (size <= 3) 
    {
        sort_three_a_limited(a,b);
        return(1);
    }
    if (size == 4)
    {
        sort_four_a(a,b);
        return(1);
    }
    return 0;
}

int check_b(t_stack *a, t_stack *b, int size)
{
    if (size <= 0)
        return(1);
    if (is_sorted_desc(b,size))
    {
        while (size-- > 0)
            pa(a, b);
        return(1);
    }
    if (size == 1)
    {
        pa(a, b);
        return(1);
    }
    if (size == 2)
    {
        if (b->arr[0] < b->arr[1])
            sb(b);
        pa(a, b);
        pa(a, b);
        return(1);
    }
    if (b->size == 3 && size == 3)
    {
        sort_three_b(b);
        pa(a,b);
        pa(a,b);
        pa(a,b);
        return(1);
    }
    if (size == 3)
    {
        sort_three_b_limited(a,b);
        return(1);
    }
    if (size == 4)
    {
        sort_four_b(a,b);
        return(1);
    }
    return (0);
}

void sort_a_quick(t_stack *a, t_stack *b, int size)
{
    if (check_a(a,b,size) == 1)
        return;
    int pivot;
    pivot = find_upper_pivot(a, size);
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
    reverse_rotate_multiple(a, rra, rotated);    
    if (size - pushed > 0)
        sort_a_quick(a, b, size - pushed);
    if (pushed > 0)
        sort_b_quick(a, b, pushed);
}

void sort_b_quick(t_stack *a, t_stack *b, int size)
{
    if (check_b(a,b,size)== 1)
        return;
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
        sort_a_quick(a, b, pushed);
    if (size - pushed > 0)
        sort_b_quick(a, b, size - pushed);
}


void sort_first(t_stack *a, t_stack *b, int size)
{
    int up_pi = find_upper_pivot(a,size);
    int lo_pi = find_low_pivot(a,size);
    int upper = 0, low = 0;
    int i = 0;
    while (i < size)
    {
        if (a->arr[0] <= lo_pi)
        {
            pb(a, b);
            rb(b);
            low++;
        }
        else if (a->arr[0] < up_pi)
        {
            pb(a,b);
            upper++;
        }
        else
            ra(a);
        i++;
    }
    if (size - (upper + low) > 0)
        sort_a_norra(a, b, size - (upper + low));
    if (upper > 0)
        sort_b_quick(a, b, upper);
    if (low > 0)
        sort_b_norrb(a,b, low);
}

void sort_a_norra(t_stack *a, t_stack *b, int size)
{
    if (check_a(a,b,size) == 1)
        return;
    int pivot;
    pivot = find_pivot(a, size);
    int pushed = 0;
    int i = 0;
    while (i < size)
    {
        if (a->arr[0] < pivot)
        {
            pb(a, b);
            pushed++;
        }
        else
            ra(a);
        i++;
    }
    if (size - pushed > 0)
    sort_a_norra(a, b, size - pushed);
    if (pushed > 0)
    sort_b_quick(a, b, pushed);
}

void sort_b_norrb(t_stack *a, t_stack *b, int size)
{
    if (check_b(a,b,size)== 1)
        return;
    int pivot = find_upper_pivot(b, size);
    int i = 0, pushed = 0;
    while (i < size)
    {
        if (b->arr[0] >= pivot)
        {
            pa(a, b);
            pushed++;
        }
        else
            rb(b);
        i++;
    }
    if (pushed > 0)
        sort_a_quick(a, b, pushed);
    if (size - pushed > 0)
        sort_b_norrb(a, b, size - pushed);
}

void sort_four_a(t_stack *a, t_stack *b)
{
    int min_index = find_min_index(a, 4);
    int count = 0;
    if (min_index == 1)
        sa(a);
    else if (min_index == 2)
    {
        ra(a);
        count++;        
        sa(a);
    }
    else if (min_index == 3)
    {
        ra(a);
        count++;
        ra(a);
        count++; 
        sa(a);
    }
    pb(a, b);
    while (count--> 0)
        rra(a);
    sort_three_a_limited(a,b);
    pa(a, b);
}

int find_min_index(t_stack *a, int size)
{
    int min = a->arr[0];
    int idx = 0;
    for (int i = 1; i < size; i++)
    {
        if (a->arr[i] < min)
        {
            min = a->arr[i];
            idx = i;
        }
    }
    return idx;
}

void sort_four_b(t_stack *a, t_stack *b)
{
    int max_index = find_max_index(b, 4); 
    int count = 0;

    if (max_index == 1)
        sb(b);
    else if (max_index == 2)
    {
        rb(b);
        count++;
        sb(b);
    }
    else if (max_index == 3)
    {
        rb(b);
        count++;
        rb(b);
        count++;
        sb(b);
    }
    pa(a, b); 
    while(count --> 0)
        rrb(b);
    sort_three_b_limited(a, b);
}

int find_max_index(t_stack *b, int size)
{
    int max = b->arr[0];
    int idx = 0;
    for (int i = 1; i < size; i++)
    {
        if (b->arr[i] > max)
        {
            max = b->arr[i];
            idx = i;
        }
    }
    return idx;
}
