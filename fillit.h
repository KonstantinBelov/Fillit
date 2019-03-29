/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbelov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 17:46:35 by kbelov            #+#    #+#             */
/*   Updated: 2019/03/27 19:19:16 by kbelov           ###   ########.fr       */
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

void				fillit(char **tetriminos, short num, short i);
int					verify_input(int fd);
int					prepare_tetrimino(char **tetriminos, short i);
int					check_tetrimino(char *tetr);

typedef struct		s_tetrimino
{
	short			id;
	short			block1_x;
	short			block1_y;
	short			block2_x;
	short			block2_y;
	short			block3_x;
	short			block3_y;
	short			block4_x;
	short			block4_y;
	char			letter;
}					t_tetrimino;

#endif
