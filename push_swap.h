/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeklee <jaeklee@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 15:18:19 by jaeklee           #+#    #+#             */
/*   Updated: 2025/06/09 18:10:03 by jaeklee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include "ft_printf/ft_printf.h"

typedef struct s_stack{
	int *arr;
	int top;
	int size;
} t_stack;

int	av_len(char **av);
int	ft_atoi(const char *str);
char **ft_split(char *str);
int	is_sorted(t_stack *a);
void sort_three_a(t_stack *stack);
void sort_three_b(t_stack *b);
void sort_five(t_stack *a, t_stack *b);
void sort_a_quick(t_stack *a, t_stack *b, int size);
char	*ft_strjoin(char const *s1, char const *s2);
void stack_check(t_stack *a, t_stack *b, int word_count);

int count_word(char *s);
int check_n(int *num, int size);
void sa(t_stack *a);
void sb(t_stack *b);
void ss(t_stack *a, t_stack *b);
void pa(t_stack *a, t_stack *b);
void pb(t_stack *a, t_stack *b);
void ra(t_stack *a);
void rb(t_stack *b);
void rr(t_stack *a,t_stack *b);
void rra(t_stack *a);
void rrb(t_stack *b);
void rrr(t_stack *a,t_stack *b);
void sort_a_quick(t_stack *a, t_stack *b, int size);
void sort_b_quick(t_stack *a, t_stack *b, int size);
#endif
