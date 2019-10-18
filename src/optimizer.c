/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkayleen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 23:20:33 by bkayleen          #+#    #+#             */
/*   Updated: 2019/10/18 23:51:49 by bkayleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		canup(int a, int b, int c, int d)
{
	return (a + 1 <= 0 && b + 1 <= 0 && c + 1 <= 0 && d + 1 <= 0);
}

int		canleft(int a, int b, int c, int d)
{
	return (a - 1 >= 0 && b - 1 >= 0 && c - 1 >= 0 && d - 1 >= 0);
}

void	optimize_item(t_item *item)
{
	int		up;
	int		left;

	up = canup(item->p1->y, item->p2->y, item->p3->y, item->p4->y);
	while (up)
	{
		item->p1->y += 1;
		item->p2->y += 1;
		item->p3->y += 1;
		item->p4->y += 1;
		up = canup(item->p1->y, item->p2->y, item->p3->y, item->p4->y);
	}
	left = canleft(item->p1->x, item->p2->x, item->p3->x, item->p4->x);
	while (left)
	{
		item->p1->x -= 1;
		item->p2->x -= 1;
		item->p3->x -= 1;
		item->p4->x -= 1;
		left = canleft(item->p1->x, item->p2->x, item->p3->x, item->p4->x);
	}
}

void	optimize_data(t_item **data)
{
	int	i;

	i = 0;
	while (data[i])
	{
		printf("Optimizing... ");
		optimize_item(data[i]);
		printf("Done\n");
		printf("P number %d\n", i + 1);
		printf("P1: x=%d, y=%d\n", data[i]->p1->x, data[i]->p1->y);
		printf("P2: x=%d, y=%d\n", data[i]->p2->x, data[i]->p2->y);
		printf("P3: x=%d, y=%d\n", data[i]->p3->x, data[i]->p3->y);
		printf("P4: x=%d, y=%d\n", data[i]->p4->x, data[i]->p4->y);
		i++;
	}
}
