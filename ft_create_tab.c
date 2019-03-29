/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 12:15:00 by mybenzar          #+#    #+#             */
/*   Updated: 2019/03/29 12:04:24 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_create_tab(int size)
{
	int		i;
	char	**tab;
	char 	*s1;

	i = 0;
	if (!(tab = (char**)malloc(sizeof(char*) * (size + 1))))
		return (NULL);
	s1 = ft_strnew(size);
	ft_memset(s1, '.', size);
	while (i < size)
	{
		tab[i] = ft_strdup(s1);
		i++;
	}
	free(s1);
	tab[size] = 0;
	return (tab);
}
