# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kbelov <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/18 17:50:38 by kbelov            #+#    #+#              #
#    Updated: 2019/04/10 06:19:54 by kbelov           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

FLAG = -Wall -Wextra -Werror

SRC = main.c verify.c prepare.c fillit.c
OBJ = main.o verify.o prepare.o fillit.o
HEADER = fillit.h

all: $(NAME)

$(NAME):
	gcc $(FLAG) $(SRC) libft/libft.a -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

lldb:
	gcc -g $(FLAG) $(SRC) libft/libft.a -o fillit_lldb

test:
	lldb fillit_lldb ../Fillit_backup/test/19.txt

dev:
	gcc $(FLAG) main.c verify.c prepare_dev_mode.c fillit_dev_mode.c libft/libft.a -o fillit_dev_mode

dev_lldb:
	gcc $(FLAG) main.c verify.c prepare_dev_mode.c fillit_dev_mode.c libft/libft.a -o fillit_dev_lldb
