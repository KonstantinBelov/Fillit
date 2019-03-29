# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kbelov <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/18 17:50:38 by kbelov            #+#    #+#              #
#    Updated: 2019/03/25 19:51:36 by kbelov           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit.a

FLAG = -Wall -Wextra -Werror

SRC = fillit.c fillit_2.c
OBJ = fillit.o fillit_2.o
HEADER = fillit.h

all: $(NAME)

$(NAME):
	gcc -c $(FLAG) $(SRC) -I $(HEADER)
	ar -rv $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
