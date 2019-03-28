/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_to_tab.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: struxill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 11:24:33 by struxill          #+#    #+#             */
/*   Updated: 2019/03/28 11:57:08 by struxill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_convert_to_tab(char *str)
{
	char	**tab;
	int		i;
	int		len;
	int		start;

	len = ft_strlen(str);
	i = 0;
	start = 0;
	if (!(tab = (char**)malloc(sizeof(char*) * ((len + 1) / 21) + 1)))
		return (NULL);
	while ((i + 1) < (len + 1) / 21)
	{
		if (!(tab[i] = ft_strsub(str, start, 19)))
			return (NULL);
		i++;
		start = start + 21;
	}
	tab[i] = 0;
	return (tab);
}
