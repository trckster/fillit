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

int		takes_place(char *sq){} // not completed 

void	fill_square(char *sq, int square_size, t_item *items, int curr_item)
{
	int		i;
	int		j;

	if (!items[curr_item])
		return (1);
	// check about two-dimensional array ??
	i = 0;
	while (i < square_size)
	{
		j = 0;
		while (j < square_size)
		{
			if (takes_place(sq, i, j, square_size))
			j++;
		}
		i++;
	}	
}
