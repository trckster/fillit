/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apearl <apearl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 17:02:26 by bkayleen          #+#    #+#             */
/*   Updated: 2019/10/18 22:32:59 by bkayleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int     item_in_ranges(t_item *item, t_point *dot, int size)
{
	if (item->p1->x + dot->x >= 0 && -item->p1->y + dot->y < size)
		return (0);
	if (item->p2->x + dot->x >= 0 && -item->p2->y + dot->y < size)
		return (0);
	if (item->p3->x + dot->x >= 0 && -item->p3->y + dot->y < size)
		return (0);
	if (item->p4->x + dot->x >= 0 && -item->p4->y + dot->y < size)
		return (0);
	return (1);
}

int		takes_place(t_field *field, t_point *dot, t_item *item, char symbol)
{
	if (!item_in_ranges(item, dot, 4))
		return (0);
	if (field->square[item->p1->x + dot->x][-item->p1->y + dot->y] != '.')
		return (0);
	if (field->square[item->p2->x + dot->x][-item->p2->y + dot->y] != '.')
		return (0);
	if (field->square[item->p3->x + dot->x][-item->p3->y + dot->y] != '.')
		return (0);
	if (field->square[item->p4->x + dot->x][-item->p4->y + dot->y] != '.')
		return (0);
	field->square[item->p1->x + dot->x][-item->p1->y + dot->y] = symbol;
	field->square[item->p2->x + dot->x][-item->p2->y + dot->y] = symbol;
	field->square[item->p3->x + dot->x][-item->p3->y + dot->y] = symbol;
	field->square[item->p4->x + dot->x][-item->p4->y + dot->y] = symbol;
	return (1);
}

void    clear_place(t_field *field, t_point *dot, t_item *item)
{
	field->square[item->p1->x + dot->x][-item->p1->y + dot->y] = '.';
	field->square[item->p1->x + dot->x][-item->p1->y + dot->y] = '.';
	field->square[item->p1->x + dot->x][-item->p1->y + dot->y] = '.';
	field->square[item->p1->x + dot->x][-item->p1->y + dot->y] = '.';
}

int 	fill_square(t_field *field, t_item **items, int curr_item)
{
	t_point *dot;
	int     res;

	if (!items[curr_item])
		return (1);
	dot = (t_point *)malloc(sizeof(t_point));
	dot->x = 0;
	while (dot->x < field->size)
	{
		dot->y = 0;
		while (dot->y < field->size)
		{
			if (takes_place(field, dot, items[curr_item], 'A' + curr_item))
			{
				res = fill_square(field, items, curr_item);
				if (!res)
					clear_place(field, dot, items[curr_item]);
				return (res);
			}
			dot->y++;
		}
		dot->x++;
	}
	return (0);
}
