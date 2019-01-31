/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_letter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 17:17:53 by mybenzar          #+#    #+#             */
/*   Updated: 2019/01/31 17:57:11 by struxill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	ft_find_letter(t_triminos *list, int tri_placed)
{
	int			i;
	t_triminos	*tmp;

	tmp = list;
	i = 0;
	while (++i < tri_placed && tmp->next)
		tmp = tmp->next;
	return (tmp->letter);
}
