/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 16:30:29 by mybenzar          #+#    #+#             */
/*   Updated: 2019/01/17 13:09:02 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_create_tab(int col, int line)
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
		tab[i][j] = '\0';
	}
	return (tab);
}

void	ft_find(char **tab, int l, int c)
{
	while (tab[l][c] != '.' && tab[l][c] && tab[l])
	{		
		c++;
		if (!tab[l][c])
			l++;
	}
}

int		ft_place(t_triminos *list, char **tab, int l, int c)
{
	char		letter;
	int			i;
	int			j;
	int			k;
	
	letter = 65;
	i = -1;
	ft_find(tab, l, c);
	while (++i <= 3)
	{
		j = c + list.pos[i].x;
		k = l + list.pos[i].y;
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

void	ft_browse(char **tab, t_triminos *list)
{
	t_triminos	*tmp;
	int			c;
	int			l;
	int			nb_minos;
	int			max_col;
	int			max_line;

	c = 0;
	l = 0;
	tmp = list;
	// la ligne suivante est elle encore necessaire ?
	nb_minos = ft_list_size(tmp);
	while (tmp->next)
	{
		// cherche l et c tel que tab[l][c] est un emplacement vide :
		ft_find(tab, l, c);
		// s'il arrive a placer le minos, passe au minos suivant :
		if (ft_place(tmp, tab, l, c))
			tmp = tmp->next;
		// s'il n'arrive a le placer nulle part, essayer de placer le suivant a la place
		else
		{
			tmp = tmp->next;
			ft_browse(tmp);
		}
		// pour faire toutes les combinaisons, il faut remettre a chaque fois le premier maillon de la chaine a la fin
		// par exemple, si on commence par 2, il faut remettre 1 a la fin de la chaine
	}
			//a essaye tous les minos mais aucune combinaison ne marche : free le tableau, l'agrandir et reessayer
			if (col == max_col && line == max_line)
}
