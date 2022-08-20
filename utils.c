/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 14:34:47 by yujelee           #+#    #+#             */
/*   Updated: 2022/08/20 18:03:18 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		++i;
	return (i);
}

static int	ft_atoi(char c, int n, int sign)
{
	if ('0' <= c && c <= '9')
	{
		if (n >= 214748364 && ((sign > 0 && (c - '0') > 7)
				|| (sign < 0 && (c - '0') > 8)))
			error();
		if (n > 214748364)
			error();
		return (c - '0');
	}
	return (-1);
}

static void	split_arg(char *arg, t_stack *a)
{
	int			idx;
	long long	temp;
	int			sign;

	idx = -1;
	temp = 0;
	sign = 1;
	while (arg[++idx])
	{
		if (arg[idx] == '-' && !temp)
			sign = -1;
		else if (ft_atoi(arg[idx], temp, sign) >= 0)
			temp = temp * 10 + ft_atoi(arg[idx], temp, sign);
		else if (arg[idx] == ' ')
		{
			if (temp || (arg[idx - 1] && !temp && arg[idx - 1] == '0'))
				insert_stack_back(a, sign * temp);
			temp = 0;
			sign = 1;
		}
		else
			error();
	}
	if (temp || (!temp && arg[idx - 1] == '0'))
		insert_stack_back(a, sign * temp);
}

void	process_args(int ac, char **av, t_stack *a)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		split_arg(av[i], a);
		++i;
	}
}

void	write_action(char *act, char c)
{
	write(1, act, ft_strlen(act));
	write(1, &c, 1);
	write(1, "\n", 1);
}
