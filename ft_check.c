/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 16:11:59 by mybenzar          #+#    #+#             */
/*   Updated: 2018/12/13 16:29:42 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#include <stdio.h>

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
		{
			printf("VALIDE\n\n");
			return (1);
		}
		if (str[i] == '\n' && str[i + 1] == '\n' && i > 3)
			i = i + 2;
		else if (str[i] == '\n')
		{
			i++; 
//			printf("\nsaut de ligne \n");
		}
		j = 3;
		while ((str[i] == '.' || str[i] == '#') && j > 0)
		{
			j--;
			i++;
		}
		if (j != 0 || str[i + 1] != '\n')
		{
			flag = 0;
			printf("i = %zu quand ca stoppe\n", i);
		}
		i++;
	}
	return (0);
}
