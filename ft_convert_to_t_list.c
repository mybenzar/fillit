/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_to_t_list.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: struxill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 17:52:18 by struxill          #+#    #+#             */
/*   Updated: 2019/03/29 12:26:08 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_list	*ft_convert_to_t_list(char *str)
{
	t_list	*start;
	t_list  *tmp;
	size_t	i;
	int 	gap;
	
	i = 1;
	gap = 21;
	start = ft_lstnew(ft_strsub(str, 0, 19), i);
	while (i < (ft_strlen(str) + 1) / 20)
	{
		i++;
		tmp = ft_lstnew(ft_strsub(str, gap, 19), i);
		ft_lstadd(&start, tmp);
		gap = gap + 21;
	}
	return (start);
}
