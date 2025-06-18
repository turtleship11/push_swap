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

void reverse_rotate_multiple(t_stack *stack, void (*rr_func)(t_stack *), int times)
{
    while (times-- > 0)
        rr_func(stack);
}