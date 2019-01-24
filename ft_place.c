/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 16:30:29 by mybenzar          #+#    #+#             */
/*   Updated: 2019/01/24 20:35:17 by mybenzar         ###   ########.fr       */
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

int		ft_test(t_triminos *list, char **tab, int l, int c)
{
	int i;
	int j;
	int k;

	i = -1;
	tmp = list;
	ft_find(tab, &l, &c);
	while (++i <= 3)
	{
		j = c + tmp->pos[i].x;
		k = l + tmp->pos[i].y;
		if (tab[k][j] == '.')
			i++;
		else
			return (0);
	}
	return (1);
	
}

void	ft_del(t_triminos *list, char **tab)
{
	int 		l;
	int 		c;
	t_triminos	*tmp;

	while (tab[l])
	{
		while (tab[l][c])
		{
			if (tab[l][c] == tmp->letter)
				tab[l][c] == '.';
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
	}
	else 
	{
		ft_del(tmp, tab);
		ft_place(tmp, tab, l++, 0);
		
		/*else if (tab[k][j] == '\0')
		{
			i = -1;
			while (++i <= 3)
			{
				j = c + tmp->pos[i].x;
				k = l + tmp->pos[i].y;
		//		printf("k = %c, j = %c\n", k, j);
				if (tab[k][j] == tmp->letter)
					tab[k][j] = '.';
			}
			ft_place(tmp, tab, l++, 0);
		}*/
			return (0);
	}
	return (1);
}

char	**ft_browse(char **tab, t_triminos *list, int size_tab)
{
	t_triminos	*tmp;
	int 		c;
	int			l;
	int			tri_placed;
	int i;

	c = 0;
	l = 0;
	tri_placed = 0;
	tmp = list;
	tab = ft_create_tab(size_tab);
	while (ft_list_size(list) != tri_placed)
	{
		// s'il arrive a placer le minos, passe au minos suivant :
		if (ft_place(tmp, tab, l, c))
		{
			tri_placed++;
			tmp = tmp->next;
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
				list = ft_sort_list(list);
				i++;
				ft_lst_insert(list, 0, 65 + i)
			}
		}
		// condition d'arret de la recursion :
		if (ft_list_size(list) == tri_placed)
			return (tab);
	}
	ft_putendl("tableau trop petit \n");
	ft_free_tab(tab);
	size_tab++;
	list = ft_sort_list(list);
	tab = ft_browse(tab, list, size_tab);
	return (tab);
}

