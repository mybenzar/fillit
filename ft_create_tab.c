/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 12:15:00 by mybenzar          #+#    #+#             */
/*   Updated: 2019/01/30 12:18:17 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char **ft_create_tab(int size)
{
	int i;
	char **tab;
	char *s1;

	i = -1;
	s1 = ft_strnew((int)size);
	if (!(tab = (char**)malloc(sizeof(char*) * (size + 1))))
		return (NULL);
	while (++i < size)
		s1[i] = '.';
	s1[i] = '\0';
	i = -1;
	while (++i < size)
		tab[i] = ft_strdup(s1);
	tab[i] = 0;
	return (tab);
}
