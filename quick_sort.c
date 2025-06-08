#include "push_swap.h"

void sort_a(t_stack *a, t_stack *b, int size)


void sort_ab(t_stack *a, t_stack *b)
{
    int pivet;
    int size = a->size;
    pivet = a->arr[0];
    int i;
    i = 0;
    int rotate;
    rotate = 0;
    while(i < size)
    {
        if(pivet < a->arr[0])
            pb(a,b);
        else
        { 
            ra(a);
            rotate++;
        }
    i++;
    }
    while (rotate-- > 0)
        rra(a);
}