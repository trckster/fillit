/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkayleen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 17:02:26 by bkayleen          #+#    #+#             */
/*   Updated: 2019/10/13 17:21:59 by bkayleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		takes_place(char **sq, t_point *dot, int sz, t_item *item)
{
	return (1);
}

int 	fill_square(char **sq, int square_size, t_item **items, int curr_item)
{
	t_point *dot;

	if (!items[curr_item])
		return (1);
	dot->x = 0;
	while (dot->x < square_size)
	{
		dot->y = 0;
		while (dot->y < square_size)
		{
			if (takes_place(sq, dot, square_size, items[curr_item]))
				return (fill_square(sq, square_size, items, curr_item));
			dot->y++;
		}
		dot->x++;
	}
	return (0);
}
