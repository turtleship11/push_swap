/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeklee <jaeklee@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 11:34:11 by jaeklee           #+#    #+#             */
/*   Updated: 2025/04/23 16:36:26 by jaeklee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <limits.h>

long	ft_atoi(const char *str,int *error)
{
	long		c;
	long		v;

	*error = 0;
	c = 1;
	v = 0;
	while (*str == ' ' || (*str >= 8 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			c = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		if (v > (LONG_MAX - (*str - '0')) / 10)
		{
			// 오버플로우 시 -1 리턴 (에러 표시)
			*error = 1;
			return 0;
		}
		v = v * 10 + (*str - '0');
		str++;
	}
	return (v * c);
}

