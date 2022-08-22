/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 18:30:00 by yujelee           #+#    #+#             */
/*   Updated: 2022/08/22 13:49:38 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	push_swap(t_stack *a, t_stack *b)
{
	if (validation(a, b) > 0)
		return ;
	if (a->size <= 5)
		classify_stack(a, b);
	else
	{
		indexing_node(a);
		moving_to_b(a, b);
		sorting(a, b);
	}
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
	push_swap(a, b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
