/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_tri_lst.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: struxill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 18:10:04 by struxill          #+#    #+#             */
/*   Updated: 2019/01/16 18:16:20 by struxill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_display_tri_lst(t_triminos *tri_list)
{
	int i;

	i = 1;
	ft_display(*tri_list);
	while (tri_list->next)
	{
		ft_display(*tri_list->next);
		tri_list = tri_list->next;
	}
}
