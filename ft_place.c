/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 16:30:29 by mybenzar          #+#    #+#             */
/*   Updated: 2019/01/18 19:27:13 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_create_tab(int size)
{
	int		i;
	char	**tab;
	char	*s1;

	i = -1;
	s1 = ft_strnew((int)size);
	if (!(tab = (char**)malloc(sizeof(char*) * (size + 1))))
		return (NULL);
	while (++i < size)
		s1[i] = '.';
	s1[i] = '\0';
	i =  -1;
	while (++i < size)
		tab[i] = ft_strdup(s1);
	tab[i] = 0;
	return (tab);
}

void	ft_find(char **tab, int *l, int *c)
{
	int	i;
	int j;
	
	i = *l;
	j = *c;
	while (tab[i][j] != '.' && tab[i][j] && tab[i])
	{		
		j++;
		if (!tab[i][j])
			i++;
	}
	*l = i;
	*c = j;
}

int		ft_place(t_triminos *list, char **tab, int l, int c)
{
	int		i;
	int		j;
	int		k;
	char	letter;
	t_triminos	tmp;
	
	i = -1;
	letter = 'A';
	tmp = *list;
	ft_find(tab, &l, &c);
	while (++i <= 3)
	{
		j = c + tmp.pos[i].x;
		k = l + tmp.pos[i].y;
		if (tab[k][j] == '.')
			tab[k][j] = tmp.letter;

		else if (!tab[k][j])
			ft_place(list, tab, l++, 0);
		//revoir ligne suivante, pertinence?
		//else if (!tab[k])
		//	ft_place(list, tab, 0, c++, &letter);
		else
			return (0);
	}
	letter++;
	return (1);
}

char	**ft_browse(char **tab, t_triminos *list, int size_tab)
{
	t_triminos	*tmp;
	int 		c;
	int			l;
	int			tri_placed;

	c = 0;
	l = 0;
	tri_placed = 0;
	tmp = list;
	tab = ft_create_tab(size_tab);
	ft_putendl("\ncree le tableau");
	ft_display_tab(tab);
	while (tmp)
	{
		// s'il arrive a placer le minos, passe au minos suivant :
		if (ft_place(tmp, tab, l, c))
		{
			tri_placed++;
			ft_lst_insert(list, tri_placed, tmp->letter);
			tmp = tmp->next;
		}
		// s'il n'arrive a le placer nulle part, essayer de placer le suivant a la place
		else
		{
			tmp = tmp->next;
			//appeler ici la fonction qui remet le minos precedent a la fin de la chaine
			ft_browse(tab, tmp, size_tab);
		}
		// pour faire toutes les combinaisons, il faut remettre a chaque fois le premier maillon de la chaine a la fin
		// par exemple, si on commence par 2, il faut remettre 1 a la fin de la chaine
	}
	//a essaye tous les minos mais aucune combinaison ne marche : free le tableau, l'agrandir et reessayer
	// condition d'arret de la recursion
	if (ft_list_size(list) == tri_placed)
		return (tab);
	ft_free_tab(tab);
	size_tab++;
	ft_browse(tab, list, size_tab);
	ft_putendl("error it shoudlnt reach this function");
	return (NULL);
}

