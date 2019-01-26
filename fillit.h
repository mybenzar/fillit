/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 15:15:54 by mybenzar          #+#    #+#             */
/*   Updated: 2019/01/26 15:50:20 by mybenzar         ###   ########.fr       */
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
# include <stdlib.h>

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
	char				letter;
}				t_triminos;

// FONCTIONS
t_triminos	ft_tri_pos(t_list *list);
t_triminos	ft_left(t_triminos tri);
void		ft_display(t_triminos tri);
t_triminos	*ft_lst_tri_new(t_triminos tri);
void		ft_lst_tri_add(t_triminos **list_tri, t_triminos *new_tri);
t_triminos	*ft_t_list_to_tri_list(t_list *list);
void		ft_display_tri_lst(t_triminos *tri_list);
int			ft_list_size(t_triminos *tri_list);
char		**ft_create_tab(int size);
char		**ft_browse(char **tab, t_triminos *list, int size_tab);
int			ft_place(t_triminos *list, char **tab, int l, int c);
void		ft_find(char **tab, int *l, int *c);
void		ft_display_tab(char **tab);
void		ft_free_tab(char **tab);
int			ft_check_diese_nb(t_list *list);
int			ft_check_shape(t_triminos *tri_list);
t_triminos	*ft_check_and_convert(char *str);
void		ft_display_tab(char **tab);
void		ft_assign_letter(t_triminos *tri_list);

// MYMA UPDATES

int			ft_test(t_triminos *list, char **tab, int l, int c);
void		ft_del(int letter, char **tab);


// SIMON UPDATE

t_triminos	*ft_lst_insert(t_triminos *tri_list, int placed, char letter);
t_triminos	*ft_lst_sort(t_triminos *tri_list);

#endif
