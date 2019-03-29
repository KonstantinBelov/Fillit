/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbelov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 19:36:26 by kbelov            #+#    #+#             */
/*   Updated: 2019/03/29 02:11:02 by kbelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fillit.h"

int			fillit()
{
	
char		**place_tms(t_tetrimino *tms, board)
{
	


char		**set_board(short board_size)
{
	char	board[board_size][board_size + 1];
	char	board_row[board_size + 1];
	short	i;
	char	*tmp;

	i = -1;
	while (i++ < board_size)
		board_row[i] = '.';
	board_row[i] = '\n';
	i = 0;
	while (i < board_size)
	{
		tmp = ft_strdup(board_row);
		board[i] = tmp;
		i++;
	}
	return (board);
}


