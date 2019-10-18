/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkayleen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 23:20:33 by bkayleen          #+#    #+#             */
/*   Updated: 2019/10/18 23:22:27 by bkayleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	optimize_data(t_item **data)
{
	int	i;

	i = 0;
	while (data[i])
	{
		printf("P number %d\n", i + 1);
		printf("P1: x=%d, y=%d\n", data[i]->p1->x, data[i]->p1->y);
		printf("P2: x=%d, y=%d\n", data[i]->p2->x, data[i]->p2->y);
		printf("P3: x=%d, y=%d\n", data[i]->p3->x, data[i]->p3->y);
		printf("P4: x=%d, y=%d\n", data[i]->p4->x, data[i]->p4->y);
		i++;
	}
}
