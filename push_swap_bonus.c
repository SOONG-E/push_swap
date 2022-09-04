/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 15:18:19 by yujelee           #+#    #+#             */
/*   Updated: 2022/09/04 14:23:31 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include <unistd.h>
#include <stdlib.h>

static void	classify_action(t_stack *a, t_stack *b, char *act)
{
	if (!ft_strcmp(act, "sa"))
		s(a, 'x');
	else if (!ft_strcmp(act, "sb"))
		s(b, 'x');
	else if (!ft_strcmp(act, "ss"))
		sst(a, b, 'x');
	else if (!ft_strcmp(act, "pa"))
		p(a, b, 'x');
	else if (!ft_strcmp(act, "pb"))
		p(b, a, 'x');
	else if (!ft_strcmp(act, "ra"))
		r(a, 'x');
	else if (!ft_strcmp(act, "rb"))
		r(b, 'x');
	else if (!ft_strcmp(act, "rr"))
		rrt(a, b, 'x');
	else if (!ft_strcmp(act, "rra"))
		rr(a, 'x');
	else if (!ft_strcmp(act, "rrb"))
		rr(b, 'x');
	else if (!ft_strcmp(act, "rrr"))
		rrrt(a, b, 'x');
	else
		error();
}

static char	*read_action(void)
{
	char	buff[100];
	char	*temp;
	int		amount;

	temp = NULL;
	amount = read(0, &buff, 100);
	while (amount)
	{
		buff[amount] = 0;
		temp = ft_strjoin(temp, buff);
		amount = read(0, &buff, 100);
	}
	return (temp);
}

static void	parsing_action(t_stack *a, t_stack *b, char *acts)
{
	char	act[4];
	int		idx;
	int		idx2;

	idx = -1;
	if (!ft_strlen(acts))
		return ;
	while (acts[++idx])
	{
		idx2 = -1;
		while (acts[idx] && acts[idx] != '\n')
			act[++idx2] = acts[idx++];
		act[++idx2] = 0;
		classify_action(a, b, act);
	}
}

static void	checker(t_stack *a, t_stack *b)
{
	char	*temp;

	temp = read_action();
	parsing_action(a, b, temp);
	free(temp);
	print_result(validation(a, b));
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	if (ac < 2)
		return (-1);
	a = init_stack();
	b = init_stack();
	process_args(ac, av, a);
	if (!a->size)
		return (0);
	checker(a, b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
