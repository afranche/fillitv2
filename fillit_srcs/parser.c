/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduriez <eduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 18:00:04 by eduriez           #+#    #+#             */
/*   Updated: 2017/11/24 18:02:56 by aaissaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "fillit.h"
#include "libft.h"

static void			get_boundaries(const char *tetrimino, char *boundaries)
{
	unsigned char	i;

	i = 0;
	boundaries[0] = 3;
	boundaries[1] = 0;
	boundaries[2] = 3;
	boundaries[3] = 0;
	while (i < 20)
	{
		if (tetrimino[i] == '#')
		{
			if (i % 5 < boundaries[0])
				boundaries[0] = i % 5;
			if (i % 5 > boundaries[1])
				boundaries[1] = i % 5;
			if (i / 5 < boundaries[2])
				boundaries[2] = i / 5;
			if (i / 5 > boundaries[3])
				boundaries[3] = i / 5;
		}
		i++;
	}
}

static int			is_linked(const char *b)
{
	int i;
	int links;

	links = 0;
	i = 0;
	while (i < 20)
	{
		if (b[i] == '#')
		{
			if ((i + 1) < 20 && b[i + 1] == '#')
				links++;
			if ((i - 1) >= 0 && b[i - 1] == '#')
				links++;
			if ((i + 5) < 20 && b[i + 5] == '#')
				links++;
			if ((i - 5) >= 0 && b[i - 5] == '#')
				links++;
		}
		i++;
	}
	return (links == 6 || links == 8);
}

/*
** brsiz = Byte-read size
*/

static int			is_valid(const char *b, const int rsize)
{
	int	i;
	int	tb;

	tb = 0;
	i = 0;
	while (i < 20)
	{
		if (i % 5 < 4)
		{
			if (!(b[i] == '#' || b[i] == '.'))
				return (0);
			else if (b[i] == '#' && ++tb > 4)
				return (0);
		}
		else if (b[i] != '\n')
			return (0);
		i++;
	}
	if (rsize == 21 && b[20] != '\n')
		return (0);
	if (!is_linked(b))
		return (0);
	return (1);
}

static t_tetrimino	make_tetrimino(const char *tetrimino, const char letter)
{
	t_tetrimino		t;
	char			bs[4];
	int				x;
	int				y;

	get_boundaries(tetrimino, bs);
	t.width = bs[1] - bs[0] + 1;
	t.height = bs[3] - bs[2] + 1;
	t.letter = letter;
	t.tetri = 0;
	y = 0;
	while (y < t.height)
	{
		x = 0;
		while (x < t.width)
		{
			if (tetrimino[(bs[0] + x) + (bs[2] + y) * 5] == '#')
				t.tetri |= (1L << (16 * (y + 1) - 1 - x));
			x++;
		}
		y++;
	}
	return (t);
}

int					ft_parse(const int fd, t_tetrimino *t)
{
	char	buffer[BUFF_SIZE + 1];
	char	tmp[BUFF_SIZE + 1];
	int		ret;
	int		i;
	char	letter;

	letter = 'A';
	i = 0;
	if (fd == -1)
		return (0);
	while ((ret = read(fd, buffer, BUFF_SIZE)) >= 20)
	{
		if (i == 26)
			return (0);
		if (is_valid(buffer, ret) == 0)
			return (0);
		t[i++] = make_tetrimino(buffer, letter++);
		ft_memcpy(tmp, buffer, BUFF_SIZE + 1);
		ft_bzero(buffer, BUFF_SIZE + 1);
	}
	if (tmp[20] == '\n')
		return (0);
	if (ret != 0)
		return (0);
	return (letter - 'A');
}
