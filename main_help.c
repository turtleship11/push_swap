/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_help.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeklee <jaeklee@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 13:16:58 by jaeklee           #+#    #+#             */
/*   Updated: 2025/06/09 13:17:21 by jaeklee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

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
	int i = 0;
	while (i < size - 1)
	{
		int j = i + 1;
		while (j < size)
		{
			if (num[i] == num[j])
				return 0;
			j++;
		}
		i++;
	}
	return 1;
}
