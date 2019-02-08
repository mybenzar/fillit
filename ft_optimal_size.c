/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_optimal_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 17:26:16 by mybenzar          #+#    #+#             */
/*   Updated: 2019/02/08 11:54:52 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#include <stdio.h>

int	ft_optimal_size(int nb)
{
	int		i;
	int		square;
//	float	rounded;
	float	res;

	i = 1;
	square = 1;
	if (nb <= 3)
		return (3);
	while (square != nb)
	{
		i++;
		square = i * i;
		if (square > nb)
		{
			i--;
			printf("i = %i\n", i);
			res = i;
			res = (res + (float)nb / res) / 2;
			printf("res = %f\n", res);
		//	rounded = (int)(res * 10 + 5) / 10;
		//	printf("rounded = %f\n", rounded);
			if ((int)(res * 10) % 10 != 0)
				return (2 * (int)res + 1);
			else
				return (2 * (int)res);
		}
	}
	return (2 * i);
}

/*int	main(void)
{
	printf("resultat = %i\n", ft_optimal_size(15));
	return (0);
}*/
