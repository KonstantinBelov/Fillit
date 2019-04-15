/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbelov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 10:46:39 by kbelov            #+#    #+#             */
/*   Updated: 2019/04/11 01:54:23 by kbelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			verify_chars(char *tetr)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		if (tetr[i] != '.' && tetr[i] != '#')
			return (0);
		i++;
	}
	return (1);
}

int			verify_connections(char *tetr)
{
	int		number_of_blocks;
	int		number_of_connections;
	int		j;

	number_of_connections = 0;
	number_of_blocks = 0;
	j = 0;
	while (j < 16)
	{
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

int			verify_tetrimino(char *t)
{
	char		tetr[16];
	int			k;

	if (t[4] != '\n' || t[9] != '\n' || t[14] != '\n' || t[19] != '\n')
		return (0);
	t[20] = '\0';
	k = 0;
	while (*t != '\0')
	{
		if (*t != '\n')
			tetr[k++] = *t;
		t++;
	}
	if (verify_chars(tetr) && verify_connections(tetr))
		return (1);
	return (0);
}

void		print_matrix_test(char **matrix)
{
	int		y;
	int		x;

	y = -1;
	while (matrix[++y])
	{
		x = -1;
		while (matrix[y][++x])
			write(1, &matrix[y][x], 1);
	}
	write(1, "\n", 1);
}
