/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apearl <apearl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 14:16:14 by bkayleen          #+#    #+#             */
/*   Updated: 2019/10/18 23:25:45 by bkayleen         ###   ########.fr       */
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
		printf("GNS: %d\n", res);
		if (!res)
			break ;
		if (ft_strlen(tmp) != 4)
			return (-1);
		if (res < 0)
			return (-1);
		sq[i] = tmp;
		i++;
	}
	if (res)
	{
		get_next_line(fd, &tmp);
		*fin = sq;
		return (1);
	}
	return (0);
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
			if (s[i][j] == '+')
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

void	logblock(char **s)
{
	ft_putstr("       <---------->\n");
	int i = 0;
	while (i < 4)
	{
			ft_putstr(s[i]);
			ft_putchar('\n');
			i++;
	}
	ft_putstr("<--------------------------->\n");
}

t_item	**load_data(char *fn)
{
	char    **next_block;
	int     fd;
	t_item	**items;
	int		i;
	int     res;

	fd = open(fn, O_RDONLY);
	items = (t_item **)malloc(sizeof(t_item *) * 27);
	i = 0;
	while (1)
	{
		res = get_next_square(fd, &next_block);
		if (res < 0)
			return (0);
		if (!res)
			break ;
		logblock(next_block);
		if (!correct_block(next_block))
			return (0);
		items[i++] = get_item_from_block(next_block);
	}
	items[i] = 0;
	printf("normal load_data ending work\n");
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
	printf("Start processing algoss\n");
	optimize_data(data);
	process_algorithm(data);
	return (1);
}
