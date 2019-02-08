/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_to_t_list.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: struxill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 17:52:18 by struxill          #+#    #+#             */
/*   Updated: 2019/02/08 14:22:06 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_list	*ft_convert_to_t_list(char *str)
{
	t_list	*start;
	int		i;
	int		len;

	len = ft_strlen(str);
	i = 1;
	start = ft_lstnew(str, 19);
	start->content_size = i;
	str = str + 21;
	while (i < (len + 1) / 21)
	{
		i++;
		ft_lstadd(&start, ft_lstnew(str, 19));
		start->content_size = i;
		str = str + 21;
	}
	return (start);
}
