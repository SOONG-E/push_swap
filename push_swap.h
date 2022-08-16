/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 18:29:57 by yujelee           #+#    #+#             */
/*   Updated: 2022/08/16 20:16:20 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_nd
{
	struct s_nd	*pre;
	int			n;
	struct s_nd	*next;
}	t_nd;

typedef struct s_stack
{
	struct s_nd	*head;
	struct s_nd	*tail;
	int			size;
}	t_stack;

t_stack	*	init_stack();
void		free_stack(t_stack **a);
void		insert_stack_back(t_stack *a, int n);

void		insert_stack_front(t_stack *a, t_nd *new);
t_nd		*steal_node(t_stack *a);

int			ft_strlen(char *str);
void		process_args(int ac, char **av, t_stack *a);

void		s(t_stack *a, char c);
void		p(t_stack *a, t_stack *b, char c);

void		error();

#endif