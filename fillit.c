/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbelov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 11:43:12 by kbelov            #+#    #+#             */
/*   Updated: 2019/04/12 05:04:49 by kbelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			fill_board(t_board *board, t_tetrimino *t, int i, int num)
{
	if (i < 0 || (i == 0 && board->board[board->y][board->x] == '\0') ||
			board->board_size == 0)
		return (0);
	if (i >= num)
		return (1);
	if (board->board[board->y][board->x] == '\0')
	{
		--i;
		reposition_last(board, &t[i]);
		board->y = t[i].y;
		board->x = t[i].x;
		iterate_board(board);
	}
	while (!(board->board[board->y][board->x] == '\0'))
	{
		if (try_tetrimino(board, &t[i]))
		{
			place_tetrimino(board, &t[i]);
			i++;
			break ;
		}
		else
			iterate_board(board);
	}
	return (fill_board(board, t, i, num));
}

void		place_tetrimino(t_board *board, t_tetrimino *t)
{
	board->board[board->y][board->x] = t->letter;
	board->board[board->y + t->block2_y][board->x + t->block2_x] = t->letter;
	board->board[board->y + t->block3_y][board->x + t->block3_x] = t->letter;
	board->board[board->y + t->block4_y][board->x + t->block4_x] = t->letter;
	t->y = board->y;
	t->x = board->x;
	board->y = 0;
	board->x = 0;
}

void		reposition_last(t_board *board, t_tetrimino *t)
{
	board->board[t->y][t->x] = '.';
	board->board[t->y + t->block2_y][t->x + t->block2_x] = '.';
	board->board[t->y + t->block3_y][t->x + t->block3_x] = '.';
	board->board[t->y + t->block4_y][t->x + t->block4_x] = '.';
}

int			try_tetrimino(t_board *board, t_tetrimino *t)
{
	if (board->y + t->block4_y < board->board_size &&
		board->x + t->block2_x < board->board_size &&
		board->x + t->block3_x < board->board_size &&
		board->x + t->block4_x < board->board_size &&
		board->x + t->block2_x >= 0 &&
		board->x + t->block3_x >= 0)
	{
		if (board->board[board->y][board->x] == '.' &&
			board->board[board->y + t->block2_y][board->x + t->block2_x] == '.'
			&&
			board->board[board->y + t->block3_y][board->x + t->block3_x] == '.'
			&&
			board->board[board->y + t->block4_y][board->x + t->block4_x] == '.')
			return (1);
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
}
