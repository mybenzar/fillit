/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scan.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 10:58:27 by mybenzar          #+#    #+#             */
/*   Updated: 2019/02/08 11:19:20 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_scan(char **tab, t_triminos *list, int size_tab)
{
	int			placed;
	int 		l;
	int			c;
	t_triminos	*tmp;
	
	tmp = list;
	placed = 0;
	while (placed < ft_list_size(list))
	{
		if (ft_place_bis(tmp, tab, l, c))
		{
			placed++;
			if (ft_test_bis(tmp->next, tab, &l, &c))
				tmp = tmp->next;
			else if (tab[l] && tab[l][c] != '\0')
				c++;
			else if (tab[l + 1])
				l++;
		}
		else
		{
			ft_del(tmp->letter, tab);
			placed--;
		}
	}
	
}
