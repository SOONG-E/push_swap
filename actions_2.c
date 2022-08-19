/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 11:20:21 by yujelee           #+#    #+#             */
/*   Updated: 2022/08/19 16:19:02 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sst(t_stack *a, t_stack *b, char c)
{
	s(a, 's');
	s(b, 's');
	if (c == 'x')
		return ;
	write_action("s", 's');
}

void	rrt(t_stack *a, t_stack *b, char c)
{
	r(a, 's');
	r(b, 's');
	if (c == 'x')
		return ;
	write_action("r", 'r');
}

void	rrrt(t_stack *a, t_stack *b, char c)
{
	rr(a, 's');
	rr(b, 's');
	if (c == 'x')
		return ;
	write_action("rr", 'r');
}
