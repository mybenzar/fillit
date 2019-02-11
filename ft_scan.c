/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scan.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 10:58:27 by mybenzar          #+#    #+#             */
/*   Updated: 2019/02/11 16:48:27 by struxill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

char	**ft_scan(t_triminos *list, int size_tab, char **tab)
{
	int			placed;
	int 		l;
	int			c;
	t_triminos	*tmp;

	tmp = list;
	placed = 0;
	l = 0;
	c = 0;
	while (placed < ft_list_size(list))
	{
		if (ft_place_bis(tmp, tab, l, c)) //si il arrive a le placer
		{
			placed++;
			l = 0;  //reinitialisation pour ft_find
			c = 0;
			// le if suivant est une condition darret anticipe car sinon apres le dernier placer 
			// il rentre dans le ft_test sur un tmp->next qui nexiste pas et ca SEGFAULT 
			// (et jai pas reussi a l'enlever autrement pour l'instant mais on va trouver)
			if (placed == ft_list_size(list))
				return (tab);
			ft_find(tab, &l, &c, list->pos[0].x); //necessaire pour se replacer au debut du tableau avant test
			if (ft_test_bis(tmp->next, tab, &l, &c)) //si le suivant rentre il se met dessus
				tmp = tmp->next;
			else //si le suivant rentre pas il revient au valeur de l et c d'avant le test pour incrementer
			{
				l = ft_find_l(tmp->letter, tab);	//tmp_l;
				c = ft_find_c(tmp->letter, tab) - tmp->pos[0].x; //tmp_c;
				ft_del(tmp->letter, tab);
				placed--;
				if (tab[l] && tab[l][c] != '\0')
					c++;
				else if (tab[l + 1])
					l++;
			}
		}
		// Quand le minos deplace arrive en bas du tableau et de peux plus etre deplacer mais
		// qu'il y a au moins 1 minos place avant on va deplacer celui la;
		else if (placed > 0 && tmp->prev)
		{
			tmp = tmp->prev;
			l = ft_find_l(tmp->letter, tab); //replacer l sur le 1er diese du minos place avant
			c = ft_find_c(tmp->letter, tab) - tmp->pos[0].x; //replacer c ...
			ft_del(tmp->letter, tab);
			placed--;
			if (tab[l] && tab[l][c] != '\0')
				c++;
			else if (tab[l + 1])
				l++;
		}
		// Quand le premier minos est en bas a droite et que ca ne rentre toujours pas on agrandi et on reset;
		else
		{
			size_tab++;
			ft_free_tab(tab);
			tab = ft_create_tab(size_tab);
			l = 0;
			c = 0;
		}
	}
	ft_lst_free(list);
	return (tab);
}
