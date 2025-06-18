/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeklee <jaeklee@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 14:25:35 by jaeklee           #+#    #+#             */
/*   Updated: 2025/06/06 19:04:12 by jaeklee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sa(t_stack *a)
{
	if(a->size < 2)
		return;
	int temp = a-> arr[0];
	a-> arr[0] = a-> arr[1];
	a-> arr[1] = temp;
    write(1, "sa\n", 3);
}
void sb(t_stack *b)
{
	if(b->size < 2)
		return;
	int temp = b->arr[0];
	b->arr[0] = b->arr[1];
	b->arr[1] = temp;
    write(1, "sb\n", 3);
}
void ss(t_stack *a, t_stack *b)
{
    if (a->size >= 2)
    {
        int temp1 = a->arr[0];
        a->arr[0] = a->arr[1];
        a->arr[1] = temp1;
    }
    if (b->size >= 2)
    {
        int temp2 = b->arr[0];
        b->arr[0] = b->arr[1];
        b->arr[1] = temp2;
    }
    write(1, "ss\n", 3);
}

void pa(t_stack *a, t_stack *b)
{
	if (b-> size == 0)
		return;
	int i;
	int temp;	
	i = 0;
	temp = b->arr[0];
	while(i < b->size -1)
	{
		b->arr[i] = b->arr[i +1];
		i++;
	}
	i = a->size;
	while (i > 0)
	{
		a->arr[i] = a->arr[i -1];
		i--;
	}
	a->arr[0] = temp;
	a->size++;
	b->size--;
    write(1, "pa\n", 3);
}

void pb(t_stack *a, t_stack *b)
{
	if (a-> size == 0)
		return;
	int temp;
	int i;
	temp = a->arr[0];
	i = 0;
	while (i < a->size -1)
	{
		a->arr[i] = a->arr[i + 1];
		i++;
	}
	i = b->size;
	while (i > 0)
	{
		b->arr[i] = b->arr[i -1];
		i--;
	}
	b->arr[0] = temp;
	b->size++;
	a->size--;
    write(1, "pb\n", 3);
}

void ra(t_stack *a)
{
    if (a->size < 2)
        return;

    int temp = a->arr[0];
	int i;
	i = 0;
	while(i < a->size - 1)
	{
		a->arr[i] = a->arr[i +1];
		i++;
	}
	a->arr[a->size -1] = temp;
    write(1, "ra\n", 3);
}

void rb(t_stack *b)
{
    if (b->size < 2) 
        return;

    int temp = b->arr[0];
    int i = 0;

    while (i < b->size - 1)
    {
        b->arr[i] = b->arr[i + 1];
        i++;
    }
    b->arr[b->size - 1] = temp;
    write(1, "rb\n", 3);
}

void rr(t_stack *a,t_stack *b)
{
	int temp;
	temp = a->arr[0];
	int i;
	i = 0;
	while (i < a->size -1)
	{
		a->arr[i] = a->arr[i+1];
		i++;
	}
	a->arr[a->size-1] = temp;
	int temp1;
	temp1 = b->arr[0];
	int j;
	j = 0;
	while (j < b->size -1)
	{
		b->arr[j] = b->arr[j+1];
		j++;
	}
	b->arr[b->size-1] = temp1;	
    write(1, "rr\n", 3);
}
void rra(t_stack *a)
{
    if (a->size < 2)
        return;

    int temp = a->arr[a->size - 1];
    for (int i = a->size - 1; i > 0; i--)
        a->arr[i] = a->arr[i - 1];
    a->arr[0] = temp;
    write(1, "rra\n", 4);
}

void rrb(t_stack *b)
{
    if (b->size < 2)
        return;

    int temp = b->arr[b->size - 1];
    for (int i = b->size - 1; i > 0; i--)
        b->arr[i] = b->arr[i - 1];
    b->arr[0] = temp;
    write(1, "rrb\n", 4);
}


void rrr(t_stack *a,t_stack *b)
{
	if (a->size > 1)
	{
		int temp;
		int i;
		temp = a->arr[a->size-1];
		i = a->size -1;
		while(i > 0)
		{
			a->arr[i] = a->arr[i -1];
			i--;
		}
		a->arr[0] = temp;
	}
	if (b->size > 1)
	{
		int temp1;
		int j;
		temp1 = b->arr[b->size-1];
		j = b->size -1;
		while(j > 0)
		{
			b->arr[j] = b->arr[j -1];
			j--;
		}
		b->arr[0] = temp1;
	}
    write(1, "rrr\n", 4);
}
