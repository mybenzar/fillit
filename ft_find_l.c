/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_l.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: struxill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 17:22:56 by struxill          #+#    #+#             */
/*   Updated: 2019/02/09 17:29:53 by struxill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_find_l(char letter, char	**tab)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (tab[i][j])
	{
		if (tab[i][j] == letter)
			return (i);
		if (tab[i][j + 1])
			j++;
		else if (tab[i + 1])
		{
			i++;
			j = 0;
		}
		else
			break ;
	}
	return (-1);
}
