/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_insert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: struxill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 18:12:51 by struxill          #+#    #+#             */
/*   Updated: 2019/01/18 19:27:43 by struxill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_lst_insert(t_triminos *tri_list, int tri_placed, char letter)
{
	t_triminos	*start;
	t_triminos	*to_moved;
	t_triminos	*moved_to_next;

	start = tri_list;
	//je scroll jusqua avant le maillion de la bonne lettre
	while (tri_list->next->letter != letter)
	{
		tri_list = tri_list->next;
	}
	to_moved = tri_list->next; //liens vers le maillon qui va etre inserer
	tri_list->next = tri_list->next->next; //relink et skip du maillon deplace
	//reset en haut
	tri_list = start;
	//scroll jusqu'au dernier maillon place
	while (tri_placed > 1)
	{
		tri_list = tri_list->next;
		tri_placed--;
	}
	moved_to_next = tri_list->next; //lien vers le maillons d'apres le dernier place 
	tri_list->next = to_moved; //le dernier maillon pointe vers celui qui est insere ici
	tri_list = tri_list->next; //je bouge sur le maillon inserer
	tri_list->next = moved_to_next; //le maillons inserer pointe vers celui qui etait la avant.
}
