/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 12:17:16 by mybenzar          #+#    #+#             */
/*   Updated: 2019/03/22 20:24:13 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_free_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		if (!tab[i])
			return ;
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab[i]);
	tab[i] = NULL;
	free(tab);
	tab = NULL;
}
