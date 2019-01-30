/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 12:23:19 by mybenzar          #+#    #+#             */
/*   Updated: 2019/01/30 18:19:58 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
/*
void	ft_del(int letter, char **tab)
{
	int l;
	int c;

	l = 0;
	while (tab[l])
	{
		c = 0;
		while (tab[l][c])
		{
			if (tab[l][c] == letter)
				tab[l][c] = '.';
			c++;
		}
		l++;
	}
}
*/

//ft_del supprime desormais toutes les lettres sauf celle mentionnee

void	ft_del(int letter, char **tab)
{
	int l;
	int c;

	l = 0;
	while (tab[l])
	{
		c = 0;
		while (tab[l][c])
		{
			if (tab[l][c] != letter && tab[l][c] != '.')
				tab[l][c] = '.';
			c++;
		}
		l++;
	}
}
