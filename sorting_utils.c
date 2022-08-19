/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 17:44:22 by yujelee           #+#    #+#             */
/*   Updated: 2022/08/19 14:49:31 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	finding_shortest_loc(t_stack *a, int n)
{
	t_nd	*temp;
	int		ret;

	temp = a->head;
	ret = -1;
	while (++ret < a->size)
	{
		if (temp->pre->n < temp->n)
		{
			if (temp->pre->n <= n && n <= temp->n)
				break ;
		}
		else
		{
			if (n <= temp->n || temp->pre->n <= n)
				break ;
		}
		temp = temp->next;
	}
	if (ret >= a->size / 2)
		ret = a->size - ret;
	return (ret);
}

int	finding_loc(t_stack *a, int n)
{
	t_nd	*temp;
	int		ret;

	temp = a->head;
	ret = -1;
	while (++ret < a->size)
	{
		if (temp->pre->n < temp->n)
		{
			if (temp->pre->n <= n && n <= temp->n)
				return (ret);
		}
		else
		{
			if (n <= temp->n || temp->pre->n <= n)
				return (ret);
		}
		temp = temp->next;
	}
	return (ret);
}

int	finding_exact_loc(t_stack *a, int n)
{
	t_nd	*temp;
	int		ret;

	temp = a->head;
	ret = -1;
	while (++ret < a->size)
	{
		if (temp->n == n)
			return (ret);
		temp = temp->next;
	}
	return (ret);
}
