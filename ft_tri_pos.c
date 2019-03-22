/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tri_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: struxill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 17:59:41 by struxill          #+#    #+#             */
/*   Updated: 2019/03/22 20:44:07 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_triminos		ft_assign_values(char *str, int nb, int i, int j)
{
	t_triminos	minos;

	while (nb < 4)
	{
		if (str[i + (j * 5)] == '#')
		{
			minos.pos[nb].x = i;
			minos.pos[nb].y = j;
			nb++;
			if (nb == 4)
				break ;
		}
		i++;
		if (i == 5)
		{
			j++;
			i = 0;
		}
	}
	return (minos);
}

t_triminos		ft_tri_pos(t_list *list)
{
	t_triminos	minos;
	int			nb;
	int			i;
	int			j;
//	char		tmpstr[20];

	nb = 0;
	i = 0;
	j = 0;
//	ft_strncpy(tmpstr, list->content, 19);
	minos = ft_assign_values(list->content, nb, i, j);
	return (minos);
}
