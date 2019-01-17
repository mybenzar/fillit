/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 16:30:29 by mybenzar          #+#    #+#             */
/*   Updated: 2019/01/17 19:49:51 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_create_tab(int size)
{
	int		i;
	char	**tab;
	char	*s1;

	i = 0;
	s1 = ft_strnew((int)size);
	if (!(tab = (char**)malloc(sizeof(char*) * (size + 1))))
		return (NULL);
	while (i < size)
		s1[i++] = '.';
	s1[i] = '\0';
	i =  0;
	while (i < size)
	{
		tab[i] = ft_strdup(s1);
		i++;
	}
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
		if (!tab[i][j])
			i++;
	}
	*l = i;
	*c = j;
	//revoir
}

int		ft_place(t_triminos *list, char **tab, int l, int c, char *letter_ptr)
{
	char	letter;
	int		i;
	int		j;
	int		k;
	t_triminos	tmp;
	
	letter = *letter_ptr;

	i = -1;
	tmp = *list;
	ft_find(tab, &l, &c);
	while (++i <= 3)
	{
		j = c + tmp.pos[i].x;
		k = l + tmp.pos[i].y;
		if (tab[k][j] == '.' && tab[k][j])
			tab[k][j] = letter;

		else if (!tab[k][j])
			ft_place(list, tab, l++, 0, &letter);
		//revoir ligne suivantem, pertinence?
		else if (!tab[k])
			ft_place(list, tab, 0, c++, &letter);
		else
			return (0);
	}
	letter++;
	*letter_ptr = letter;
	return (1);
}

void	ft_browse(char **tab, t_triminos *list, int size_tab)
{
	t_triminos	*tmp;
	char		letter;
	int 		c;
	int			l;

	c = 0;
	l = 0;
	tmp = list;
	letter = 'A';
	while (tmp)
	{
		// cherche l et c tel que tab[l][c] est un emplacement vide // pertinence ici ?:
		ft_find(tab, &l, &c);
		ft_putnbr(l);
		ft_putchar(',');
		ft_putnbr(c);
		ft_putchar('\n');
		// s'il arrive a placer le minos, passe au minos suivant :
		if (ft_place(tmp, tab, l, c, &letter))
		{
			tmp = tmp->next;
		}
		// s'il n'arrive a le placer nulle part, essayer de placer le suivant a la place
		else
		{
			tmp = tmp->next;
			ft_putendl("hello");
			//appeler ici la fonction qui remet le minos precedent a la fin de la chaine
			ft_browse(tab, tmp, size_tab);
		}
		// pour faire toutes les combinaisons, il faut remettre a chaque fois le premier maillon de la chaine a la fin
		// par exemple, si on commence par 2, il faut remettre 1 a la fin de la chaine
	}
	//a essaye tous les minos mais aucune combinaison ne marche : free le tableau, l'agrandir et reessayer
	// condition d'arret de la recursion
	if (ft_list_size(list) == letter - 64)
		return ;
	free(tab);
	size_tab++;
	ft_browse(ft_create_tab(size_tab), list, size_tab);


	tab = ft_create_tab(size_tab);
	ft_browse(tab, list, size_tab)
}
