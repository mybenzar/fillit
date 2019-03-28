/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_and_convert.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: struxill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 15:49:06 by struxill          #+#    #+#             */
/*   Updated: 2019/03/28 13:58:06 by struxill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_triminos	*ft_check_and_convert(char *str)
{
	t_list		*tmp_list;
	t_triminos	*tri_list;

	if (ft_check(str))
	{
		tmp_list = ft_convert_to_t_list(str);
		if (DEBUG)
			ft_lst_aff(tmp_list);
		tri_list = ft_t_list_to_tri_list(tmp_list);
		ft_lstfree(tmp_list);
		tmp_list = NULL;
		if (ft_check_shape(tri_list))
		{
			ft_assign_letter(tri_list);
			return (tri_list);
		}
		else
		{
			ft_lst_free(tri_list);
			tri_list = NULL;
		}
	}
	return (NULL);
}
