/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 16:30:29 by mybenzar          #+#    #+#             */
/*   Updated: 2019/01/16 20:08:38 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

// recoder realloc car elle n'est pas autorisee

char	**ft_create_tab(char **tab, int col, int line)
{
	int i;
	int j;

	i = 1;
	j = 0;
	if (!(tab = (char**)malloc(sizeof(char*) * col)))
		return (NULL);
	while (i <= 4)
	{
		if (!(tab[i++] = (char*)malloc(sizeof(char) * (col + 1))))
			return (NULL);
		while (tab[i][j])
			tab[i][j++] = '.';
		tab[i][j] = '\n';
	}
	return (tab);
}

int		ft_place(t_triminos *list, char **tab, int l, int c)
{
	char		letter;
	int			i;
	int			j;
	int			k;
	
	letter = 65;
	i = -1;
/* mettre dans ft_browse et envoyer l et c?
**	while (tab[l][c] != '.' && tab[l][c] && tab[l])
**	{		
**		c++;
**		if (!tab[l][c])
**			l++;
**	}
*/
	while (++i <= 3)
	{
		j = c + list.content.pos[i].x;
		k = l + list.content.pos[i].y;
		if (tab[k][j] == '.' && tab[k][j])
			tab[k][j] = letter;
		else if (!tab[k][j])
			ft_place(list, tab, l++, 0);
		else if (!tab[k])
			ft_place(list, tab, 0; c++);
		else
			return (0)
	}
	letter++;
	return (1);
}

void	ft_browse(char **tab, t_list **list)
{
	t_list	*tmp;
	int		col;
	int		line;
	int		nb_minos;
	int		max_col;
	int		max_line;

	col = 0;
	line = 0;
	tmp = *list;
	nb_minos = ft_list_size(*list);
	while (tmp->next)
	{
		
	}


	while (--nb_minos)
	{
		if (tab[line][col] == '.')
		{
			while (ft_place(tmp, &col, &line))
				tmp = tmp->next;
			while (!ft_place(tmp, &col, &line) && ((col + 1) % 4 != 0) && col <= max_col && line <= max_line)
			{
				if ((col + 1) % 4 != 0)
				{
					col++;
					ft_place(tmp, &col, &line);
				}
				else if ((col + 1) % 4 == 0)
				{
					line++;
					ft_place(tmp, &col, &line);
				}
				//n'arrive pas a le placer nulle part, donc doit passer a un autre minos
			}
			//a essaye tous les minos mais aucune combinaison ne marche : free le tableau, l'agrandir et reessayer
			if (col == max_col && line == max_line)
		}
	}
}
