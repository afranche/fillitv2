/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolver.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaissaou <aaissaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 09:45:05 by aaissaou          #+#    #+#             */
/*   Updated: 2017/11/24 16:17:04 by aaissaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "fillit.h"

static char		*empty_map(int size)
{
	char	*str;
	int		x;
	int		y;

	str = ft_strnew((size + 1) * (size));
	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			str[y * (size + 1) + x] = '.';
			x++;
		}
		str[y * (size + 1) + x] = '\n';
		y++;
	}
	return (str);
}

static void		display(t_tetrimino *t, int count, int size)
{
	char	*map;
	int		x;
	int		y;

	map = empty_map(size);
	while (count > 0)
	{
		y = 0;
		while (y < t->height)
		{
			x = 0;
			while (x < t->width)
			{
				if ((t->tetri >> (16 * (y + 1) - 1 - x)) & 1)
					map[(t->y + y) * (size + 1) + x + t->x] = t->letter;
				x++;
			}
			y++;
		}
		t++;
		count--;
	}
	ft_putstr(map);
	ft_strdel(&map);
}

static	int		resolve_on_size(t_tetrimino *t, uint16_t *m, size_t s, int tc)
{
	t->y = 0;
	while (t->y <= (int)(s - t->height))
	{
		t->x = 0;
		while (t->x <= (int)(s - t->width))
		{
			if (t_fits(t, m))
			{
				t_bits(t, m);
				if (tc - 1 == (int)(t->letter - 'A'))
					return (1);
				if (resolve_on_size(t + 1, m, s, tc) == 1)
					return (1);
				t_bits(t, m);
			}
			t->x++;
		}
		t->y++;
	}
	t->x = 0;
	t->y = 0;
	return (0);
}

int				resolve(t_tetrimino *ts, const int tc, uint16_t *map)
{
	size_t	size;

	size = 2;
	while ((int)(size * size) < tc * 4)
		size++;
	while (!(resolve_on_size(ts, map, size, tc)) && size <= 16)
	{
		ft_bzero(map, sizeof(uint16_t) * 16);
		size++;
	}
	if (size != 0)
	{
		display(ts, tc, size);
		return (1);
	}
	else
		return (0);
}
