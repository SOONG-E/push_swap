/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 17:44:22 by yujelee           #+#    #+#             */
/*   Updated: 2022/08/18 18:01:38 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
				break;
		}
		else
		{
			if (n <= temp->n || temp->pre->n <= n)
				break;
		}
		temp = temp->next;
	}
	if (ret > a->size / 2)
		ret = a->size - ret;
	return (ret);
}
