/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 18:30:00 by yujelee           #+#    #+#             */
/*   Updated: 2022/08/16 19:18:57 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <stdio.h> //지우기 제발 지우기 제발 지우기 제발 지우기
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

//int	main(int ac, char **av)
int	main()
{
	t_stack	*a;
	t_stack	*b;


	int ac = 3;
	char *av[3];
	av[1] = "3 4 55";
	av[2] = "6 7";

	if (ac < 2)
		error();
	a = init_stack();
	b = init_stack();
	process_args(ac, av, a);
	
	pprint(a);
	p(b, a, 'b');
	printf("after p \na : \n");
	pprint(a);
	printf("b : \n");
	pprint(b);
}
