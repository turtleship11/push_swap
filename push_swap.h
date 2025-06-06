/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeklee <jaeklee@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 15:18:19 by jaeklee           #+#    #+#             */
/*   Updated: 2025/06/06 14:22:14 by jaeklee          ###   ########.fr       */
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

int	ft_atoi(const char *str);
char	**ft_split(char const *s, char c);

#endif
