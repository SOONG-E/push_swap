/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_in_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 18:57:11 by yujelee           #+#    #+#             */
/*   Updated: 2022/08/16 20:20:52 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insert_stack_front(t_stack *a, t_nd *new)
{
	if (a->size)
	{
		new->pre = a->head->pre;
		new->next = a->head;
		a->head->pre = new;
		a->head->pre->next = new;
	}
	else
	{
		a->tail = new;
		new->pre = a->tail;
		new->next = a->tail;
	}
	a->head = new;
}

t_nd	*steal_node(t_stack *a)
{
	t_nd	*ret;

	ret = a->head;
	a->head->next->pre = a->head->pre;
	a->head->pre->next = a->head->next;
	a->head = a->head->next;
	return (ret);
}
