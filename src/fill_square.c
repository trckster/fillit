/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apearl <apearl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 17:02:26 by bkayleen          #+#    #+#             */
/*   Updated: 2019/10/19 00:02:14 by bkayleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int     item_in_ranges(t_item *item, t_point *dot, int size)
{
	if (item->p1->x + dot->x < 0 || item->p1->x + dot->x >= size) {
		printf("Problem comes here %d %d\n", item->p1->x, size);
		return (0);
	}
	if (item->p2->x + dot->x < 0 || item->p2->x + dot->x >= size)
		return (0);
	if (item->p3->x + dot->x < 0 || item->p3->x + dot->x >= size)
		return (0);
	if (item->p4->x + dot->x < 0 || item->p4->x + dot->x >= size)
		return (0);
	if (-item->p1->y + dot->y < 0 || -item->p1->y + dot->y >= size)
		return (0);
	if (-item->p2->y + dot->y < 0 || -item->p2->y + dot->y >= size)
		return (0);
	if (-item->p3->y + dot->y < 0 || -item->p3->y + dot->y >= size)
		return (0);
	if (-item->p4->y + dot->y < 0 || -item->p4->y + dot->y >= size)
		return (0);
	return (1);
}

int		takes_place(t_field *field, t_point *dot, t_item *item, char symbol)
{
	printf("Fuck here comes problem if not comes item in ranges\n");
	if (!item_in_ranges(item, dot, field->size))
		return (0);
	printf("Item in ranges\n");
	if (field->square[item->p1->x + dot->x][-item->p1->y + dot->y] != '.')
		return (0);
	if (field->square[item->p2->x + dot->x][-item->p2->y + dot->y] != '.')
		return (0);
	if (field->square[item->p3->x + dot->x][-item->p3->y + dot->y] != '.')
		return (0);
	if (field->square[item->p4->x + dot->x][-item->p4->y + dot->y] != '.')
		return (0);
	printf("Item takes place as %c\n", symbol);
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

/** Log function */
void    print_field(t_field *field)
{
	int i = 0, j;
	while (i < field->size)
	{
		j = 0;
		while (j < field->size)
		{
			printf("%c", field->square[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

int 	fill_square(t_field *field, t_item **items, int curr_item)
{
	t_point *dot;
	int     res;

	if (!items[curr_item])
		return (1);
	printf("FS: sq_size=%d, curr_item=%d\n", field->size, curr_item); 
	dot = (t_point *)malloc(sizeof(t_point));
	dot->x = 0;
	while (dot->x < field->size)
	{
		dot->y = 0;
		while (dot->y < field->size)
		{
			printf("try %d %d\n", dot->x, dot->y);
			if (takes_place(field, dot, items[curr_item], 'A' + curr_item))
			{
				res = fill_square(field, items, curr_item + 1);
				if (!res)
					clear_place(field, dot, items[curr_item]);
				return (res);
			}
			dot->y++;
		}
		dot->x++;
	}
	free(dot);
	return (0);
}
