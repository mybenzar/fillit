/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_diese_nb.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: struxill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 16:10:07 by struxill          #+#    #+#             */
/*   Updated: 2019/02/07 17:38:55 by struxill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

// A SUPPRIMER, remplacee maintenant par ft_check.

int	ft_check_diese_nb(t_list *list)
{
	int		count;
	int		i;
	char	tmp_str[21];

	while (list)
	{
		count = 0;
		i = 0;
		ft_strncpy(tmp_str, list->content, 20);
		while (tmp_str[i])
		{
			if (tmp_str[i] == '#')
				count++;
			i++;
		}
		if (count != 4)
			return (0);
		list = list->next;
	}
	return (1);
}
