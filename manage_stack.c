/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 15:26:49 by yujelee           #+#    #+#             */
/*   Updated: 2022/08/16 20:30:29 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

t_stack	*init_stack()
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

/*
void	free_stack(t_stack **a)
{

	t_nd	*temp;

	while (*head)
	{
		temp = (*head)->next;
		free(*head);
		*head = temp;
	}
}*/

void	insert_stack_back(t_stack *a, int n)
{
	t_nd	*temp;

	temp = (t_nd *)malloc(sizeof(t_nd));
	if (!temp)
		error();
	temp->pre = a->tail;
	temp->next = a->head;
	if (a->tail)
		a->tail->next = temp;
	a->tail = temp;
	temp->n = n;
	if (a->size == 0)
		a->head = temp;
	a->head->pre = temp;
	++(a->size);
}
