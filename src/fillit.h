/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkayleen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 15:57:29 by bkayleen          #+#    #+#             */
/*   Updated: 2019/10/13 15:57:36 by bkayleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include "../libft/libft.h"
# include <fcntl.h>

typedef struct	s_item
{
	char field[4][4];
}				t_item;

int         fillit(char *s);

#endif
