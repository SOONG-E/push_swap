/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_checker_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 15:35:02 by yujelee           #+#    #+#             */
/*   Updated: 2022/08/19 18:18:40 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <stdlib.h>

void	print_result(int res)
{
	if (res > 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	idx;

	if (!s1 || !s2)
		return (1);
	idx = 0;
	while (s1[idx] == s2[idx] && s1[idx])
		idx++;
	return ((unsigned char)s1[idx] - (unsigned char)s2[idx]);
}

char	*ft_strjoin(char *str1, char *str2)
{
	int		retidx;
	int		stridx;
	int		amount;
	char	*ret;

	amount = ft_strlen(str1) + ft_strlen(str2);
	ret = (char *)malloc((amount + 1) * sizeof(char));
	if (!ret)
		error();
	retidx = 0;
	if (str1)
	{
		stridx = 0;
		while (str1[stridx])
			ret[retidx++] = str1[stridx++];
		free(str1);
	}
	stridx = 0;
	while (str2[stridx])
		ret[retidx++] = str2[stridx++];
	ret[retidx] = 0;
	return (ret);
}