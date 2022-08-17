/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 11:20:21 by yujelee           #+#    #+#             */
/*   Updated: 2022/08/17 12:28:24 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sst(t_stack *a, t_stack *b)
{
	s(a, 's');
	s(b, 's');
	write_action("s", 's');
}

void	rrt(t_stack *a, t_stack *b)
{
	r(a, 's');
	r(b, 's');
	write_action("r", 'r');
}

void	rrrt(t_stack *a, t_stack *b)
{
	rr(a, 's');
	rr(b, 's');
	write_action("rr", 'r');
}
