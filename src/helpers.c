/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkayleen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 16:09:38 by bkayleen          #+#    #+#             */
/*   Updated: 2019/10/19 13:38:49 by bkayleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_sqrt(int n)
{
	int	i;

	if (n < 0)
		return (-1);
	i = 0;
	while (i * i < n)
		i++;
	return (i);
}

char	**init_4_len_sq(void)
{
	char	**s;
	int		i;

	i = 0;
	s = (char **)malloc(sizeof(char *) * 4);
	while (i < 4)
		s[i++] = 0;
	return (s);
}
