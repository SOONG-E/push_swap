/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 15:26:49 by yujelee           #+#    #+#             */
/*   Updated: 2022/08/19 14:48:54 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

t_stack	*init_stack(void)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		exit(1);
	new->head = NULL;
	new->tail = NULL;
	new->size = 0;
	return (new);
}

void	free_stack(t_stack **a)
{
	t_nd	*temp;
	int		idx;

	idx = -1;
	while (++idx < (*a)->size)
	{
		temp = (*a)->head->next;
		free((*a)->head);
		(*a)->head = temp;
	}
	free(*a);
}

static int	check_duplication(t_stack *a, int n)
{
	t_nd	*temp;
	int		idx;

	temp = a->head;
	idx = -1;
	while (++idx < a->size)
	{
		if (temp->n == n)
			error();
		temp = temp->next;
	}
	return (1);
}

void	insert_stack_back(t_stack *a, int n)
{
	t_nd	*temp;

	if (check_duplication(a, n))
	{
		temp = (t_nd *)malloc(sizeof(t_nd));
		if (!temp)
			error();
		if (a->size == 0)
		{
			a->head = temp;
			a->tail = temp;
		}
		temp->pre = a->tail;
		temp->next = a->head;
		if (a->tail)
			a->tail->next = temp;
		a->tail = temp;
		temp->n = n;
		a->head->pre = temp;
		++(a->size);
	}
}
