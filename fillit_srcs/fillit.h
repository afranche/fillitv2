/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduriez <eduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 14:08:27 by eduriez           #+#    #+#             */
/*   Updated: 2017/11/24 17:53:56 by aaissaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <stdint.h>
# include "libft.h"

/*
**	t_tetrimino
**
**	Represents a Tetrimino. We use a uint64_t (unsigned long long) which
**	contains the actual piece information since we're placing the pieces
**	on a map which is also a uint64_t using bitwise operations and masking.
**
**	This tetrimino:
**		#...
**		#...
**		#...
**		#...
**
**	gives us the following bit representation (once placed on a uint64_t):
**		1000000000000000100000000000000010000000000000001000000000000000
**		(9223512776490647552)
**
**	where UlONG_MAX equals to:
**		1111111111111111111111111111111111111111111111111111111111111111
**		(18446744073709551615)
**
**	This way, we ensure that the uint64_t can hold our output map.
*/

# define BUFF_SIZE 21

typedef	struct	s_tetrimino
{
	uint64_t			tetri;
	char				letter;
	int					x;
	int					y;
	int					width;
	int					height;
}				t_tetrimino;

int				ft_parse(const int fd, t_tetrimino *t);
int				resolve(t_tetrimino *ts, const int tc, uint16_t *map);
int				t_fits(const t_tetrimino *t, uint16_t *map);
void			t_bits(const t_tetrimino *t, uint16_t *map);
#endif
