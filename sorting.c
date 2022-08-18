/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 15:53:06 by yujelee           #+#    #+#             */
/*   Updated: 2022/08/18 17:31:13 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>
#include <stdio.h> //제발 지워 제발 지워 제발 지워 제발 지워

static int	finding_loc(t_stack *a, int n)
{
	t_nd	*temp;
	int		ret;

	temp = a->head;
	ret = 0;
	while (ret < a->size)
	{
		if (temp->pre->n < temp->n)
		{
			if (temp->pre->n < n && n < temp->n)
				break;
		}
		else
		{
			if (n < temp->n || temp->pre->n < n)
				break;
		}
		temp = temp->next;
		++ret;
	}
	if (ret > a->size / 2)
		ret = a->size - ret;
	return (ret);
}

static int	calculator(t_stack *a, t_stack *b)
{
	int		min[2];
	int		idx;
	int		loc;
	t_nd	*temp;

	idx = 0;
	temp = b->head;
	min[0] = temp->n;
	min[1] = INT_MAX;
	while (idx < b->size)
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
		++idx;
	}
	return (min[0]);
}

static void	shift_a(t_stack *a, int n)
{
	void	(*f)(t_stack *a, char c);
	
	if (finding_loc(a, n) > (a->size / 2))
		f = rr;
	else
		f = r;
	while (finding_loc(a, n))
		f(a, n);
}

static void	moving_to_a(t_stack *a, t_stack *b, int n)
{
	t_nd	*temp;

	temp = b->head;
	shift_a(a, n);
	
	
}

void	sorting(t_stack *a, t_stack *b)
{
	int	idx;

	idx = calculator(a, b);
	moving_to_a(a, b, idx);
}
