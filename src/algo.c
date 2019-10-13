/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkayleen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 16:00:58 by bkayleen          #+#    #+#             */
/*   Updated: 2019/10/13 16:38:44 by bkayleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		get_init_square_size(t_item *items)
{
	int		size;

	size = 0;
	while (items[size])
		size++;
	return (ft_sqrt(size * 4));
}

void	clear_square(char *square, int size)
{
	int i;

	i = 0;
	while (i < size * size)
		square[i++] = '.';
}

void	fill_square(char *sq, t_item *items, int curr_item)
{
	if (!items[curr_item])
		return (1);
}

int		try_accommodate(t_item *items, int square_size)
{
	char	*square;

	square = (char *)malloc(square_size * square_size);
	clear_square(square, square_size);
	if (fill_square(square, items, 0))
	{
		print_answer(square);
		return (1);
	}
	return (0);
}

int		process_algorithm(t_item *items)
{
	int		square_size;

	square_size = get_init_square_size(items);
	while (!try_accommodate(items, square_size))
		square_size++;
	return (1);
}
