/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 16:11:59 by mybenzar          #+#    #+#             */
/*   Updated: 2019/02/07 19:54:25 by struxill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_check(char *str)
{
	int i;
	int j;
	int	diese_nb;
	int dot_nb;
	int cr_nb;

	i = 0;
	j = 0;
	while (str)
	{
		diese_nb = 0;
		dot_nb = 0;
		cr_nb = 0;
		while (i < j + 20 && str[i])
		{
			if (str[i] == '.')
				dot_nb++;
			if (str[i] == '#')
				diese_nb++;
			if (str[i] == '\n')
				cr_nb++;
			i++;
		}
		if (dot_nb != 12 || diese_nb != 4 || cr_nb != 4)
			return (0);
		if (str[i] == '\0')
			return (1);
		if (str[i] != '\n')
			return (0);
		else
			i++;
		j = i;
	}
	return (0);
}
