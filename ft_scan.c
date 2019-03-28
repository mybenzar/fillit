/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scan.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 10:58:27 by mybenzar          #+#    #+#             */
/*   Updated: 2019/03/28 14:20:59 by struxill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_scan(t_triminos *list, char **tab, int l, int c)
{
	int			placed;
	t_triminos	*tmp;

	tmp = list;
	placed = 0;
	while (placed < ft_list_size(list))
	{
		if (DEBUG)
			printf("rentre dans while ft_scan. List size = %i\n Placed = %i\n", 
					ft_list_size(list), placed);
		if (ft_place(tmp, tab, &l, &c))
		{
			placed++;
			ft_find(tab, &l, &c, list->pos[0].x);
			tmp = tmp->next;
		}
		else if (placed > 0 && tmp->prev)
		{
			tmp = tmp->prev;
			ft_find_and_del(tmp, tab, &l, &c);
			placed--;
		}
		else
			return (0);
	}
	return (1);
}
