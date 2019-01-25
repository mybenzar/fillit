/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainSim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: struxill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 14:24:31 by struxill          #+#    #+#             */
/*   Updated: 2019/01/25 16:45:37 by mybenzar         ###   ########.fr       */
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
	printf("TEST TRI_LIST MAKING AND DISPLAY (UP AND LEFT ALREADY)\n\n");
	tri_list = ft_check_and_convert(buf);

	l = 0;
	c = 0;
	letter = 'A';

	//TEST FT CREATE TAB ET FT FREE TAB
	tab = ft_create_tab(4);
	printf("*******************TEST FT_CREATE_TAB ET FT_FREE_TAB***************** \n\n");
	ft_display_tab(tab);
	printf("succes de ft_create_tab\n");
	ft_free_tab(tab);
	if (tab[0] == NULL && tab[1] == NULL && tab[2] == NULL && tab[3] == NULL)
		printf("succes de ft_free_tab\n");
	else
		printf("echec de ft_free_tab\n");

	//TEST FT PLACE
	printf("\n\n*******************TEST FT_PLACE***************** \n\n");
	tab = ft_create_tab(4);
	ft_place(tri_list, tab, l, c);
	ft_display_tab(tab);
	ft_free_tab(tab);
	printf("succes de ft_place pour 1 minos valide\n");
	
	//TEST FT BROWSE
	printf("\n\n*******************TEST FT_BROWSE***************** \n\n");
	tab = ft_browse(tab, tri_list, 8);
	ft_display_tab(tab);
	
	
	return (0);
}
