/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeklee <jaeklee@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 15:18:19 by jaeklee           #+#    #+#             */
/*   Updated: 2025/06/06 19:02:55 by jaeklee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include "ft_printf/ft_printf.h"
#include <limits.h>

typedef struct s_stack{
	int *arr;
	int size;
} t_stack;

int	av_len(char **av);
long	ft_atoi(const char *str,int *error);
char **ft_split(char *str);
int	is_sorted(t_stack *a);
void sort_three_a(t_stack *stack);
void sort_three_b(t_stack *b);
void sort_five(t_stack *a, t_stack *b);
char	*ft_strjoin(char const *s1, char const *s2);
void stack_check(t_stack *a, t_stack *b, int word_count);
int *CtoI(char **temp, int word_count);
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
void sort_a_quick(t_stack *a, t_stack *b, int total_size);
void sort_b_quick(t_stack *a, t_stack *b, int total_size);
void dual_quick_sort(t_stack *a, t_stack *b, int size, char stack_name);

int is_sorted_size(t_stack *stack, int size);
void swap(int *a, int *b);
void rb_partial(t_stack *b, int size);
void rrb_partial(t_stack *b, int size);
int find_pivot(t_stack *stack, int size);

int is_sorted_desc(t_stack *b, int size);
void reverse_rotate_multiple(t_stack *stack, void (*rr_func)(t_stack *), int times);
int find_low_pivot(t_stack *stack, int size);
int find_upper_pivot(t_stack *stack, int size);
int find_pivot(t_stack *stack, int size);

void sort_three_a_limited(t_stack *a,t_stack *b);
// void sort_three_b_limited(t_stack *a);
void sort_three_b_limited(t_stack *a, t_stack *b);
void sort_first(t_stack *a, t_stack *b, int size);
int find_low_pivot(t_stack *stack, int size);
int find_upper_pivot(t_stack *stack, int size);
int find_pivot(t_stack *stack, int size);

void sort_a_norra(t_stack *a, t_stack *b, int size);
void sort_b_norrb(t_stack *a, t_stack *b, int size);
void sort_four_a(t_stack *a, t_stack *b);
int find_min_index(t_stack *a, int size);

int find_max_index(t_stack *b, int size);
void sort_four_b(t_stack *a, t_stack *b);
void sort_five_a(t_stack *a, t_stack *b);
int find_third_largest_pivot(t_stack *stack, int size);

#endif
