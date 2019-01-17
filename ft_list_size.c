/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: struxill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 19:51:35 by struxill          #+#    #+#             */
/*   Updated: 2019/01/16 20:04:50 by struxill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_list_size(t_triminos *tri_list)
{
	int i;

	i = 1;
	while (tri_list->next)
	{
		i++;
		tri_list = tri_list->next;
	}
	return (i);
}
