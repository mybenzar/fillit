/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tri_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: struxill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 17:59:41 by struxill          #+#    #+#             */
/*   Updated: 2019/01/16 19:22:17 by struxill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

t_triminos ft_tri_pos(t_list *list)
{
	t_triminos	triminos;
	int 		nb;
	int 		i;
	int 		j;
	char		tmpstr[20];

	nb = 0;
	i = 0;
	j = 0;
	ft_strncpy(tmpstr, list->content, 19); 
//	printf("list content = %s\n", tmpstr);
	while (nb < 4)
	{
//		printf("str[%i] = %c\n", (i + (j * 5)), tmpstr[i + (j * 5)]); 
		if (tmpstr[i + (j * 5)] == '#')
		{
			triminos.pos[nb].x = i;
//			printf("assignation de pos[%i].x = %i\n", nb, i);
			triminos.pos[nb].y = j;
//			printf("assignation de pos[%i].y = %i\n", nb, j);
			nb++;
			if (nb == 4)
				break;
		}
//		list->content++;
//		printf("list->content = %i\n", (int)list->content);
		i++;
		if (i == 5)
		{
			j++;
			i = 0;
//			printf("reset i = 0, j = %i\n", j);
		}
	}	
//	printf("\n x de pos 0 = %i\n", triminos.pos[0].x);
//	printf("y de pos 0 = %i\n", triminos.pos[0].y);
//	printf("\n x de pos 1 = %i\n", triminos.pos[1].x);
//	printf("y de pos 1 = %i\n", triminos.pos[1].y);
//	printf("\n x de pos 2 = %i\n", triminos.pos[2].x);
//	printf("y de pos 2 = %i\n", triminos.pos[2].y);
//	printf("\n x de pos 3 = %i\n", triminos.pos[3].x);
//	printf("y de pos 3 = %i\n", triminos.pos[3].y);
	return (triminos);
}
