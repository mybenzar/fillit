/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_insert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: struxill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 18:12:51 by struxill          #+#    #+#             */
/*   Updated: 2019/01/31 21:56:52 by struxill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

/*
 * NOTES D'UTILISATIONS LIEES AUX MODIFS :
 *
 * changement du type de la fonction en t_triminos *ft_lst_instert (au lieu de void)
 * car dans le cas ou aucun triminos de rentre et on veux mettre par exemple le D en premier, si je ne te renvois pas un pointeur vers le D qui est la nouvelle tete de liste il n'apparait pas. Donc il faut utiliser la fonction en faisant :
 *
 *
 * tri_list = ft_lst_instert(tri_list, placed, letter);
 *
 * NOTES ADDITIONNELLES :
 *
 * ex : Une lettre ne peux que etre remontee dans la liste, pas descendue.
 * Si la fonction est appeler comme ca ca met "Les paramettres de ft_lst_insert ne sont pas valide" et ca renvois la liste originale (et ca evite le segfault)
 * ex : si la lettre A est appelee, ca change rien.
 * Si la lettre appelle n'existe pas ca met erreur et renvois la liste originale.
 * Si le chiffre depasse le nombre de maillons ca met erreur et renvois la liste originale.
 *
 * Jai bien tout test et normalement y'a plus de SEGFAULT[s] !!
 * 	*/

int			ft_check_insert_params(t_triminos *tri_list, int placed, char letter)
{
	int check;
	int	list_len;

	check = 0;
	list_len = ft_list_size(tri_list);
//	printf("list size is : %i\n", list_len);
	if (list_len >= (letter - 64) && placed >= 0)
		check = 1;
	else
		printf("\nles parametres de ft_lst_insert ne sont pas valides !!\n\n");
   return (check);
}

t_triminos	*ft_lst_insert(t_triminos *tri_list, int placed, char letter)
{
	t_triminos	*start;
	t_triminos	*to_moved;
	t_triminos	*moved_to_next;

	start = tri_list;
	if (tri_list->letter == letter || ft_check_insert_params(tri_list, placed, letter) == 0)
		return (tri_list);
	else
	{
		//je scroll jusqua avant le maillion de la bonne lettre
		while (tri_list->next->letter != letter && tri_list->next)
		{
			tri_list = tri_list->next;
		}
		to_moved = tri_list->next; //liens vers le maillon qui va etre inserer
		if (tri_list->next->next)
			tri_list->next = tri_list->next->next; //relink et skip du maillon deplace
		else
			tri_list->next = NULL;
	}
	//reset en haut
	tri_list = start;
	//scroll jusqu'au dernier maillon place
	if (placed == 0)
	{
		moved_to_next = tri_list;
		tri_list = to_moved;
		tri_list->next = moved_to_next;
//		ft_display_tri_lst(tri_list);
	}
	else
	{
		while (placed > 1 && tri_list->next)
		{
			tri_list = tri_list->next;
			placed--;
			//moved_to_next = tri_list->next; 
		}
		moved_to_next = tri_list->next; //lien vers le maillons d'apres le dernier place
		tri_list->next = to_moved; //le dernier maillon pointe vers celui qui est insere ici
		tri_list = tri_list->next; //je bouge sur le maillon inserer
		tri_list->next = moved_to_next; //le maillons inserer pointe vers celui qui etait la avant.
		tri_list = start;
	}
	return (tri_list);
}
