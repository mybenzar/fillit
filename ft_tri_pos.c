/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tri_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: struxill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 17:59:41 by struxill          #+#    #+#             */
/*   Updated: 2019/01/24 15:27:06 by struxill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_triminos	ft_tri_pos(t_list *list)
{
	t_triminos	triminos;
	int			nb;
	int			i;
	int			j;
	char		tmpstr[20];

	nb = 0;
	i = 0;
	j = 0;
	ft_strncpy(tmpstr, list->content, 19);
	while (nb < 4)
	{
		if (tmpstr[i + (j * 5)] == '#')
		{
			triminos.pos[nb].x = i;
			triminos.pos[nb].y = j;
			nb++;
			if (nb == 4)
				break ;
		}
		i++;
		i == 5 ? j++, i = 0 : i;
/*		if (i == 5)
		{
			j++;
			i = 0;
		}*/
	}
	return (triminos);
}
