
#include "push_swap.h"

void sort_three_a_limited(t_stack *a, t_stack *b)
{
    int x = a->arr[0];
    int y = a->arr[1];
    int z = a->arr[2];

    if (x > y && y > z) // 3 2 1
    {
        sa(a);
        ra(a);
        sa(a);
        rra(a);
        sa(a);
    }
    else if (x > y && y < z && x > z) // 3 1 2
    {
        sa(a);
        ra(a);
        sa(a);
        rra(a);
    }
    else if (x < y && y > z && x > z)
    {
        ra(a);
        sa(a);
        rra(a);
        sa(a);
    }
    else if (x > y && y < z && x < z)
    {
        if (b->arr[0] < b->arr[1])
            ss(a,b);
        else
            sa(a);
    }
    else if (x < y && y > z && x < z) // 1 3 2
    {
        ra(a);
        sa(a);
        rra(a);
    }
}

void sort_three_b_limited(t_stack *a, t_stack *b)
{
    int a1 = b->arr[0];
    int b1 = b->arr[1];
    int c = b->arr[2];

    if (a1 < b1 && b1 < c) 
    {
        rb(b);
        sb(b);
        pa(a,b);      
        pa(a,b);          
        rrb(b);
        pa(a,b);
    }
    else if (a1 < b1 && b1 > c && a1 < c) // 1 3 2
    {
        sb(b);
        pa(a,b);
        sb(b);
        pa(a,b);
        pa(a,b);
    }
    else if (a1 > b1 && b1 < c && a1 < c) // 2 1 3
    {
        rb(b);
        sb(b);
        pa(a,b);        
        rrb(b);
        pa(a,b);
        pa(a,b);
    }
    else if (a1 < b1 && b1 > c && a1 > c) // 2 3 1
    {
        sb(b);
        pa(a,b);
        pa(a,b);
        pa(a,b);
    
    }
    else if (a1 > b1 && b1 > c) // 3 2 1 
    {
        pa(a,b);
        pa(a,b);
        pa(a,b);
    }
    else if (a1 > b1 && b1 < c && a1 > c) // 3 1 2
    {
        pa(a,b);
        sb(b);
        pa(a,b);
        pa(a,b);
    }
}