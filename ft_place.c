/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 16:30:29 by mybenzar          #+#    #+#             */
/*   Updated: 2019/01/31 21:56:50 by struxill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		ft_find(char **tab, int *l, int *c)
{
	int	i;
	int j;

	i = *l;
	j = *c;
	while (tab[i][j] != '.' && tab[i][j] && tab[i])
	{
		j++;
		if (tab[i][j] == '\0')
		{
			j = 0;
			if (tab[i + 1])
				i++;
			else
				return (0);
		}
	}
	*l = i;
	*c = j;
	return (1);
	//	printf("fd find valide pour [%i, %i]\n", j, i);
}

// ft_test va chercher sur toute la ligne s'il peut placer le mino
int		ft_test(t_triminos *list, char **tab, int *l, int *c)
{
	int 		i;
	int 		j;
	int 		k;
	int			col;
	t_triminos	*tmp;

	tmp = list;
	col = 0;
	if (ft_find(tab, l, c))
	{
		i = 0;
		while (i <= 3)
		{
			j = col + tmp->pos[i].x;
			k = *l + tmp->pos[i].y;
			if (tab[k] == 0 || tab[k][j] == '\0')
				return (0);
			else if (tab[k][j] == '.')
				i++;
			else
			{
				i = 0;
				col++;
			}
		}
		*c = col;
		//	*l = line;
		printf("Dernier point teste valide : [%i, %i]\n", *l, col);
		return (1);
	}
	else
		return (0);
}

int		ft_place(t_triminos *list, char **tab, int l, int c)
{
	int			i;
	int			j;
	int			k;
	t_triminos	*tmp;

	i = -1;
	tmp = list;
	//	printf("l = %d\n", l);
	if (ft_test(tmp, tab, &l, &c))
	{
		while (++i <= 3)
		{
			j = c + tmp->pos[i].x;
			k = l + tmp->pos[i].y;
			printf("k = %d, j = %d\n", k, j);
			tab[k][j] = tmp->letter;
		}
		return (1);
	}
	// si le test a echoue pour la ligne 'l' mais qu'il n'existe pas de ligne suivante
	else if (!ft_test(tmp, tab, &l, &c) && !tab[l + 1])
		return (0);
	// si le test a echoue pour la ligne 'l' et que la  ligne suivante existe, le placer a la ligne suivante
	else if (!ft_test(tmp, tab, &l, &c) && tab[l + 1])
	{
		if (ft_place(tmp, tab, ++l, 0))
			return (1);
		else
			return (0);
	}
	return (0);
}



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
		// s'il arrive a placer le minos, passe au minos suivant :
		//printf("ft_place renvoie = %i pour le mino %c \n", ft_place(tmp, tab, l, c), tmp->letter);
		if (!stepback && ft_place(tmp, tab, 0, 0))
		{
			ft_putendl("rentre dans la boucle ft_place = 1");
			tri_placed++;
			letter = tmp->letter;
			tmp = tmp->next;
			ft_display_tab(tab);
		}
		// s'il n'arrive a le placer nulle part, essayer de placer le suivant a la place

		// NOUVEAU BLOC else 
		// EXEMPLE pour ABCDEF avec ABC qui rentre et D non.
		// ABC sont dans le tableau, tri_placed = 3, letter = C;
		else
		{
			printf("on rentre dans le else, lettre = %c\n", letter);
			
			if (ft_del(letter, tab))    	// DEL de C, lettre toujours C
			{
				printf("del de %c\n", letter);
				ft_display_tab(tab);
				tri_placed--; //tri_placed = 2
			}
			stepback = 0;
	//		tmp = ft_lst_sort(list, tri_placed); // pointe sur B
			
			//si la lettre suivante existe et nest pas deja utilise
			if (ft_next_valid_letter(list, letter))
			{
				letter = ft_next_valid_letter(list, letter); // lettre = C
				printf("next valid letter : %c, tri_placed : %i\n", letter, tri_placed);
				list = ft_lst_insert(list, tri_placed, letter); //insert de C en 2 pour ACBDEF
				ft_display_tri_lst(list);
				printf("ft_lst_sort de la list\n");
				ft_lst_sort(list, tri_placed + 1); //tri a pqrtir de tri placed
				printf("\nNouvelle liste :\n");
				ft_display_tri_lst(list);
				tmp = list;
				while (tmp->letter != letter && tmp->next)
					tmp = tmp->next;
			}
			else 			//si letter ++ nexiste pas (G) il a tout teste
			{
				printf("il ny a pas de lettre apres  %c, tri_placed = %i\n", letter, tri_placed);
				if (tri_placed == 0)
					break ;			//break qui fait sortir de la loop si ya plus de lettre valide 
		//		tmp = ft_lst_sort(list, (tri_placed - 1)); //HEAD sur le maillon davant
				letter = ft_find_letter(list, tri_placed);
				printf("stepback sur letter %c\n", letter);
				// replacer tete de liste sur E
				stepback = 1; //sert a remonter dun cran quand ya plus de lettre valide a tester;
			}
		}
	}
			/*
			// peut etre mettre directement le while d'en dessous ici
			if (tmp->next)
			{
				while (tmp->next && !ft_test_for_lst_place(tmp, tab))
					tmp = tmp->next;
				if (ft_test_for_lst_place(tmp, tab))
					list = ft_lst_insert(list, tri_placed, tmp->letter);
			} */
			// si on echoue avec toute les combinaisons a tri_placed
			// A VERIFIER : dans lidee cest de rappeler avec tri placed -- MAIS IL NEST PAS ENCORE EFFACEE.
			/*else
			  {
			  printf("rentre dans le dernier else\n");
			//printf("affichage du tableau apres avoir supprime la lettre '%c'\n", 65 + i);
			while (tmp->letter != 
			list = ft_lst_sort(list);
			ft_display_tri_lst(list);
			i++;
			tri_placed--;
			list = ft_lst_insert(list, tri_placed, 65 + i);
			ft_display_tri_lst(list);
			tmp = list;*/
			//si on a echoue avec toutes les combinaisons commencant par une lettre :
	
			/*
			else
			{

				ft_putendl("Nouvelle premiere lettre");
				ft_free_tab(tab);
				tab = ft_create_tab(size_tab);
				ft_display_tab(tab);
				list = ft_lst_sort(list);
				i++;
				tri_placed = 0;
				list = ft_lst_insert(list, 0, 65 + i);
				tmp = list;
				//			printf("AFFICHAGE NEW LIST\n");
				//			ft_display_tri_lst(list);
			} */
		// condition d'arret de la recursion :
		if (ft_list_size(list) == tri_placed)
		{
			ft_putendl("rentre dans la condition d'arret");
			printf("tri_placed = %i\n", tri_placed);
			//			printf("list size : %i\n", ft_list_size(list));
			return (tab);
		}
		ft_putendl("tableau trop petit \n");
		ft_free_tab(tab);
		size_tab++;
		
		ft_display_tri_lst(list);
		list = ft_lst_insert(list, 0, 'A'); //condition necessaire au reset de lst sort
		ft_lst_sort(list, 0); 
		printf("Liste fraichement trier avant nouveau tableau plus grand\n");
		ft_display_tri_lst(list);

		tab = ft_browse(tab, list, size_tab);
		return (tab);
	}


