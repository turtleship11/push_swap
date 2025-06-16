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

int valid_input(char **av)
{
	int	i;
	int j;
	i = 1;
	if (av[i] == NULL)
		return (0);
	while (av[i] != NULL)
	{
		if (av[i][0] == '\0')  // 빈 문자열이면 에러
            return 0;
		j = 0;
		while(av[i][j] != '\0')
		{
			if ((av[i][j] >= '0' && av[i][j] <= '9') || (av[i][j] == ' ' 
			|| av[i][j] == '\t'))
				j++;
            else if (av[i][j] == '-')
            {
                // '-' 뒤에는 반드시 숫자가 와야 함을 체크
                if ((j == 0 || av[i][j - 1] == ' ' || av[i][j - 1] == '\t')
                    && (av[i][j + 1] >= '0' && av[i][j + 1] <= '9'))
                    j++;
                else
                    return 0;
			}
			else
				return (0);
		}
		i++;
	}
	return (1);
}
int	av_len(char **av)
{
	int	i;
	int j;
	int len;
	len = 0;
	i = 1;
	while (av[i] != NULL)
	{
		j = 0;
		while(av[i][j] != '\0')
		{
			j++;
		}
		len = len + j;
		i++;
	}
	return (len);
}
char	*words_join(char **av)
{
	int len;
	len = av_len(av);
	int	i;
	i = 1;
	int word_count ;
	word_count = 0;
	while (av[i] != NULL)
	{
		word_count++;
		i++;
	}
	char *temp;
	temp = malloc(len + word_count + 1);
	if(!temp)
		return NULL;
	int t;
	int j;	
	i = 1;
	t = 0;
	j = 0;
	while (av[i] != NULL)
	{
		j = 0;
		while(av[i][j] != '\0')
		{
			temp[t] = av[i][j];
			j++;
			t++;
		}
		temp[t] = ' ';
		t++;
		i++;
	}
	temp[t] = '\0';
	return (temp);
}
void free_split(char **split)
{
    int i = 0;
    while (split[i])
    {
        free(split[i]);
        i++;
    }
    free(split);
}
int *CtoI(char **temp, int word_count)
{
	int *n_array;
	n_array = malloc(sizeof(int) * word_count);
	int i;
	i = 0;
    while (temp[i] != NULL)
    {
        long val = ft_atoi(temp[i]);
		if (val == -1 || val > INT_MAX || val < INT_MIN)
        {
            write(2, "Error\n", 6);
            free_split(temp);
            free(n_array);
            return NULL;
        }
        n_array[i] = (int)val;
        i++;
    }
	free_split(temp);
	if (check_n(n_array, word_count) == 0)
	{
    	write(2, "Error\n", 6);
		free(n_array);
		return NULL;
	}
	return (n_array);
}

int init_sort(int *n_array, int word_count)
{
	t_stack a;
	t_stack b;
	a.arr = malloc(sizeof(int) * word_count);
	if(!a.arr)
		return 0;
	b.arr = malloc(sizeof(int) * word_count);
	if (!b.arr)
	{
		free(a.arr);
		return 0;
	}
	a.size = word_count;
	b.size = 0;
	if (!a.arr)
		return 0;
	if (!b.arr)
		return 0;	
	int	i;
	i = 0;
	while (i < word_count)
	{
		a.arr[i] = n_array[i];
		i++;
	}
	free(n_array);
	stack_check(&a, &b, word_count);
	return (1);
}
void stack_check(t_stack *a,t_stack *b,int word_count)
{
	if (is_sorted(a))
		return (free(a->arr), free(b->arr));
    if (word_count == 2)
    {
        if (a->arr[0] > a->arr[1])
            sa(a);
    }
	if (word_count == 3)
		sort_three_a(a);
	else if (word_count <= 5)
		sort_five(a,b);
	else
		sort_a_quick(a,b,word_count);
	int i = 0;
	while(i < a->size)
	{
		ft_printf("arr[%d] = %i\n",i, a->arr[i]);
		i++;
	}
	// ft_printf("a->size %i\n", a->size);
	// ft_printf("b->size %i\n", b->size);	
	free(a->arr);
	free(b->arr);
}
int main (int ac, char **av)
{
	if ((ac <= 1) || valid_input(av) == 0) 
	{
    	write(2, "Error\n", 6);
		return 0;
	}
	char *str = words_join(av);
	if (!str)
		return 0;
	int word_count = count_word(str);
	char **temp;
	temp = ft_split(str);
	if (!temp)
		return (free(str), 0);
	free(str);
	int *n_array = CtoI(temp,word_count);
	if (n_array == NULL)
    	return 0;
	init_sort(n_array, word_count);
	return 0;
}