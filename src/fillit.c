/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apearl <apearl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 14:16:14 by bkayleen          #+#    #+#             */
/*   Updated: 2019/10/18 22:37:06 by bkayleen         ###   ########.fr       */
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
		if (ft_strlen(tmp) != 4)
			return (0);
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

void	add_point(t_item *item, int i, int j, int cnt)
{
	t_point	*p;

	p = (t_point *)malloc(sizeof(t_point));
	p->x = i;
	p->y = -j;
	if (!cnt)
		item->p1 = p;
	else if (cnt == 1)
		item->p2 = p;
	else if (cnt == 2)
		item->p3 = p;
	else if (cnt == 3)
		item->p4 = p;
}

t_item	*get_item_from_block(char **s)
{
	int		i;
	int		j;
	int		cnt;
	t_item	*item;

	i = 0;
	cnt = 0;
	item = (t_item *)malloc(sizeof(t_item));
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (s[i][j] == '#')
			{
				add_point(item, i, j, cnt);
				cnt++;
			}
			j++;
		}
		i++;
	}
	return (item);
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
			return (0);//free_data(items));
	}
	items[i] = 0;
	return (items);
}

int     fillit(char *filename)
{
	t_item **data;

	if (!filename)
		return (0);
	data = load_data(filename);
	if (!data)
		return (0);
	process_algorithm(data);
	return (1);
}
