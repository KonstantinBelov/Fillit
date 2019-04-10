/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbelov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 17:46:35 by kbelov            #+#    #+#             */
/*   Updated: 2019/04/10 02:53:56 by kbelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define FILE_SIZE_FILLIT 545
# define BUFF_SIZE 32

# include "libft/libft.h"
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct	s_tetrimino
{
	short		index_block1;
	short		index_block2;
	short		index_block3;
	short		index_block4;
	short		id;
	short		block1_x;
	short		block1_y;
	short		block2_x;
	short		block2_y;
	short		block3_x;
	short		block3_y;
	short		block4_x;
	short		block4_y;
	char		letter;
	short		x;
	short		y;
}				t_tetrimino;

typedef struct	s_board
{
	int			board_size;
	char		**board;
	int			y;
	int			x;
}				t_board;

int				verify_input(int fd);
int				verify_chars(char *tetr);
int				verify_connections(char *tetr);
int				verify_tetrimino(char *t);
int				ft_calc_x(int ind_0, int ind_1);
int				ft_calc_y(int ind_0, int ind_1);
void			fillit();
t_board			set_board(short board_size);
void			struct_tetrimino(char *tetrimino, short i);
t_board			*fill_board(t_board *board, t_tetrimino *t, int i, short num);
int				try_tetrimino(t_board *board, t_tetrimino t);
void			place_tetrimino(t_board *board, t_tetrimino t, int i);
void			reposition_last(t_board *board, t_tetrimino t, int i);
void			iterate_board(t_board *board);
void			print_matrix_test(char **matrix);

#endif
