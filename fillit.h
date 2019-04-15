/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbelov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 17:46:35 by kbelov            #+#    #+#             */
/*   Updated: 2019/04/12 05:03:35 by kbelov           ###   ########.fr       */
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
	int		index_block1;
	int		index_block2;
	int		index_block3;
	int		index_block4;
	int		id;
	int		block1_x;
	int		block1_y;
	int		block2_x;
	int		block2_y;
	int		block3_x;
	int		block3_y;
	int		block4_x;
	int		block4_y;
	char	letter;
	int		x;
	int		y;
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
t_board			set_board(short bd_size);
void			struct_tetrimino(char *tetrimino, short i);
int				fill_board(t_board *board, t_tetrimino *t, int i, int num);
int				try_tetrimino(t_board *board, t_tetrimino *t);
void			place_tetrimino(t_board *board, t_tetrimino *t);
void			reposition_last(t_board *board, t_tetrimino *t);
void			iterate_board(t_board *board);
void			print_matrix_test(char **matrix);

#endif
