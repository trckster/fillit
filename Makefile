# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apearl <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/18 23:28:51 by apearl            #+#    #+#              #
#    Updated: 2019/10/12 16:51:02 by apearl           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRC = ./fillitp/*.c
OBJ = ./fillitp/*.o
HDR = ./fillitp/fillit.h
FLAG = -Wall -Wextra -Werror

LIBFT = libft/

all:	$(NAME)

$(NAME):
	make -C $(LIBFT)
	gcc $(FLAG) -o $(NAME) $(SRC) -I $(HDR) -L. libft/libft.a
   	
clean:
	@rm -f $(OBJ)
	make -C $(LIBFT) clean

fclean: clean
	@rm -f $(NAME)
	make -C $(LIBFT) fclean 

re: fclean all

.PHONY: all, clean, fclean, re
