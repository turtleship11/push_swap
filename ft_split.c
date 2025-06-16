/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeklee <jaeklee@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 18:07:26 by jaeklee           #+#    #+#             */
/*   Updated: 2025/06/06 19:01:27 by jaeklee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	word_count(char *s)
{
	int i = 0;
	int word = 0;
	int count = 0;

	while (s[i])
	{
		if ((s[i] != ' ' && s[i] != '\t') && word == 0)
		{
			count++;
			word = 1;
		}
		else if (s[i] == ' ' || s[i] == '\t')
			word = 0;
		i++;
	}
	return count;
}

char *ft_store(int start, int end, char *s)
{
	char *temp;
	int i = 0;

	temp = malloc(end - start + 1);
	if (!temp)
		return NULL;
	while (start < end)
		temp[i++] = s[start++];
	temp[i] = '\0';
	return temp;
}

char **ft_split(char *str)
{
	char **temp;
	int i = 0, t = 0, start;
	int count = word_count(str);

	temp = malloc(sizeof(char *) * (count + 1));
	if (!temp)
		return NULL;

	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\t')
			i++;
		if (str[i] == '\0')
			break;
		start = i;
		while (str[i] != ' ' && str[i] != '\t' && str[i] != '\0')
			i++;
		temp[t++] = ft_store(start, i, str);
	}
	temp[t] = NULL;
	return temp;
}

