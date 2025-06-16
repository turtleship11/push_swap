/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeklee <jaeklee@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 14:10:30 by jaeklee           #+#    #+#             */
/*   Updated: 2025/06/06 18:45:52 by jaeklee          ###   ########.fr       */
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
int is_sorted_size(t_stack *stack, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        if (stack->arr[i] > stack->arr[i + 1])
            return 0;
    }
    return 1;
}
int is_sorted_desc(t_stack *b, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        if (b->arr[i] < b->arr[i + 1])
            return 0;
    }
    return 1;
}


void sort_three_a(t_stack *stack)
{
    if (stack->size < 3)
    {
        if (stack->size == 2 && stack->arr[0] > stack->arr[1])
            sa(stack);
        return;
    }
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
    if (a > b_ && b_ > c) // already sorted
        return;
    else if (a > c && c > b_) // a > c > b_
    {
        sb(b);
        rb(b);
    }
    else if (b_ > a && a > c) // b_ > a > c
        sb(b);
    else if (b_ > c && c > a) // b_ > c > a
        rb(b);
    else if (c > a && a > b_) // c > a > b_
        rrb(b);
    else if (c > b_ && b_ > a) // c > b_ > a
    {
        sb(b);
        rrb(b);
    }
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
        if (min_i <= a->size / 2)
        {
            i = 0;
            while (i < min_i)
            {
                ra(a);
                i++;
            }
        }
        else
        {
            i = 0;
            while (i < a->size - min_i)
            {
                rra(a);
                i++;
            }
        }
        pb(a,b);
    }
    sort_three_a(a);
    while(b->size > 0)
        pa(a,b);
}

void sort_first_three_al(t_stack *stack)
{
    if (stack->size < 3)
    {
        if (stack->size == 2 && stack->arr[0] > stack->arr[1])
            sa(stack);
        return;
    }

    int a = stack->arr[0];
    int b = stack->arr[1];
    int c = stack->arr[2];

    if (a > b && b < c && c > a)
        sa(stack);
    else if (a < b && b > c && a > c)
    {
        rra(stack);
        sa(stack);
        ra(stack);
        ra(stack);
    }
    else if (a > b && b > c && a > c)
    {
        sa(stack);
        rra(stack);
        sa(stack);
        ra(stack);
        ra(stack);
    }
    else if (a < b && b > c && a < c)
    {
        sa(stack);
        ra(stack);
        sa(stack);
        rra(stack);
    }
    else if (a > b && b < c && a > c)
        ra(stack);
}
void sort_first_three_bl(t_stack *stack)
{
    if (stack->size < 3)
    {
        if (stack->size == 2 && stack->arr[0] < stack->arr[1])
            sb(stack);
        return;
    }

    int a = stack->arr[0];
    int b = stack->arr[1];
    int c = stack->arr[2];

    if (a < b && b > c && a > c)
        sb(stack);
    else if (a < b && b < c)
    {
        sb(stack);
        rb(stack);
        sb(stack);
        rrb(stack);
    }
    else if (a > b && b < c && a < c)
    {
        rb(stack);
        sb(stack);
        rrb(stack);
    }
    else if (a > b && b < c && a > c)
    {
        sb(stack);
        rb(stack);
        sb(stack);
        rrb(stack);
    }
    else if (a < b && b > c && a < c)
    {
        rb(stack);
        sb(stack);
        rrb(stack);
        sb(stack);
    }
    // else: already sorted (a > b > c)
}
