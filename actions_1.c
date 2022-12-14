/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 17:31:01 by yujelee           #+#    #+#             */
/*   Updated: 2022/08/19 16:17:59 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	s(t_stack *a, char c)
{
	int	temp;

	if (a->size <= 1)
		return ;
	temp = a->head->n;
	a->head->n = a->head->next->n;
	a->head->next->n = temp;
	if (c == 'x')
		return ;
	if (c != 's')
		write_action("s", c);
}

void	p(t_stack *a, t_stack *b, char c)
{
	if (b->size < 1)
		return ;
	insert_stack_front(a, steal_node(b));
	if (c == 'x')
		return ;
	write_action("p", c);
}

void	r(t_stack *a, char c)
{
	if (a->size <= 1)
		return ;
	a->tail = a->head;
	a->head = a->head->next;
	if (c == 'x')
		return ;
	if (c != 's')
		write_action("r", c);
}

void	rr(t_stack *a, char c)
{
	if (a->size <= 1)
		return ;
	a->head = a->tail;
	a->tail = a->tail->pre;
	if (c == 'x')
		return ;
	if (c != 's')
		write_action("rr", c);
}
