/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 18:29:57 by yujelee           #+#    #+#             */
/*   Updated: 2022/08/16 17:14:13 by yujelee          ###   ########seoul.kr  */
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
void		insert_stack(t_stack *a, int n);

void		process_args(int ac, char **av, t_stack *a);

void		error();

#endif