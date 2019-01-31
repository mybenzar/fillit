/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: struxill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 19:41:29 by struxill          #+#    #+#             */
/*   Updated: 2019/01/31 17:34:20 by struxill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_lst_sort(t_triminos *lst, int tri_placed)
{
	int index;
	int	size_list;
	t_triminos	*tmp;

	index = 1;
	size_list = ft_list_size(lst);
	tmp = lst;
	while (index <= tri_placed && tmp->next)
	{
		index++;
		tmp = tmp->next;
	}
	while (tmp->next)
	{
		if (tmp->letter > tmp->next->letter)
			lst = ft_lst_insert(lst, index, lst->next->letter);
		index++;
		tmp = tmp->next;
	}
}








/*

{
	int		i;
	int		j;
	int		list_size;
//	t_triminos	*start;

//	start = tri_list;
	i = 0;
	j = 0;
	list_size = ft_list_size(tri_list);
	while (i < (tri_placed + 1))
	{
	//	tri_list = tri_list->next; // pointe sur le 2eme maillon
		i++;
	}
	while (i < list_size) // probleme de tri en fonction i au lieu de lettre restantes
	{
		if (tri_list->letter->next
		tri_list = ft_lst_insert(tri_list, i, 65 + i);
		i++;
	}
//	while (j < tri_placed)
//	{
//		j++;
//		tri_list = tri_list->next;
//	}	
	return (tri_list);
} */
