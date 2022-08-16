/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 18:30:00 by yujelee           #+#    #+#             */
/*   Updated: 2022/08/16 17:24:59 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <stdio.h> //지우기 제발 지우기 제발 지우기 제발 지우기
//int	main(int ac, char **av)
int	main(int ac, char **av)
{
	t_stack	*a;
	//t_stack	*b;

	if (ac < 2)
		return (-1);
	a = init_stack();
	process_args(ac, av, a);
}

//안지우면 죽음뿐.....유 다이;...
void pprint(t_stack *a)
{
	t_nd	*tmp;
	tmp = a->head;
	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
