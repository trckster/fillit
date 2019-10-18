/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apearl <apearl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 14:16:14 by bkayleen          #+#    #+#             */
/*   Updated: 2019/10/18 21:52:36 by bkayleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		get_next_square(int fd, char ***fin)
{
	char	*tmp;
	int		i;
	int		res;
	char	**sq;

	sq = (char **)malloc(sizeof(char *) * 4);
	i = 0;
	while (i < 4)
	{
		res = get_next_line(fd, &tmp);
		if (res < 0)
			return (0);
		if (!res)
			break ;
		sq[i] = tmp;
		i++;
	}
	*fin = sq;
	return (1);
}

t_item	**load_data(char *fn)
{
	char    **next_block;
	int     fd;
	int		valid;
	t_item	**items;
	int		i;

	fd = open(fn, O_RDONLY);
	valid = 1;
	items = (t_item **)malloc(sizeof(t_item *) * 27);
	i = 0;
	while (1)
	{
		valid = get_next_square(fd, &next_block);
		valid = valid && correct_block(next_block);
		if (valid)
			items[i++] = get_item_from_block(next_block);
		else
			return (free_data(items));
	}
	items[i] = 0;
	return (items);
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
