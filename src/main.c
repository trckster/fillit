/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkayleen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 14:16:14 by bkayleen          #+#    #+#             */
/*   Updated: 2019/10/12 14:50:39 by bkayleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void    show_usage()
{
	ft_putstr("usage: <>< ><> < <<<<< >>>>\n");
}

void    show_error()
{
	ft_putstr("error\n");
}

int     main(int argc, char **argv)
{
	if (argc != 2)
	{
        show_usage();
		return (1);
	}
	if (!fillit(argv[1]))
		show_error();
    return (0);
}
