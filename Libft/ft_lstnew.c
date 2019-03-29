/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: struxill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 16:49:58 by struxill          #+#    #+#             */
/*   Updated: 2019/03/28 16:42:54 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(char *content, size_t content_size)
{
	t_list	*new_list;

	if (!(new_list = (t_list*)malloc(sizeof(*new_list))))
		return (NULL);
	if (content == NULL)
	{
		new_list->content = NULL;
		new_list->content_size = 0;
	}
	new_list->content = ft_strdup(content);
	new_list->content_size = content_size;
	new_list->next = NULL;
	return (new_list);
}
/*
	else
	{
		new_list->content = (char *)malloc(sizeof(*(new_list->content))
				* content_size);
		if (new_list->content == NULL)
		{
			free(new_list);
			return (NULL);
		}
		new_list->content_size = content_size;
		ft_memcpy(new_list->content, content, content_size);
	}
	new_list->next = NULL;
	return (new_list);
*/
