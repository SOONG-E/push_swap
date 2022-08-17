/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 18:30:00 by yujelee           #+#    #+#             */
/*   Updated: 2022/08/17 16:26:33 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <stdio.h> //지우기 제발 지우기 제발 지우기 제발 지우기

//안지우면 죽음뿐.....유 다이;...
void pprint(t_stack *a)
{
	t_nd	*tmp;
	tmp = a->head;
	int i;
	
	i = 0;
	while (tmp && i < a->size)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
		++i;
	}
} //안지우면 죽음뿐.....유 다이;...


void	push_swap(t_stack *a, t_stack *b)
{
	if (a->size <= 5)
		classify_stack(a, b);
	else
	{
		indexing_node(a);
	}
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	if (ac < 2)
		error();
	a = init_stack();
	b = init_stack();
	process_args(ac, av, a);
	push_swap(a, b);
	pprint(a);
}
