# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/12 11:25:39 by npiya-is          #+#    #+#              #
#    Updated: 2021/12/12 11:57:15 by npiya-is         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAG = -Wall -Werror -Wextra

SRC1 = find_dict.c ft_string.c ft_utility.c ft_utility2.c main.c 

SRC2 = read_files.c testnum.c map_dict.c

NAME = rush02

$(NAME):
	gcc $(CFLAG) -o $(NAME) $(SRC1) $(SRC2)

fclean:
	rm $(NAME)
