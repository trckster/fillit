/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkayleen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 14:16:14 by bkayleen          #+#    #+#             */
/*   Updated: 2019/10/13 16:53:50 by bkayleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_item	*load_data()
{
    char    buff[BUFF_SIZE];
    int     fd;
    int     need_amount;
    
    fd = open(filename, O_RDONLY);
    need_amount = read(fd, buf, BUFF_SIZE);
    
    // Узнать сколько нужно выделить памяти
	// Выделить память под нужноe количество
    buf = (char *) malloc (sizeof (char *));
    // Положить нуль в конец
    buf[need_amount] = '\0'
	// Заполнить массив t_item'ов на основе входных данных
	// Вернуть указатель на первый элемент
	// Если при считывании происходит ошибка или становится понятно что даны неправильные тетрамино,
	// возвратить 0
}

int     fillit(char *filename)
{
	t_item *data;
	
	if (!filename)
		return (0);
	data = load_data();
//  process_(recursive?)_algorithm(data)
//  print_answer()
//  return 0 or 1;
	return (1);
}
