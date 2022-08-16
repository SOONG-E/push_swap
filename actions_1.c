/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 17:31:01 by yujelee           #+#    #+#             */
/*   Updated: 2022/08/16 20:12:54 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	s(t_stack *a, char c)
{
	int temp;

	if (a->size < 1)
		return ;
	temp = a->head->n;
	a->head->n = a->head->next->n;
	a->head->next->n = temp;
}

void	double_time(t_stack *a, t_stack *b, char *c, \
		void (*f)(t_stack*, char))
{
	write(1, c, ft_strlen(c));
	write(1, "\n", 1);
	f(a, 'a');
	f(b, 'b');
} // 함수포인터 안쓰게 되면 ft_strlen지우기

void	p(t_stack *a, t_stack *b, char c)
{
	if ((b)->size > 0)
	{
		insert_stack_front(a, steal_node(b));
		++((a)->size);
		--((b)->size);
	}	
}

void	r(t_stack *a, char c)
{
	
}
