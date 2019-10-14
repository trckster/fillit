/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkayleen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 16:00:58 by bkayleen          #+#    #+#             */
/*   Updated: 2019/10/13 17:20:27 by bkayleen         ###   ########.fr       */
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

void	clear_square(char **square, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
			square[i][j++] = '.';
		i++;
	}
}

int		try_accommodate(t_item *items, int square_size)
{
	char	**square;
	int		i;

	i = 0;
	square = (char **)malloc(square_size * sizeof(char *));
	while (i < square_size)
		square[i++] = (char *)malloc(square_size * sizeof(char));
	clear_square(square, square_size);
	if (fill_square(square, square_size, items, 0))
	{
		print_answer(square, square_size);
		return (1);
	}
	return (0);
}

int		process_algorithm(t_item **items)
{
	int		square_size;

	square_size = get_init_square_size(items);
	while (!try_accommodate(items, square_size))
		square_size++;
	return (1);
}
