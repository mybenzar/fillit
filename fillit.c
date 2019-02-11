/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 19:16:03 by mybenzar          #+#    #+#             */
/*   Updated: 2019/02/11 22:08:11 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int ac, char **av)
{
	int			ret;
	int			fd;
	char		buf[BUFF_SIZE + 1];
	char		**tab;
	t_triminos	*tri_list;
	int			size_tab;

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
	size_tab = ft_optimal_size(ft_list_size(tri_list));
	tab = ft_create_tab(size_tab);
	while (!ft_scan(tri_list, tab, 0, 0))
	{
		size_tab++;
		ft_free_tab(tab);
		tab = ft_create_tab(size_tab);
	}
	ft_display_tab(tab);
	ft_lst_free(tri_list);
	ft_free_tab(tab);
	return (0);
}
