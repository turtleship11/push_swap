/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeklee <jaeklee@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 14:10:30 by jaeklee           #+#    #+#             */
/*   Updated: 2025/06/09 13:58:58 by jaeklee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_sorted(t_stack *a)
{
	int	i;
	if (a->size <= 1)
		return (1);
	i = 0;
	while (i < a->size - 1)
	{
		if (a->arr[i] > a->arr[i+1])
			return 0;
	i++;
	}
	return (1);
}

void sort_three_a(t_stack *stack)
{
    int a;
    int b;
    int c;
    a = stack->arr[0];
    b = stack->arr[1];
    c = stack->arr[2];
    
    if(a > b && b < c && c > a)
        sa(stack);
    else if (a < b && b > c && a > c)
        rra(stack);
    else if (a > b && b > c && a > c)
    {
        sa(stack);
        rra(stack);
    }
    else if (a < b && b > c && a < c)
    {
        sa(stack);
        ra(stack);
    }
    else if (a > b && b < c && a > c )
        ra(stack);
}

void sort_three_b(t_stack *b)
{
    int a = b->arr[0];
    int b_ = b->arr[1];
    int c = b->arr[2];

    if (a < b_ && b_ > c && a > c)
        sb(b);
    else if (a < b_ && b_ < c)
    {
        sb(b);
        rrb(b);
    }
    else if (a < b_ && b_ > c && a < c)
        rb(b);
    else if (a > b_ && b_ < c && a < c)
    {
        sb(b);
        rb(b);
    }
    else if (a > b_ && b_ < c && a > c)
        rrb(b);
}


int min_num(t_stack *stack)
{
    int min;
    min = stack->arr[0];
    int  i = 1;
    int index;
    index = 0;
    while (i < stack->size)
    {
        if (stack->arr[i] < min)
        {
            min = stack->arr[i];
            index = i;
        }
        i++;
    }
    return (index);
}

void sort_five(t_stack *a, t_stack *b)
{
    int i;
    while (a->size > 3)
    {
        int min_i;
        min_i = min_num(a);
        i = 0;
        while (i < min_i)
        {
            ra(a);
            i++;
        }
        pb(a,b);
    }
    sort_three_a(a);
    while(b->size > 0)
        pa(a,b);
}
