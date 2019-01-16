/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 15:15:54 by mybenzar          #+#    #+#             */
/*   Updated: 2019/01/16 19:43:55 by struxill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef __FILLIT_H
# define __FILLIT_H
# include "libft.h"
# define BUFF_SIZE 1048 
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

/*
** la structure pour definir le contenu et l'id du minos est celle de la libft.h
*/ 

/*
** structure pour definir la position de chaque # dans les minos
*/ 

int			ft_check(char *str);
t_list		*ft_convert_to_t_list(char *str);

typedef struct	s_pos
{
	int x;
	int y;
}				t_pos;

/*
** structure pour definir la position de chaque # dans les minos
*/ 

typedef struct	s_triminos
{
	t_pos				pos[4];
	struct s_triminos	*next;
}				t_triminos;

t_triminos	ft_tri_pos(t_list *list);
t_triminos	ft_left(t_triminos tri);
void		ft_display(t_triminos tri);
t_triminos	*ft_lst_tri_new(t_triminos tri);
void		ft_lst_tri_add(t_triminos **list_tri, t_triminos *new_tri);
t_triminos	*ft_t_list_to_tri_list(t_list *list);
void		ft_display_tri_lst(t_triminos *tri_list);
//t_triminos	*ft_rev_tri_lst(t_triminos *list);

#endif
