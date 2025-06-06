/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeklee <jaeklee@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 14:25:35 by jaeklee           #+#    #+#             */
/*   Updated: 2025/06/06 17:56:09 by jaeklee          ###   ########.fr       */
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
	ft_printf("sa\n");
}
void sb(t_stack *b)
{
	if(b->size < 2)
		return;
	int temp = b->arr[0];
	b->arr[0] = b->arr[1];
	b->arr[1] = temp;
	ft_printf("sb\n");		
}
void ss(t_stack *a, t_stack *b)
{
	int temp1;
	int temp2;
	if(a->size < 2)
		return;
	if(b->size < 2)
		return;
	int temp1 = a-> arr[0];
	a-> arr[0] = a-> arr[1];
	a-> arr[1] = temp1;
	int temp2 = b->arr[0];
	b->arr[0] = b->arr[1];
	b->arr[1] = temp2;
	ft_printf("ss\n");
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
	ft_printf("pa\n");
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
	ft_printf("pb\n");
}

void ra(t_stack *a)
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
	ft_printf("ra\n");
}
void rb(t_stack *b)
{
	int temp;
	temp = b->arr[0];
	int i;
	i = 0;
	while (i < b->size -1)
	{
		b->arr[i] = b->arr[i+1];
		i++;
	}
	b->arr[b->size-1] = temp;
	ft_printf("rb\n");
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
	ft_printf("rr\n");	
}
void rra(t_stack *a)
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
	ft_printf("rra\n");
}
void rrb(t_stack *b)
{
	if (b->size > 1)
	{
		int temp;
		int i;
		temp = b->arr[b->size-1];
		i = b->size -1;
		while(i > 0)
		{
			b->arr[i] = b->arr[i -1];
			i--;
		}
		b->arr[0] = temp;
	}
	ft_printf("rra\n");
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
	ft_printf("rrr\n");
}
