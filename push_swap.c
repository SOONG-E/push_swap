/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 18:30:00 by yujelee           #+#    #+#             */
/*   Updated: 2022/08/12 19:37:21 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_lst **head, t_lst **tail)
{
	*head = (t_lst *)malloc(sizeof(t_lst));
	*tail = (t_lst *)malloc(sizeof(t_lst));
	*(head->pre) = NULL;
	*head->n = 0;
	*head->next = *tail;
	*tail->pre = *head;
	*tail->n = 0;
	*tail->next = NULL;
}

void	free_stack(t_lst **head)
{
	t_lst	temp;

	while (*head)
	{
		temp = *head->next;
		free(*head);
		*head = temp;
	}
}

void	insert_stack(t_lst *tail, int n)
{
	t_lst	*temp;

	temp = (t_lst *)malloc(sizeof(t_lst));
	temp->pre = tail->pre;
	temp->n = n;
	temp->next = tail;
	tail->pre->next = temp;
	tail->pre = temp;
	return (temp);
}

int	check_args(int ac, char **av)
{
	int	avs[ac - 1];
	int	i;
	int j;

	i = 1;
	while (i < ac - 1)
	{
		if (sizeof(int) != sizeof(av[i]))
			return (-1);
		j = 0;
		while (j < i)
		{
			if (av[i] == avs[j])
				return (-1);
			++j;
		}
		avs[i] = av[i];
		++i;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;
	
	t_lst	*head;
	t_lst	*tail;

	if (ac < 2)
		return (-1);
	if (check_args(ac, av) == -1)
		return (-1);
		
}
