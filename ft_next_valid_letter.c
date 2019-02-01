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
	t_triminos	*tmp;

	while (lst->next && letter != lst->letter)
		lst = lst->next;
	if (letter == lst->letter)
	{
		while (lst->next && letter >= lst->letter && !ft_test_for_lst_place(lst, tab))
			lst = lst->next;
		if (lst->letter > letter && lst->letter < 91)
			return (lst->letter);
		else
			return (0);
	}
	else
		return (0);
}
