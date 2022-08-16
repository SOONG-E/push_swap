/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 18:29:57 by yujelee           #+#    #+#             */
/*   Updated: 2022/08/12 19:28:16 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_lst
{
	struct s_lst	*pre;
	int				n;
	struct s_lst	*next;
}	t_lst;

typedef struct s_stack
{
	struct s_lst head;
	struct s_lst tail;
}	t_stack;



#endif