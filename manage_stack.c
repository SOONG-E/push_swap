/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 15:26:49 by yujelee           #+#    #+#             */
/*   Updated: 2022/08/16 18:57:20 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

static void	init_node(t_nd **head, t_nd	**tail)
{
	(*head)->pre = NULL;
	(*head)->n = 0;
	(*head)->next = *(tail);
	(*tail)->pre = *(head);
	(*tail)->n = 0;
	(*tail)->next = NULL;
}

t_stack	*init_stack()
{
	t_stack	*stk;
	stk = (t_stack *)malloc(sizeof(t_stack));
	if (!stk)
		exit(1);
	stk->head = NULL;
	stk->tail = NULL;
	stk->size = 0;
	return (stk);
}

void	free_stack(t_stack **a)
{
	/*
	t_nd	*temp;

	while (*head)
	{
		temp = (*head)->next;
		free(*head);
		*head = temp;
	}*/
}

void	insert_stack_back(t_stack *a, int n)
{
	t_nd	*temp;

	temp = (t_nd *)malloc(sizeof(t_nd));
	if (!temp)
		error();
	temp->pre = a->tail; //
	temp->next = NULL;
	if (a->tail)
		a->tail->next = temp;
	a->tail = temp;
	temp->n = n;
	if (a->size == 0)
		a->head = temp;
	++(a->size);
}
