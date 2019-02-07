/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 16:30:29 by mybenzar          #+#    #+#             */
/*   Updated: 2019/02/07 17:30:32 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_find(char **tab, int *l, int *c, int x_pos)
{
	int	i;
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
				return (0);
		}
	}
	*l = i;
	*c = j - x_pos;
	return (1);
}

int		ft_test(t_triminos *list, char **tab, int *l, int *c)
{
	int			i;
	int			j;
	int			k;

	*c = 0;
	if (ft_find(tab, l, c, list->pos[0].x))
	{
		i = 0;
		while (i <= 3)
		{
			j = *c + list->pos[i].x;
			k = *l + list->pos[i].y;
			if (tab[k] && tab[k][j] && tab[k][j] != '\0')
			{
				if (tab[k][j] == '.')
					i++;
				if (tab[k][j] >= 'A' && tab[k][j] <= 'Z')
				{
					i = 0;
					*c = *c + 1;
				}
			}
			else
					return (0);
		}
		return (1);
	}
	return (0);
}

/*
 ** ft_place places a mino only if ft_test returns 1
 ** ft_place calls ft_test for each line untill there is no line left
*/

int		ft_place(t_triminos *list, char **tab, int l, int c)
{
	int			i;
	int			j;
	int			k;
	t_triminos	*tmp;

	i = -1;
	tmp = list;
	if (ft_test(tmp, tab, &l, &c))
	{
		while (++i <= 3)
		{
			j = c + tmp->pos[i].x;
			k = l + tmp->pos[i].y;
			tab[k][j] = tmp->letter;
		}
		return (1);
	}
	else if (!tab[l + 1])
	{
		return (0);
	}
	else
	{
		if (ft_place(tmp, tab, ++l, 0))
			return (1);
	}
	return (0);
}
