/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: struxill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 15:04:04 by struxill          #+#    #+#             */
/*   Updated: 2019/01/26 15:44:09 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_display_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		ft_putendl(tab[i++]);
	ft_putchar('\n');
}
