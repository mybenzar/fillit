/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_t_list_to_tri_list.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: struxill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 17:52:03 by struxill          #+#    #+#             */
/*   Updated: 2019/01/16 18:20:42 by struxill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

t_triminos	*ft_t_list_to_tri_list(t_list *list)
{
	t_triminos	*start;

	start = ft_lst_tri_new(ft_left(ft_tri_pos(list)));
//	printf("diese 1 du triminos 1 : [%i, %i]\n", start->pos[0].x, start->pos[0].y);

	while (list->next)
	{
		ft_lst_tri_add(&start, ft_lst_tri_new(ft_left(ft_tri_pos(list->next))));
		list = list->next;
	}

	return (start);
}
