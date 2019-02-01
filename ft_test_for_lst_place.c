/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_for_lst_place.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 19:00:56 by mybenzar          #+#    #+#             */
/*   Updated: 2019/02/01 19:33:25 by struxill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_test_for_lst_place(t_triminos *list, char **tab)
{
	t_triminos	*tmp;
	int			l;
	int			c;

	l = 0;
	c = 0;
	tmp = list;
	if (ft_test(tmp, tab, &l, &c))
		return (1);
	else if (!ft_test(tmp, tab, &l, &c) && !tab[l + 1])
		return (0);
	else if (!ft_test(tmp, tab, &l, &c) && tab[l + 1])
	{
		l++;
		c = 0;
		if (ft_test(tmp, tab, &l, &c))
			return (1);
	}
	return (0);
}
