/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 15:15:54 by mybenzar          #+#    #+#             */
/*   Updated: 2018/12/13 16:31:32 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** la structure pour definir le contenu et l'id du minos est celle de la libft.h
*/ 

/*
** structure pour definir la position de chaque # dans les minos
*/ 

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
	s_pos	pos[3];
}				t_triminos;

}
