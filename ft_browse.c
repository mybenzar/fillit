/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_browse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 14:10:45 by mybenzar          #+#    #+#             */
/*   Updated: 2019/02/06 18:34:51 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

char	**ft_browse(char **tab, t_triminos *list, int size_tab)
{
	t_triminos	*tmp;
	int			tri_placed;
	int 		i;
	char		letter;
	int			stepback;

	tri_placed = 0;
	tmp = list;
	tab = ft_create_tab(size_tab);
	i = 0;
	stepback = 0;
	while (tri_placed < ft_list_size(list))
	{
		if (!stepback && ft_place(tmp, tab, 0, 0))
		{
			ft_putendl("rentre dans la boucle ft_place = 1");
			tri_placed++;
			letter = tmp->letter;
			tmp = tmp->next;
			ft_display_tab(tab);
		}
		// s'il n'arrive a le placer nulle part, essayer de placer le suivant a la place
		else
		{
			printf("TEST on rentre dans le else, lettre = %c\n", letter);
			
			if (ft_del(letter, tab))  // DEL de C, lettre toujours C
			{
				printf("rentre dans if ft_del\n");
				printf("del de %c\n", letter);
				ft_display_tab(tab);
				tri_placed--; //tri_placed = 2
			}
/*			if (!stepback)
			{
				printf("rentre dans if !stepback\n");
				tmp = list;
				while (tmp->letter != ft_find_letter(list, tri_placed) && tmp->next)
					tmp = tmp->next;
				letter = tmp->letter;
				if (ft_del(letter, tab))  // DEL de C, lettre toujours C
				{
					printf("del de %c\n", letter);
					ft_display_tab(tab);
					tri_placed--; //tri_placed = 2
				}
			} */
			stepback = 0;
			ft_lst_sort(list, tri_placed + 1);
			ft_display_tri_lst(list);
			
			//si la lettre suivante existe et nest pas deja utilise
			if (ft_next_valid_letter(list, letter, tab))
			{
				printf("list a valid letter, et tmp->letter = %c\n", tmp->letter);
		//		ft_display_tri_lst(list);
				letter = ft_next_valid_letter(list, letter, tab); // lettre = C
				printf("next valid letter : %c, tri_placed : %i\n", letter, tri_placed);
				list = ft_lst_insert(list, tri_placed, letter); //insert de C en 2 pour ACBDEF
		//		ft_display_tri_lst(list);
		//		printf("ft_lst_sort de la list\n");
				ft_lst_sort(list, tri_placed + 1); //tri a pqrtir de tri placed
		//		printf("\nNouvelle liste :\n");
				ft_display_tri_lst(list);
				tmp = list;
				while (tmp->letter != letter && tmp->next)
					tmp = tmp->next;
			}
			else 			//si letter ++ nexiste pas (G) il a tout teste
			{
		//		printf("il ny a pas de lettre apres  %c, tri_placed = %i\n", letter, tri_placed);
				if (tri_placed == 0)
					break ;			//break qui fait sortir de la loop si ya plus de lettre valide 
		//		tmp = ft_lst_sort(list, (tri_placed - 1)); //HEAD sur le maillon davant
				letter = ft_find_letter(list, tri_placed);
				printf("stepback sur letter %c\n", letter);
				stepback = 1;
				// replacer tete de liste sur E
		//		if (stepback == 0)
		//			stepback = 1;
		//		else
		//			stepback = 0;
					//sert a remonter dun cran quand ya plus de lettre valide a tester;
			}
		}
	}
		if (ft_list_size(list) == tri_placed)
		{
			ft_putendl("rentre dans la condition d'arret");
	//		printf("tri_placed = %i\n", tri_placed);
			//			printf("list size : %i\n", ft_list_size(list));
			return (tab);
		}
		ft_putendl("tableau trop petit \n");
		ft_free_tab(tab);
		size_tab++;
		
	//	ft_display_tri_lst(list);
		list = ft_lst_insert(list, 0, 'A'); //condition necessaire au reset de lst sort
		ft_lst_sort(list, 0); 
	//	printf("Liste fraichement trier avant nouveau tableau plus grand\n");
	//	ft_display_tri_lst(list);

		tab = ft_browse(tab, list, size_tab);
		return (tab);
	}
