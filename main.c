/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbelov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 17:10:39 by kbelov            #+#    #+#             */
/*   Updated: 2019/04/11 01:53:38 by kbelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char			**g_tetriminos;
int				g_num;
t_tetrimino		g_tms[26];

int			verify_input(int fd)
{
	extern char		**g_tetriminos;
	char			buf[FILE_SIZE_FILLIT + 1];
	int				bytes_read;
	int				i;
	char			*file;

	bytes_read = read(fd, buf, FILE_SIZE_FILLIT + 1);
	if (((bytes_read + 1) % 21 != 0) || bytes_read < 20)
		return (0);
	g_num = (bytes_read + 1) / 21;
	file = ft_strdup(buf);
	i = 0;
	if (!(g_tetriminos = malloc((g_num + 1) * sizeof(*g_tetriminos))))
		return (0);
	g_tetriminos[g_num] = NULL;
	while (i < g_num)
	{
		g_tetriminos[i] = ft_strnew(20);
		ft_strncpy(g_tetriminos[i], file, 20);
		if (!verify_tetrimino(g_tetriminos[i]))
			return (0);
		i++;
		file += 21;
	}
	return (1);
}

int			main(int ac, char *av[])
{
	extern t_tetrimino	g_tms[26];
	int					fd;
	int					i;

	fd = open(av[1], O_RDONLY);
	if (ac == 2)
	{
		if (verify_input(fd))
		{
			i = 0;
			while (i < g_num)
			{
				struct_tetrimino(g_tetriminos[i], i);
				i++;
			}
			fillit();
		}
		else
			write(1, "error\n", 6);
	}
	else
		write(1, "usage: ./fillit [source_file]\n", 33);
	return (0);
}
