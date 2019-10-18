/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apearl <apearl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 14:16:14 by bkayleen          #+#    #+#             */
/*   Updated: 2019/10/14 18:00:40 by apearl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_item **load_data(char *fn)
{
	char    **next_block;
	int     fd;

	fd = open(fn, O_RDONLY);
	while (/** FUCKEDK*/)
	{
	}
}

int     fillit(char *filename)
{
	t_item **data;

	if (!filename)
		return (0);
	data = load_data(char *filename);
	if (!data)
		return (0);
	process_algorithm(data);
    print_answer();
	return (1);
}