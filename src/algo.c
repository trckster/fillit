/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkayleen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 16:00:58 by bkayleen          #+#    #+#             */
/*   Updated: 2019/10/13 16:15:40 by bkayleen         ###   ########.fr       */
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

int		process_algorithm(t_item *items)
{
	int		init_size;

	init_size = get_init_square_size(items);
}
