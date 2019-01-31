/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: struxill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 19:41:29 by struxill          #+#    #+#             */
/*   Updated: 2019/01/31 21:56:54 by struxill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void	ft_lst_sort(t_triminos *lst, int tri_placed)
{
	int 		index;
	t_triminos	*tmp;
	int 		i;

	index = 1;
	tmp = lst;
	i = 0;
	// CAS OU APPELER AVEC ZERO ET lst->letter == A  => RESET TOTAL 
	if (tri_placed == 0 && lst->letter == 'A')
		while (i < ft_list_size(lst))
		{
			ft_lst_insert(lst, i, 65 + i);
			i++;
		}
	else
	{
		while (index <= tri_placed && tmp->next)
		{
			index++;
			tmp = tmp->next;
		}
		while (tmp->next)
		{
			if (tmp->letter > tmp->next->letter)
			{
				printf("tmp->letter = %c, tmp->next->letter = %c, index = %i\n", 
						tmp->letter, tmp->next->letter, index);
				lst = ft_lst_insert(lst, (index - 1), tmp->next->letter);
		//	printf("Apres le lst insert : tmp->letter = %c, tmp->next->letter = %c, 
		//	index = %i\n", tmp->letter, tmp->next->letter, index); 
		//	PRINTF QUI SEGFAULT CAR VAS VOIR ->NEXT QUI NEXISTE PAS;
		//	tmp = tmp->next; pas besoin du coup
			}	
			else
				tmp = tmp->next;
			index++;
		}
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
