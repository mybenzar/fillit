/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 16:30:36 by mybenzar          #+#    #+#             */
/*   Updated: 2019/01/16 18:17:13 by struxill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_display(t_triminos tri)
{
	char	str_tri[20];
	int		diese;

	diese = 0;
	ft_strncpy(str_tri, "....\n....\n....\n....", 19);
	while (diese < 4)
	{
		str_tri[tri.pos[diese].x + (tri.pos[diese].y * 5)] = '#';
		diese++;
	}
	str_tri[19] = '\0';
//	ft_putstr("ft_display test after ft_left : \n\n");
	ft_putstr(str_tri);
	ft_putstr("\n\n");
}
