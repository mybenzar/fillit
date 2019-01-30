/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: struxill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 19:41:29 by struxill          #+#    #+#             */
/*   Updated: 2019/01/30 13:44:20 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_triminos	*ft_lst_sort(t_triminos *tri_list, int tri_placed)
{
	int		i;
	int		list_size;
	t_triminos	*tmp;

	tmp = tri_list;
	i = 0;
	list_size = ft_list_size(tri_list);
	while (i < (tri_placed - 1))
	{
		tmp = tmp->next; // pointe sur le 2eme maillon
		i++;
	}
	while (i < list_size)
	{
		tri_list = ft_lst_insert(tri_list, i, 65 + i);
		i++;
	}
	return (tmp);
}
