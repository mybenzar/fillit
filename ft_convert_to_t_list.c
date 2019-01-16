/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_to_t_list.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: struxill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 17:52:18 by struxill          #+#    #+#             */
/*   Updated: 2019/01/16 15:14:05 by struxill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_list	*ft_convert_to_t_list(char *str)
{
	t_list	*start;
	int 	i;
	int		len;

	len = ft_strlen(str);
	i = 1;
	start = ft_lstnew(str, 19);
	start->content_size = i;
	i++;
	str = str + 21;
	while (i - 1 < len / 20)
	{
		ft_lstadd(&start, ft_lstnew(str, 19));
		start->content_size = i;
		i++;
		str = str + 21;
	}
	return (start);
}
