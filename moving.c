/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 18:41:39 by yujelee           #+#    #+#             */
/*   Updated: 2022/08/17 20:30:39 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	moving_to_b(t_stack *a, t_stack *b)
{
	int 	idx;
	int		pv[2];
	int		len;

	idx = 0;
	pv[0] = a->size / 3;
	pv[1] = pv[0] * 2;
	len = a->size;
	while (idx < len)
	{
		if (a->head->n >= pv[1])
			p(b, a, 'b');
		else if (a->head->n < pv[0])
		{
			p(b, a, 'b');
			r(b, 'b');
		}
		else
			r(a, 'a');
		++idx;
	}
}
