/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeklee <jaeklee@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 15:17:05 by jaeklee           #+#    #+#             */
/*   Updated: 2025/06/06 19:01:55 by jaeklee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int count_word(char *s)
{
	int i = 0;
	int count = 0;
	int word = 0;
	while (s[i] == ' ')
		i++;
	while (s[i] != '\0')
	{
		if ((s[i] >= '0' && s[i] <= '9') && word == 0)
		{
			word = 1;
			count++;
		}
		if (s[i] == ' ' || s[i] == '\t')
			word = 0;
		i++;
	}
	return (count);
	
}
int check_n(int *num, int size)
{
	int i;
	int	j;
	i = 0;
	while (i < size  -1)
	{
		j = 0;
		while(j < size)
		{
			if (i != j && num[i] == num[j])
				return 0;
		j++;
		}
	i++;
	}
	return (1);
}
int main (int ac, char **av)
{
	if (ac != 2)
		{
			ft_printf("error\n");
			return 0;
		}
	int word_count = count_word(av[1]);
	ft_printf("word_c : %i\n", word_count);	
	char **temp;
	temp = ft_split(av[1]);
	if (!temp)
		return 0;
	int ctoi;
	int *n_array;
	n_array = malloc(sizeof(int) * word_count);
	int i = 0;
	while (temp[i] != NULL)
	{
		ctoi = ft_atoi(temp[i]);
		n_array[i] = ctoi;
		ft_printf("%i\n",n_array[i]);		
		i++;
	}
	if (check_n(n_array, word_count) == 0)
	{
		ft_printf("Error: duplicate found\n");
		free(n_array);
		return 0;		
	}
	
	t_stack stack_a;
	stack_a.arr = malloc(sizeof(int) * word_count);

	if (!stack_a.arr)
		return 0;
	stack_a.size = word_count;
	
	i = 0;
	while (i < word_count)

	{
		stack_a.arr[i] = n_array[i];
		ft_printf("stack_a[%d] = %d\n", i, stack_a.arr[i]);
		i++;
	}
	free(n_array);
	return 0;
}
