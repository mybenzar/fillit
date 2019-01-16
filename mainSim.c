/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainSim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: struxill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 14:24:31 by struxill          #+#    #+#             */
/*   Updated: 2019/01/16 19:16:04 by struxill         ###   ########.fr       */
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
	t_list	*list;
	t_triminos	tri;
	t_triminos	*tri_list;

	if (ac != 2)
	{
		printf("Invalid numbers of arguments\nUsage : ./a.out input.txt\n");
		return (0);
	}
	fd = open(av[1], O_RDONLY);
	ret = read(fd, buf, BUFF_SIZE);
	printf("ret = %d\n", ret);
	buf[ret] = '\0';
	printf("%s", buf);
	test = ft_check(buf);
	if (test == 1)
		printf("Donnees valides !\n\n");
	if (test == 0)
	{
		printf("Donnees incorrectes...\n");
		return (-1);
	}
	if (test == 1)
	{
		list = ft_convert_to_t_list(buf);
//		ft_lst_aff(list);
	}
//	tri = ft_tri_pos(list);
//	tri = ft_left(tri);
//	ft_display(tri);
	
	
	//NEW TRI LIST TESTING
	printf("TEST TRI_LIST MAKING AND DISPLAY (UP AND LEFT ALREADY)\n\n");
	tri_list = ft_t_list_to_tri_list(list);
	ft_display_tri_lst(tri_list);



	
	return (0);
}