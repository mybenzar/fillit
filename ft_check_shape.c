/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_shape.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: struxill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 16:10:41 by struxill          #+#    #+#             */
/*   Updated: 2019/01/17 17:48:41 by struxill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>


int	ft_check_other_shape(t_triminos *tri_list)
{
	if ((tri_list->pos[0].x == tri_list->pos[2].x ||
		tri_list->pos[0].y == tri_list->pos[2].y) ||
		(tri_list->pos[0].x == tri_list->pos[3].x ||
		tri_list->pos[0].y == tri_list->pos[3].y) ||
		(tri_list->pos[1].x == tri_list->pos[3].x ||
		tri_list->pos[1].y == tri_list->pos[3].y))
		return (1);
	return (0);
}

int	ft_check_shape(t_triminos *tri_list)
{
	int i;

	while (tri_list)
	{
		i = 0;
		while (i < 3 && (tri_list->pos[i].x == tri_list->pos[i + 1].x ||
				tri_list->pos[i].y == tri_list->pos[i + 1].y))
		{
			i++;
	//		ft_putendl("Test");
		}
		if (i != 3)
			if (ft_check_other_shape(tri_list))
				i = 3;
		if (i != 3)
		{
			ft_putendl("La forme m'est pas bonne");
			printf("[%i, %i] n'est pas compatible avec [%i, %i]\n", tri_list->pos[i].x, tri_list->pos[i].y, tri_list->pos[i].y, tri_list->pos[i + 1].y);
			return (0);
		}
		tri_list = tri_list->next;
	}
	return (1);
}
