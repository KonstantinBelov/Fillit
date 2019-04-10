/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbelov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 11:43:12 by kbelov            #+#    #+#             */
/*   Updated: 2019/04/10 04:24:17 by kbelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_board		*fill_board(t_board *board, t_tetrimino *t, int i, short num)
{
	extern t_tetrimino	g_tms[26];
	//char				**tmp;

//	printf("\nHere we go new fill_board starts\n");
	//write(1, "\nfuck\n", 6);
	//ft_putnbr(board.y);
	//write(1, " ", 1);
	//ft_putnbr(board.x);
	//write(1, "\n", 1);
	//ft_putnbr(board.board_size);
	//write(1, "\n", 1);
//
	if (i < 0 || (i == 0 && board->board[board->y][board->x] == '\0') ||
			board->board_size == 0)
	{
		board->board_size = 0;
		return (board);
	}
	//write(1, "epta\n", 5);
	if (i >= num)
		return (board);
	//write(1, "ept2\n", 5);
	if (board->board[board->y][board->x] == '\0')
	{
		--i;
		//board->board = reposition_last(board->board, t[i], i);
		reposition_last(board, t[i], i);
		board->y = g_tms[i].y;
		board->x = g_tms[i].x;
	}
	//write(1, "Let's try tetrimino\n", 20);
	if (try_tetrimino(board, t[i]))
	{
		//write(1, "Let's place tetrimino\n", 22);
		//printf("Success!\n");
		//board = place_tetrimino(board, t[i], i);
		place_tetrimino(board, t[i], i);
		i++;
	}
	else
	{
		//write(1, "ept5\n", 5);
		//printf("Going to iterate board from %d:", board->y);
		//printf("%d\n", board->x);
		iterate_board(board);
		//printf("Board iterated to %d:", board->y);
		//printf("%d\n", board->x);
	}
	//write(1, "ept6\n", 5);
	//printf("We are about to return result of fill_board\n");
	return (fill_board(board, t, i, num));
}

void		place_tetrimino(t_board *board, t_tetrimino t, int i)
{
	extern t_tetrimino	g_tms[26];

	board->board[board->y][board->x] = t.letter;
	board->board[board->y + t.block2_y][board->x + t.block2_x] = t.letter;
	board->board[board->y + t.block3_y][board->x + t.block3_x] = t.letter;
	board->board[board->y + t.block4_y][board->x + t.block4_x] = t.letter;
	g_tms[i].y = board->y;
	g_tms[i].x = board->x;
	board->y = 0;
	board->x = 0;
	//printf("Tetrimino %d placed:\n", i + 1);
	//print_matrix_test(board->board);
	//return (board);
}

void		reposition_last(t_board *board, t_tetrimino t, int i)
{
	extern t_tetrimino	g_tms[26];

	board->board[t.y][t.x] = '.';
	board->board[t.y + t.block2_y][t.x + t.block2_x] = '.';
	board->board[t.y + t.block3_y][t.x + t.block3_x] = '.';
	board->board[t.y + t.block4_y][t.x + t.block4_x] = '.';
	if (board->board[t.y][t.x + 1] == '\n')
	{
		g_tms[i].y++;
		g_tms[i].x = 0;
	}
	else
		g_tms[i].x++;
	//printf("Tetrimino %d removed:\n", i + 1);
	//print_matrix_test(board->board);
	//return (board);
}

int			try_tetrimino(t_board *board, t_tetrimino t)
{
	//write(1, "Inside try_tetrimino\n", 21);
	//printf("Trying tetrimino %d at ", t.id);
	//printf("y %d ", board->y);
	//printf("x %d\n", board->x);
	if (board->y + t.block4_y < board->board_size &&
		board->x + t.block2_x < board->board_size &&
		board->x + t.block3_x < board->board_size &&
		board->x + t.block4_x < board->board_size &&
		board->x + t.block2_x >= 0 &&
		board->x + t.block3_x >= 0)
	{
		//write(1, "Size is fine\n", 13);
		/*if (!board->board[board->y][board->x] ||
			!board->board[board->y + t.block2_y][board->x + t.block2_x] ||
			!board->board[board->y + t.block3_y][board->x + t.block3_x] ||
			!board->board[board->y + t.block4_y][board->x + t.block4_x])
			write (1, "SURPRISE, M***R!\n", 17);*/
		if (board->board[board->y][board->x] == '.' &&
			board->board[board->y + t.block2_y][board->x + t.block2_x] == '.' &&
			board->board[board->y + t.block3_y][board->x + t.block3_x] == '.' &&
			board->board[board->y + t.block4_y][board->x + t.block4_x] == '.')
		{
			//write(1, "Free space detected\n", 20);	
			return (1);
		}
		//write(1, "Space occupied\n", 15);
	}
	return (0);
}

void		iterate_board(t_board *board)
{
	if (board->board[board->y][board->x + 1] == '\n')
	{
		board->y++;
		board->x = 0;
	}
	else
		board->x++;
	//return (board);
}
