/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbelov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 19:36:26 by kbelov            #+#    #+#             */
/*   Updated: 2019/04/10 04:23:32 by kbelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				ft_calc_x(int ind_0, int ind_1)
{
	if (ind_1 - ind_0 == 5)
		return (0);
	else if (ind_1 - ind_0 == 1)
		return (1);
	else
		return (ind_1 - ind_0 - 5);
}

int				ft_calc_y(int ind_0, int ind_1)
{
	if (ind_1 - ind_0 == 1)
		return (0);
	return (1);
}

void			fillit(void)
{
	extern short		g_num;
	extern t_tetrimino	g_tms[26];
	t_board				board_max;
	t_board				board_med;
	t_board				board_min;

	board_max = set_board(ft_sqrt_rounded_up(g_num * 4) + 2);
	fill_board(&board_max, g_tms, 0, g_num);
	board_med = set_board(ft_sqrt_rounded_up(g_num * 4) + 1);
	fill_board(&board_med, g_tms, 0, g_num);
	if (board_med.board_size == 0)
		print_matrix_test(board_max.board);
	else
	{
		board_min = set_board(ft_sqrt_rounded_up(g_num * 4));
		fill_board(&board_min, g_tms, 0, g_num);
		if (board_min.board_size == 0)
			print_matrix_test(board_med.board);
		else
			print_matrix_test(board_min.board);
	}
}

t_board			set_board(short board_size)
{
	t_board			board;
	//char			board_row[board_size + 1];
	char			*board_row;
	short			l;

	l = 0;
	//board_row = NULL;
	//
	board_row = ft_strnew(board_size);
	//printf("This is a board row initialized: \n%s\n", board_row);
	//if (!(board_row = (char *)malloc((board_size + 1) * sizeof(board_row))))
//	{
//		board.board_size = 0;
//		return (board);
//	}
	//printf("l = %d\n", l);
	//printf("board_size = %d\n", board_size);
	//board_row = ft_memset(board_row, '.', board_size);
	while (l < board_size)
	{
		board_row[l] = '.';
		//printf("This is board_row after board_row[%d] set:\n", l);
		//printf("%s", board_row);
		l++;
	}
	//
	//printf("This is a board row filled with '.': \n%s\n", board_row);
	board_row[l] = '\n';
	board_row[l + 1] = '\0';
	//
	//printf("This is a board row with \\n: \n%s\n", board_row);
	l = 0;
	if (!(board.board = (char **)malloc((board_size + 1) * sizeof(*board.board))))
	{
		board.board_size = 0;
		return (board);
	}
	board.board[board_size] = NULL;
	while (l < board_size)
	{
		board.board[l++] = ft_strdup(board_row);
		//
		//printf("This is a board.board[%d]: \n", l);
	}
	board.board[board_size - 1][board_size] = '\0';
	board.board_size = board_size;
	board.y = 0;
	board.x = 0;
	//free(board_row);
	//
	//printf("*************Board set, board size:  %d**********\n", board_size);
	//print_matrix_test(board.board);
	//printf("*************Here was a board above**************\n");
	return (board);
}

void			struct_tetrimino(char *tetrimino, short i)
{
	extern t_tetrimino		g_tms[26];

	g_tms[i].index_block1 = ft_find_index(tetrimino, '#', 1);
	g_tms[i].index_block2 = ft_find_index(tetrimino, '#', 2);
	g_tms[i].index_block3 = ft_find_index(tetrimino, '#', 3);
	g_tms[i].index_block4 = ft_find_index(tetrimino, '#', 4);
	g_tms[i].id = i + 1;
	g_tms[i].block1_x = 0;
	g_tms[i].block1_y = 0;
	g_tms[i].block2_x = ft_calc_x(g_tms[i].index_block1, g_tms[i].index_block2);
	g_tms[i].block2_y = ft_calc_y(g_tms[i].index_block1, g_tms[i].index_block2);
	g_tms[i].block3_x = ft_calc_x(g_tms[i].index_block2, g_tms[i].index_block3)
		+ g_tms[i].block2_x;
	g_tms[i].block3_y = ft_calc_y(g_tms[i].index_block2, g_tms[i].index_block3)
		+ g_tms[i].block2_y;
	g_tms[i].block4_x = ft_calc_x(g_tms[i].index_block3, g_tms[i].index_block4)
		+ g_tms[i].block3_x;
	g_tms[i].block4_y = ft_calc_y(g_tms[i].index_block3, g_tms[i].index_block4)
		+ g_tms[i].block3_y;
	g_tms[i].letter = 'A' + i;
	g_tms[i].x = -1;
	g_tms[i].y = -1;
}
