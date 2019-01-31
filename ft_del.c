/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 12:23:19 by mybenzar          #+#    #+#             */
/*   Updated: 2019/01/31 21:05:30 by struxill         ###   ########.fr       */
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


//ft_del supprime desormais toutes les lettres sauf celle mentionnee
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
			if (tab[l][c] != letter && tab[l][c] != '.')
				tab[l][c] = '.';
			c++;
		}
		l++;
	}
} */
