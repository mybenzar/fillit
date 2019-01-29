/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_and_convert.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: struxill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 15:49:06 by struxill          #+#    #+#             */
/*   Updated: 2019/01/24 15:07:53 by struxill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_triminos	*ft_check_and_convert(char *str)
{
	t_list		*tmp_list;
	t_triminos	*tri_list;

	if (ft_check(str))
	{
		ft_putendl("ft_check OK. Converting to t_list.");
		tmp_list = ft_convert_to_t_list(str);
		if (ft_check_diese_nb(tmp_list))
		{
			ft_putendl("ft_check_diese_nb OK. Converting to t_triminos list.");
			tri_list = ft_t_list_to_tri_list(tmp_list);
			if (ft_check_shape(tri_list))
			{
				ft_putendl("ft_check_shape OK.");
				ft_putendl("\nLes donnes sont valides.");
				ft_assign_letter(tri_list);
				return (tri_list);
			}
		}
	}
	ft_putendl("\nLes donnes sont invalides...");
	return (NULL);
}
