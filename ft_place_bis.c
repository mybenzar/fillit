/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_bis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 11:19:27 by mybenzar          #+#    #+#             */
/*   Updated: 2019/02/08 11:52:16 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_find(char **tab, int *l, int *c, int x_pos)
{	
	int i;
	int j;

	i = *l;
	j = *c + x_pos;
	while (tab[i][j] != '.' && tab[i][j] && tab[i])
	{
		j++;
		if (tab[i][j] == '\0')
		{
			j = 0;
			if (tab[i + 1])
				i++;
			else
				return ;
		}
	}
	*l = i;
	*c = j - x_pos;
}

int		ft_test(t_triminos *list, char **tab, int *l, int *c)
{
	int	i;
	int	j;
	int k;

	*c = 0;
//	ft_find(tab, l, c, list->pos[0].x);
	i = 0;
	while (i <= 3)
	{
		j = *c + list->pos[i].x;
		k = *l + list->pos[i].y;
		if (tab[k] && tab[k][j])
		{
			if (tab[k][j] == '.')
				i++;
			else if (tab[k][j] >= 'A' && tab[k][j] <= 'Z')
			{
				i = 0;
				*c = *c + 1;
			}
			else if (tab[k][j] == '\0' && tab[k + 1])
			{
				*c = 0;
				*l = *l + 1;
				i = 0;
			}
		}
		else
			return (0);
	}
	return (1);
}

int		ft_place_bis(t_triminos *list, char **tab, int l, int c)
{
	int i;
	int j;
	int k;

	i = -1;
	ft_find(tab, &l, &c, list->pos[0].x);
	if (ft_test(list, tab, &l, &c))
	{
		while (++i <= 3)
		{
			j = c + list->pos[i].x;
			k = l + list->pos[i].y;
			tab[k][j] = list->letter;
		}
		return (1);
	}
	return (0);
}