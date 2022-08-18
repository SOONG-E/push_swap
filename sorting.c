/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 15:53:06 by yujelee           #+#    #+#             */
/*   Updated: 2022/08/18 19:11:07 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

static int	calculator(t_stack *a, t_stack *b)
{
	int		min[2];
	int		idx;
	int		loc;
	t_nd	*temp;

	idx = -1;
	temp = b->head;
	min[0] = temp->n;
	min[1] = INT_MAX;
	while (++idx < b->size)
	{
		if (idx < b->size / 2)
			loc = idx + finding_loc(a, temp->n);
		else
			loc = b->size - idx + finding_loc(a, temp->n);
		if (loc < min[1])
		{
			min[0] = temp->n;
			min[1] = loc;
		}
		temp = temp->next;
	}
	return (min[0]);
}

static void	shift_a(t_stack *a, int n, char c)
{
	void	(*f)(t_stack *a, char c);
	
	if (finding_loc(a, n) > (a->size / 2))
		f = rr;
	else
		f = r;
	while (finding_loc(a, n))
		f(a, c);
}

static void	moving_to_a(t_stack *a, t_stack *b, int n)
{
	t_nd	*temp;

	temp = b->head;
	shift_a(a, n, 'a');
	shift_a(b, n, 'b');
	if (b->tail->n == n)
		rr(b, 'b');
	p(a, b, 'a');
}

void	smallest_head(t_stack *a)
{
	int		min;
	int		idx;
	t_nd	*temp;

	temp = a->head;
	min = temp->n;
	idx = -1;
	while (++idx < a->size)
	{
		if (temp->n < min)
			min = temp->n;
		temp = temp->next;
	}
	shift_a(a, min, 'a');
	if (a->tail->n == min)
		rr(a, 'a');
}

void	sorting(t_stack *a, t_stack *b)
{
	int	min;

	while (b->size)
	{
		min = calculator(a, b);
		moving_to_a(a, b, min);
	}
	smallest_head(a);
}
