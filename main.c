/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 17:14:06 by mybenzar          #+#    #+#             */
/*   Updated: 2019/02/06 17:25:26 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int ac, char **av)
{
	int		ret;
	int		fd;
	char	buf[BUFF_SIZE + 1];
	char	**tab;
	t_triminos	*tri_list;

	if (ac != 2)
		return (0);
	fd = open(av[1], O_RDONLY);
	ret = read(fd, buf, BUFF_SIZE);
	buf[ret] = '\0';
	if (!(tri_list = ft_check_and_convert(buf)))
	{
		ft_putendl("error");
		return (0);
	}
	tab = ft_browse(tab, tri_list, ft_optimal_size(ft_list_size(tri_list)));
	ft_display_tab(tab);
	ft_free_tab(tab);
	return (0);
}
