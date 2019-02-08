/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainSim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: struxill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 14:24:31 by struxill          #+#    #+#             */
/*   Updated: 2019/02/08 14:19:17 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fillit.h"
#include <stdio.h>


int	main(int ac, char **av)
{
	int		test;
	int		ret;
	int		fd;
	char	buf[BUFF_SIZE + 1];
	char	**tab;
	int		l;
	int		c;
	char	letter;
	t_list	*list;
	t_triminos	tri;
	t_triminos	*tri_list;
	int		d;

	if (ac != 2)
		return (0);
	fd = open(av[1], O_RDONLY);
	ret = read(fd, buf, BUFF_SIZE);
	buf[ret] = '\0';
	tri_list = ft_check_and_convert(buf);
	tab = ft_browse(tab, tri_list, ft_optimal_size(ft_list_size(tri_list)));
	ft_display_tab(tab);
	ft_free_tab(tab);
	return (0);
}
