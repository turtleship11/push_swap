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
