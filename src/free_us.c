/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apearl <apearl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 14:16:14 by bkayleen          #+#    #+#             */
/*   Updated: 2019/10/18 23:25:45 by bkayleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void    free_items(t_item **items)
{
	int i;

	i = 0;
	while (items[i])
	{
		free(items[i]->p1);
		free(items[i]->p2);
		free(items[i]->p3);
		free(items[i]->p4);
		free(items[i]);
		i++;
	}
	free(items);
}

void    free_next_block(char **next_block)
{
	int i;

	i = 0;
	while(i < 4)
	{
		free(next_block[i]);
		i++;
	}
	free(next_block);
}

void    free_field(t_field *field)
{
	int i;

	i = 0;
	while (i < field->size)
	{
		free(field->square[i]);
		i++;
	}
	free(field->square);
	free(field);
}