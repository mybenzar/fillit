/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_next_valid_letter.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: struxill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 19:03:52 by struxill          #+#    #+#             */
/*   Updated: 2019/02/01 21:54:50 by struxill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	ft_next_valid_letter(t_triminos *lst, char letter, char **tab)
{
	char		ret;
//	t_triminos	*tmp;


	while (lst->next && letter != lst->letter)
		lst = lst->next;
	if (letter == lst->letter)
	{
		while (lst) 
		{
			if ((lst->letter > letter) && !ft_shape(letter, lst->letter, lst))
			//&& ft_test_for_lst_place(lst, tab))
				return (lst->letter);
			else
				lst = lst->next;
		}
	}
	return (0);
}
