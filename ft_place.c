/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 16:30:29 by mybenzar          #+#    #+#             */
/*   Updated: 2019/01/26 16:47:05 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
	while (tab[i][j] != '.' && tab[i][j])
	{		
		j++;
		if (tab[i][j] == '\0')
			i++;
	}
	*l = i;
	*c = j;
}

// ft_test va chercher sur toute la ligne s'il peut placer le mino
int		ft_test(t_triminos *list, char **tab, int l, int c)
{
	int 		i;
	int 		j;
	int 		k;
	t_triminos	*tmp;


	tmp = list;
	ft_find(tab, &l, &c);
	i = 0;
	while (i <= 3 && tab[l][c])
	{
		j = c + tmp->pos[i].x;
		k = l + tmp->pos[i].y;
		if (tab[k][j] == '.')
			i++;
		else if (tab[k][j] =='\0')
			return (0);
		else
		{
			i = 0;
			c++;
		}
	}
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
	if (ft_test(tmp, tab, l, c))
	{
		while (++i <= 3)
		{
			j = c + tmp->pos[i].x;
			k = l + tmp->pos[i].y;
			tab[k][j] = tmp->letter;
		}
		return (1);
	}
	// si le test a echoue pour la ligne 'l' mais qu'il n'existe pas de ligne suivante
	else if (!ft_test(tmp, tab, l, c) && !tab[l + 1])
		return (0);
	// si le test a echoue pour la ligne 'l' et que la  ligne suivante existe, le placer a la ligne suivante
	else if (!ft_test(tmp, tab, l, c) && tab[l + 1])
	{
		if (ft_place(tmp, tab, l + 1, 0))
			return (1);
		else
			return (0);
	}
	return (0);
}



char	**ft_browse(char **tab, t_triminos *list, int size_tab)
{
	t_triminos	*tmp;
	int 		c;
	int			l;
	int			tri_placed;
	int 		i;

	tri_placed = 0;
	tmp = list;
	tab = ft_create_tab(size_tab);
	ft_putendl("tableau cree");
	while (ft_list_size(list) != tri_placed)
	{
		c = 0;
		l = 0;
		// s'il arrive a placer le minos, passe au minos suivant :
		//printf("ft_place renvoie = %i pour le mino %c \n", ft_place(tmp, tab, l, c), tmp->letter);
		if (ft_place(tmp, tab, l, c))
		{
			tri_placed++;
			tmp = tmp->next;
			ft_display_tab(tab);
		}
		// s'il n'arrive a le placer nulle part, essayer de placer le suivant a la place
		else
		{
			if (tmp->next)
			{
				tmp = tmp->next;
				ft_lst_insert(list, tri_placed, tmp->letter);	
			}
			//si on a echoue avec toutes les combinaisons commencant par une lettre :
			else
			{
				ft_del(64 + tri_placed, tab);
				list = ft_lst_sort(list);
				i++;
				ft_lst_insert(list, 0, 65 + i);
				ft_putnbr(i);
				ft_putchar('\n');
			}
		}
		// condition d'arret de la recursion :
		if (ft_list_size(list) == tri_placed)
			return (tab);
	}
	ft_putendl("tableau trop petit \n");
	ft_free_tab(tab);
	size_tab++;
	list = ft_lst_sort(list);
	tab = ft_browse(tab, list, size_tab);
	return (tab);
}


