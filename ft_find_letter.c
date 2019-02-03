/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_letter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 17:17:53 by mybenzar          #+#    #+#             */
/*   Updated: 2019/01/31 21:16:46 by struxill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	ft_find_letter(t_triminos *list, int tri_placed)
{
	int			i;
	t_triminos	*tmp;

	tmp = list;
	i = 1;
	while (i < tri_placed && tmp->next)
	{
		tmp = tmp->next;
		i++;
	}
	if (tmp->letter > 64 && tmp->letter < 91)
		return (tmp->letter);
	ft_putendl("error de ft_find_letter");
	return (0);
}
