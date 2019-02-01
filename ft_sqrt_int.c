/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 12:52:07 by mybenzar          #+#    #+#             */
/*   Updated: 2019/02/01 13:57:10 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_sqrt_int(int nb)
{
	int i;
	int	sqrt;

	i = 1;
	sqrt = 1;
	if (nb == 1)
		return (1);
	if (nb <= 0)
		return (0);
	while (sqrt != nb)
	{
		i++;
		sqrt = i * i;
		if (sqrt > nb)
		{
			i--;
			return (i);	
		}
	}
	return (i);
}
