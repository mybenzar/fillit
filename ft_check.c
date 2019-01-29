/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 16:11:59 by mybenzar          #+#    #+#             */
/*   Updated: 2019/01/24 15:07:01 by struxill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_check(char *str)
{
	size_t	i;
	size_t	j;
	int		flag;

	flag = 1;
	i = 0;
	while (str[i] && flag == 1)
	{
		if (str[i + 1] == '\0' && i > 18)
			return (1);
		if (str[i] == '\n' && str[i + 1] == '\n' && i > 3)
			i = i + 2;
		else if (str[i] == '\n')
			i++;
		j = 3;
		while ((str[i] == '.' || str[i] == '#') && j > 0)
		{
			j--;
			i++;
		}
		if (j != 0 || str[i + 1] != '\n')
			flag = 0;
		i++;
	}
	return (0);
}
