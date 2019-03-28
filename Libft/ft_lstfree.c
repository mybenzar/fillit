/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: struxill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 18:28:03 by struxill          #+#    #+#             */
/*   Updated: 2019/03/28 14:17:00 by struxill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

#include <stdio.h>

void	ft_lstfree(t_list *lst)
{
	t_list	*tmp;

	while (lst)
	{
		printf("lst pointe sur le maillon %zu\n", lst->content_size);
		tmp = lst;
		free(lst->content);
		lst->content_size = 0;
		lst = lst->next;
		free(tmp);
		if (lst)
			printf("fin du while, lst content_size :  %zu\n", lst->content_size);
	}
	printf("\nlstfree terminee\n");
	lst = NULL;
}
