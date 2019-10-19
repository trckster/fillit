/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apearl <apearl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 15:57:29 by bkayleen          #+#    #+#             */
/*   Updated: 2019/10/18 23:20:27 by bkayleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include "../libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h> // delete it after end of work

# define BUFF_SIZE 100
# define MAX_FD_COUNT 1025

typedef struct  s_point
{
	short x;
	short y;
}               t_point;

typedef struct	s_item
{
	t_point *p1;
	t_point *p2;
	t_point *p3;
	t_point *p4;
}				t_item;

typedef struct  s_field
{
	char    **square;
	int     size;
}               t_field;

int				ft_sqrt(int n);
int				fillit(char *s);
int 	        fill_square(t_field *field, t_item **items, int curr_item);
int		        process_algorithm(t_item **items);
void            print_answer(t_field *field);
int             get_next_line(const int fd, char **line, int c);
int				correct_block(char **s);
void			optimize_data(t_item **items);
void            free_items(t_item **items);
void            free_field(t_field *field);
void            free_next_block(char **nb);

#endif
