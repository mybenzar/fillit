/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: struxill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 18:28:03 by struxill          #+#    #+#             */
/*   Updated: 2018/11/29 19:25:48 by struxill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstfree(t_list *lst)
{
	t_list	*tmp;

	while (lst)
	{
		tmp = lst;
		free(lst->content);
		lst->content_size = 0;
		lst = lst->next;
		free(tmp);
	}
	lst = NULL;
}
