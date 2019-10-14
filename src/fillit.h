/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkayleen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 15:57:29 by bkayleen          #+#    #+#             */
/*   Updated: 2019/10/13 17:11:02 by bkayleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <unistd.h>
# include "../libft/libft.h"
# include <fcntl.h>
# define BUFF_SIZE 22

# include <stdio.h> // delete it after end of work

typedef struct	s_item
{
	s_point *p1;
	s_point *p2;
	s_point *p3;
	s_point *p4;
}				t_item;

typedef struct  s_point
{
	short x;
	short y;
}               t_point;

typedef struct  s_field
{
	char    **square;
	int     size;
}               t_field;

int				ft_sqrt(int n);
int				fillit(char *s);
void			fill_square(char *square, int square_size, t_item *items, int curr_item);

#endif
