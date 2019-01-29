/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 16:30:29 by mybenzar          #+#    #+#             */
/*   Updated: 2019/01/29 17:53:46 by struxill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

char	**ft_create_tab(int size)
{
	int		i;
	char	**tab;
	char	*s1;

	i = -1;
	s1 = ft_strnew((int)size);
	if (!(tab = (char**)malloc(sizeof(char*) * (size + 1))))
		return (NULL);
	while (++i < size)
		s1[i] = '.';
	s1[i] = '\0';
	i =  -1;
	while (++i < size)
		tab[i] = ft_strdup(s1);
	tab[i] = 0;
	return (tab);
}

void	ft_find(char **tab, int *l, int *c)
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
			i++;
		}
	}
	*l = i;
	*c = j;
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
//	int			line;

	tmp = list;
	col = 0;
//	printf("l = %p", l);
//	line = *l;

/////////////  CI DESSOUS EST MORT LE PROBLEME DU CCC QUI MANGE LE BB !!!!! 
/////////////	avant : ft_find(tab, l, c);

	ft_find(tab, l, c);
//	printf("ft_find dans ft_test renvoie line = %d\n", line); 
	i = 0;
	while (i <= 3)
	{
		////////// ca fonctionne pareil avec k = line ... ou k = *l ...
		j = col + tmp->pos[i].x;
		k = *l + tmp->pos[i].y;
	
//		printf("k = %d, j = %d\n", k, j);
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

void	ft_del(int letter, char **tab)
{
	int 		l;
	int 		c;

	l = 0;
	while (tab[l])
	{
		c = 0;
		while (tab[l][c])
		{
			if (tab[l][c] == letter)
				tab[l][c] = '.';
			c++;
		}
		l++;
	}
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
	char		end_char;
	int			flag_end_loop;

	tri_placed = 0;
	tmp = list;
	tab = ft_create_tab(size_tab);
	ft_putendl("tableau cree");
	i = 0;
	flag_end_loop = 1;
	while (i < ft_list_size(list))
	{
		// s'il arrive a placer le minos, passe au minos suivant :
		//printf("ft_place renvoie = %i pour le mino %c \n", ft_place(tmp, tab, l, c), tmp->letter);
		if (ft_place(tmp, tab, 0, 0))
		{
			ft_putendl("rentre dans la boucle ft_place = 1");
			tri_placed++;
			tmp = tmp->next;
			ft_display_tab(tab);
		}
		// s'il n'arrive a le placer nulle part, essayer de placer le suivant a la place
		else
		{
			// Essaie Sim
			if ((tmp->next) && flag_end_loop)
			{

				ft_putendl("rentre dans la boucle tmp->next");
				printf("tmp->letter = %c\n", tmp->letter);
				if (tmp->next->letter == end_char)
				{
					list = ft_lst_insert(list, tri_placed, end_char);
					if (!tmp->next)
					{
						flag_end_loop = 0;
						printf("flag a zero\n");
					}
				}
				end_char = tmp->letter;
				if (tmp->next)
				{
					tmp = tmp->next;
					list = ft_lst_insert(list, tri_placed, tmp->letter);
				}
			}
/*			if (tmp->next)
			{
			//////// probleme de rentrer dans cette boucle a linfinie malgres la nouvelle condition
				ft_putendl("rentre dans la boucle tmp->next");
				
				end_char = tmp->letter; //end_char == C

				tmp = tmp->next; // tmp == D
				list = ft_lst_insert(list, tri_placed, tmp->letter);
				if (tmp->next->letter == end_char)

				
		//		ft_display_tri_lst(list);
			}  */
			//si on a echoue avec toutes les combinaisons commencant par une lettre :
			else
			{

				ft_putendl("rentre dans le dernier else");
				ft_free_tab(tab);
				tab = ft_create_tab(size_tab);
				//ft_del(64 + tri_placed, tab);
				ft_display_tab(tab);
				list = ft_lst_sort(list);
				i++;
				tri_placed = 0;
				list = ft_lst_insert(list, 0, 65 + i);
				tmp = list;
				flag_end_loop = 1;
	//			printf("AFFICHAGE NEW LIST\n");
	//			ft_display_tri_lst(list);
			}
		}
		// condition d'arret de la recursion :
		if (ft_list_size(list) == tri_placed)
		{
			ft_putendl("rentre dans la condition d'arret");
			printf("tri_placed = %i", tri_placed);
//			printf("list size : %i\n", ft_list_size(list));
			return (tab);
		}
	}
	ft_putendl("tableau trop petit \n");
	ft_free_tab(tab);
	size_tab++;
	list = ft_lst_sort(list);
	tab = ft_browse(tab, list, size_tab);
	return (tab);
}


