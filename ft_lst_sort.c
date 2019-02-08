/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: struxill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 19:41:29 by struxill          #+#    #+#             */
/*   Updated: 2019/02/08 14:26:48 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_lst_sort(t_triminos *lst, int tri_placed)
{
	int 		index;
	t_triminos	*tmp;
	int 		i;

	index = 1;
	tmp = lst;
	i = 0;
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
				lst = ft_lst_insert(lst, (index - 1), tmp->next->letter);
			else
				tmp = tmp->next;
			index++;
		}
	}
}
