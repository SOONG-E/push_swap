/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   classify_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 13:06:42 by yujelee           #+#    #+#             */
/*   Updated: 2022/08/22 17:40:36 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_size_2(t_stack *a)
{
	if (a->head->n > a->tail->n)
		s(a, 'a');
}

void	stack_size_3(t_stack *a)
{
	if (a->head->n < a->tail->pre->n && a->tail->pre->n < a->tail->n)
		return ;
	if (a->tail->pre->n < a->head->n && a->head->n < a->tail->n)
	{
		s(a, 'a');
		return ;
	}
	if (!(a->tail->n < a->head->n && a->head->n < a->tail->pre->n)
		&& (!(a->tail->pre->n < a->tail->n && a->tail->n < a->head->n)))
		s(a, 'a');
	if (a->tail->pre->n < a->tail->n)
		r(a, 'a');
	else
		rr(a, 'a');
}

static void	stack_size_4(t_stack *a, t_stack *b)
{
	while (a->head->n)
		r(a, 'a');
	if (validation(a, b) < 0)
	{
		p(b, a, 'b');
		stack_size_3(a);
		p(a, b, 'a');
	}
}

static void	stack_size_5(t_stack *a, t_stack *b)
{
	int	n;

	n = 0;
	while (n < 2)
	{
		if (a->head->n == 0 || a->head->n == 1)
		{
			p(b, a, 'b');
			++n;
		}
		else
			r(a, 'a');
	}
	stack_size_3(a);
	if (b->head->n < b->tail->n)
		s(b, 'b');
	p(a, b, 'a');
	p(a, b, 'a');
}

void	classify_stack(t_stack *a, t_stack *b)
{
	if (a->size == 1)
		return ;
	else if (a->size == 2)
		stack_size_2(a);
	else
	{
		indexing_node(a);
		if (a->size == 3)
			stack_size_3(a);
		else if (a->size == 4)
			stack_size_4(a, b);
		else
			stack_size_5(a, b);
	}
}
