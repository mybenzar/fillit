/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_to_tri_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: struxill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 11:28:08 by struxill          #+#    #+#             */
/*   Updated: 2019/03/28 11:57:06 by struxill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_triminos	*ft_tab_to_tri_list(char **tab)
{
	t_triminos	*start;
	int			i;

	i = 0;
	start = ft_lst_tri_new(ft_left(ft_tri_pos(tab[i])));
	i++;
	while (tab[i])
	{
		ft_lst_tri_add(&start, ft_lst_tri_new(ft_left(ft_tri_pos(tab[i]))));
		i++;
	}
	return (start);
}
