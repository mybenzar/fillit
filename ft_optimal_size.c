/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_optimal_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 17:26:16 by mybenzar          #+#    #+#             */
/*   Updated: 2019/02/01 17:26:36 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_optimal_size(int nb)
{
	int i;
	int	square;

	i = 1;
	square = 1;
	if (nb == 1)
		return (1);
	if (nb <= 0)
		return (0);
	while (square != nb)
	{
		i++;
		square = i * i;
		if (square > nb)
		{
			i--;
			return ((2 * i) + 1);	
		}
	}
	return (2 * i);
}
