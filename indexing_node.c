/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing_node.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 13:08:42 by yujelee           #+#    #+#             */
/*   Updated: 2022/08/17 16:27:40 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

static void	shell_sort(t_nd ***arr, int len)
{
	int		h;
	int		i;
	int		j;
	t_nd	**temp;

	h = len / 2;
	while (h > 0)
	{
		i = h;
		while (i < len)
		{
			j = i - h;
			temp = arr[i];
			while (j >= 0 && (*arr[j])->n > (*temp)->n)
			{
				arr[j + h] = arr[j];
				j -= h;
			}
			arr[j + h] = temp;
			i++;
		}
		h /= 2;
	}
}

void	indexing_node(t_stack *a)
{
	t_nd	***idxs;
	t_nd	**temp;
	int		idx;

	idxs = (t_nd ***)malloc((a->size) * sizeof(t_nd **));
	if (!idxs)
		error();
	temp = &(a->head);
	idx = 0;
	while (temp && idx < a->size)
	{
		idxs[idx++] = temp;
		temp = &((*temp)->next);
	}
	shell_sort(idxs, a->size);
	idx = -1;
	while (++idx < a->size)
		(*idxs[idx])->n = idx;
	free(idxs);
}
