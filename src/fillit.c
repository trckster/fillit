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

t_item	*load_data(char *filename)
{
    char    buf[BUFF_SIZE];
    int     fd;
    int     need_amount;
    t_item  *tetro;
    int     i;
    
    i = 0;
    // Узнать сколько нужно выделить памяти
    // Выделить память под нужноe количество
    fd = open(filename, O_RDONLY);
    buf =  (char *) malloc (sizeof (char *) * BUFF_SIZE);
    need_amount = read(fd, buf, BUFF_SIZE);
    if (need_amount < 0)
        return (NULL);
    //buf[need_amount] = '\0'
    tetro = (t_item *)malloc(sizeof (t_item));
    while (i < 4)
    {
        ft_strncpy(tetro->field[i], buf + i * 5, 4);
        tetro->field[i][4] = '\0';
        i++;
    }

    // Положить нуль в конец
	// Заполнить массив t_item'ов на основе входных данных
	// Вернуть указатель на первый элемент
	// Если при считывании происходит ошибка или становится понятно что даны неправильные тетрамино,
	// возвратить 0
}

int     fillit(char *filename)
{
	t_item **data;
	
	if (!filename)
		return (0);
	data = load_data(char *filename);
	process_algorithm(data);
    print_answer()
//  return 0 or 1;
	return (1);
}
