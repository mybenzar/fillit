/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_tri_add.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: struxill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 17:41:52 by struxill          #+#    #+#             */
/*   Updated: 2019/01/16 19:06:57 by struxill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_lst_tri_add(t_triminos **list_tri, t_triminos *new_tri)
{
	if (!list_tri || !new_tri)
		return ;
//	while ((*list_tri)->next)
//		(*list_tri) = (*list_tri)->next;
//
//	(*list_tri)->next = new_tri;
	(*new_tri).next = *list_tri;
	*list_tri = new_tri;
}
