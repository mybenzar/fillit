/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_browse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 14:10:45 by mybenzar          #+#    #+#             */
/*   Updated: 2019/02/08 13:36:09 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_browse(char **tab, t_triminos *list, int size_tab)
{
	t_triminos	*tmp;
	int			tri_placed;
	int 		i;
	char		letter;
	int			stepback;

	tri_placed = 0;
	tmp = list;
	tab = ft_create_tab(size_tab);
	i = 0;
	stepback = 0;
	while (tri_placed < ft_list_size(list))
	{
		if (!stepback && ft_place_bis(tmp, tab, 0, 0))
		{
			tri_placed++;
			letter = tmp->letter;
			tmp = tmp->next;
		}
		else
		{
			if (ft_del(letter, tab))
				tri_placed--;
			stepback = 0;
			ft_lst_sort(list, tri_placed + 1);
			if (ft_next_valid_letter(list, letter, tab))
			{
				letter = ft_next_valid_letter(list, letter, tab);
				list = ft_lst_insert(list, tri_placed, letter);
				ft_lst_sort(list, tri_placed + 1);
				tmp = list;
				while (tmp->letter != letter && tmp->next)
					tmp = tmp->next;
			}
			else
			{
				if (tri_placed == 0)
					break ; 
				letter = ft_find_letter(list, tri_placed);
				stepback = 1;
			}
		}
	}
	if (ft_list_size(list) == tri_placed)
		return (tab);
	ft_free_tab(tab);
	size_tab++;
	list = ft_lst_insert(list, 0, 'A');
	ft_lst_sort(list, 0); 
	tab = ft_browse(tab, list, size_tab);
	return (tab);
}
