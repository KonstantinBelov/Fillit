/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbelov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 17:10:39 by kbelov            #+#    #+#             */
/*   Updated: 2019/03/29 02:07:27 by kbelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*g_tetriminos[26];
short	g_num; //number of pieces
short	g_i;
short	g_board_size;

int			check_tetrimino(char *tetr)
{
	short	number_of_blocks;
	short	number_of_connections;
	short	j;

	number_of_connections = 0;
	number_of_blocks = 0;
	j = 0;
	while (j < 16)
	{
		if (tetr[j] != '.' && tetr[j] != '#')
			return (0);
		if (tetr[j] == '#')
		{
			if (j != 3 && j != 7 && j != 11 && j != 15 && tetr[j + 1] == '#')
				number_of_connections++;
			if (j <= 11 && tetr[j + 4] == '#')
				number_of_connections++;
			if (j != 0 && j != 4 && j != 8 && j != 12 && tetr[j - 1] == '#')
				number_of_connections++;
			if (j >= 4 && tetr[j - 4] == '#')
				number_of_connections++;
			number_of_blocks++;
		}
		j++;
	}
	return ((number_of_blocks == 4 && number_of_connections >= 6) ? 1 : 0);
}

int			prepare_tetrimino(char **tetriminos, short i)
{
	char	tetr[16];
	short	k;
	char	*t;

	t = tetriminos[i];
	if (t[4] != '\n' || t[9] != '\n' || t[14] != '\n' || t[19] != '\n'
			|| t[20] != '\n')
		return (0);
	t[20] = '\0';
	k = 0;
	while (*t != '\0')
	{
		if (*t != '\n')
			tetr[k++] = *t;
		t++;
	}
	if (check_tetrimino(tetr))
	{
		t = ft_strdup(tetr);
		free(g_tetriminos[g_i]);
		g_tetriminos[g_i] = t;
		return (1);
	}
	return (0);
}

int			verify_input(int fd)
{
	char			file[FILE_SIZE_FILLIT + 1];
	int				bytes_read;

	bytes_read = read(fd, file, FILE_SIZE_FILLIT);
	if (((bytes_read + 1 % 21) != 0) || bytes_read < 20)
		return (0);
	file[FILE_SIZE_FILLIT] = '\n';
	g_num = (bytes_read + 1) / 21;
	g_i = 0;
	while (g_i < g_num)
	{
		g_tetriminos[g_i] = ft_strncpy(g_tetriminos[g_i], file, 20);
		g_i++;
		*file += 21;
	}
	while (g_i >= 0)
	{
		if (!prepare_tetrimino(g_tetriminos, g_i))
			return (0);
		g_i++;
	}
	g_board_size = ft_sqrt_rounded_up(g_num * 4) + 2;
	return (1);
}

t_tetrimino	*struct_tetriminos(char **tetriminos, short num)
{
	t_tetrimino		tms[num];
	short			k;
	short			index_blk2;
	short			index_block3;
	short			index_block4;

	k = 0;
	index_blk2 = ft_find_index(g_tetriminos[k], '#', 2);
	index_block3 = ft_find_index(g_tetriminos[k], '#', 3);
	index_block4 = ft_find_index(g_tetriminos[k], '#', 4);
	while (k <= num && tetriminos)
	{
		tms[k].id = k + 1;
		tms[k].block1_x = 0;
		tms[k].block1_y = 0;
		tms[k].block2_x = ft_calc_x(ft_find_index(tetriminos[k], '#', 1), index_blk2);
		tms[k].block2_y = ft_calc_y(ft_find_index(tetriminos[k], '#', 1), index_blk2);
		tms[k].block3_x = ft_calc_x(index_blk2, index_block3);
		tms[k].block3_y = ft_calc_y(index_blk2, index_block3);
		tms[k].block4_x = ft_calc_x(index_block3, index_block4);
		tms[k].block4_y = ft_calc_y(index_block3, index_block4);
		tms[k].letter = 'A' + k;
	}
	return (tms);
}

int			main(int ac, char *av[])
{
	int		fd;
	
	fd = open(av[1], O_RDONLY);
	if (ac == 2 && verify_input(fd))
		fillit(g_tetriminos, g_num, g_i);
	else
		write(1, "usage: fillit source_file", 27);
	return (0);
}
