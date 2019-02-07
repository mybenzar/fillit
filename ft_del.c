/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 12:23:19 by mybenzar          #+#    #+#             */
/*   Updated: 2019/02/07 18:04:24 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_del(int letter, char **tab)
{
	int l;
	int c;
	int flag;

	l = 0;
	flag = 0;
	while (tab[l])
	{
		c = 0;
		while (tab[l][c])
		{
			if (tab[l][c] == letter)
			{
				tab[l][c] = '.';
				flag = 1;
			}
			c++;
		}
		l++;
	}
	return (flag);
}
