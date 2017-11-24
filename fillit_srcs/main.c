/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduriez <eduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 14:21:58 by eduriez           #+#    #+#             */
/*   Updated: 2017/11/24 18:02:21 by aaissaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include "libft.h"
#include "fillit.h"

int	main(int argc, char **argv)
{
	uint16_t	map[16];
	t_tetrimino	t[26];
	int			tc;

	tc = 0;
	ft_bzero(map, 16);
	if (argc == 2)
	{
		if ((tc = ft_parse(open(argv[1], O_RDONLY), t)) == 0)
			ft_putstr("error\n");
		else
		{
			if (resolve(t, tc, map) == 0)
				ft_putstr("error\n");
		}
	}
	else
		ft_putstr("usage: ./fillit filename\n");
	return (0);
}
