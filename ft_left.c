/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_left.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 16:30:17 by mybenzar          #+#    #+#             */
/*   Updated: 2019/02/01 21:23:51 by struxill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

t_triminos	ft_left(t_triminos triminos)
{
	t_triminos new_tri;

	new_tri = triminos;
/*
	while (new_tri.pos[0].x > 0 && new_tri.pos[1].x > 0 && new_tri.pos[2].x > 0 && new_tri.pos[3].x > 0)
	{
		new_tri.pos[0].x--;
		new_tri.pos[1].x--;
		new_tri.pos[2].x--;
		new_tri.pos[3].x--;
	}
	while (new_tri.pos[0].y > 0 && new_tri.pos[1].y > 0 && new_tri.pos[2].y > 0 && new_tri.pos[3].y > 0)
	{
		new_tri.pos[0].y--;
		new_tri.pos[1].y--;
		new_tri.pos[2].y--;
		new_tri.pos[3].y--;
	}
*/

	// MAJ des coordonnes en relatif par rapport au premier.
	while (new_tri.pos[0].x > 0)
	{
		new_tri.pos[0].x--;
		new_tri.pos[1].x--;
		new_tri.pos[2].x--;
		new_tri.pos[3].x--;
	}
	while (new_tri.pos[0].y > 0)
	{
		new_tri.pos[0].y--;
		new_tri.pos[1].y--;
		new_tri.pos[2].y--;
		new_tri.pos[3].y--;
	}
//	printf("Coordonnes du triminos en sortie de ft_left :\n");
//	printf("\nDiese 0 : [%i, %i]\n", new_tri.pos[0].x, new_tri.pos[0].y);
//	printf("Diese 1 : [%i, %i]\n", new_tri.pos[1].x, new_tri.pos[1].y);
//	printf("Diese 2 : [%i, %i]\n", new_tri.pos[2].x, new_tri.pos[2].y);
//	printf("Diese 3 : [%i, %i]\n\n", new_tri.pos[3].x, new_tri.pos[3].y);

	return (new_tri);
}
