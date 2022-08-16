/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 17:31:01 by yujelee           #+#    #+#             */
/*   Updated: 2022/08/16 20:37:25 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	s(t_stack *a, char c)
{
	int temp;

	if (a->size < 1)
		return ;
	temp = a->head->n;
	a->head->n = a->head->next->n;
	a->head->next->n = temp;
	write_action("s", c);
}

void	double_time(t_stack *a, t_stack *b, char *c, \
		void (*f)(t_stack*, char))
{
	write(1, c, ft_strlen(c));
	write(1, "\n", 1);
	f(a, 'a');
	f(b, 'b');
}

void	p(t_stack *a, t_stack *b, char c)
{
	if ((b)->size > 0)
	{
		insert_stack_front(a, steal_node(b));
		++((a)->size);
		--((b)->size);
	}
	write_action("p", c);
}

