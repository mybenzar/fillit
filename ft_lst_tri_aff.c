/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_tri_aff.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 17:33:51 by mybenzar          #+#    #+#             */
/*   Updated: 2019/01/28 17:37:01 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_lst_tri_aff(t_triminos *tri_list)
{
	ft_display(tri_list);
	while (tri_list->next)
	{
		tri_list = tri_list->next;
		ft_display(tri_list);
	}
}
