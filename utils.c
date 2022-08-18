/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 14:34:47 by yujelee           #+#    #+#             */
/*   Updated: 2022/08/18 15:18:42 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}

static int	ft_atoi(char c)
{
	if ('0' <= c && c <= '9')
		return (c - '0');
	return (-1);
}

static void	split_arg(char *arg, t_stack *a)
{
	int	idx;
	int	temp;

	idx = 0;
	temp = 0;
	while (arg[idx])
	{
		if (ft_atoi(arg[idx]) >= 0)
			temp = temp * 10 + ft_atoi(arg[idx]);
		else if (arg[idx] == ' ')
		{
			if (temp)
				insert_stack_back(a, temp);
			temp = 0;
		}
		else
			error();
		++idx;
	}
	if (temp)
		insert_stack_back(a, temp);
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
