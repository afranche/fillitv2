/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaissaou <aaissaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 16:35:19 by aaissaou          #+#    #+#             */
/*   Updated: 2017/11/24 14:29:01 by aaissaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "fillit.h"

/*
**	can_it_fit
**	toggle_bits
**
**	Respective functions tests if a piece can fit in the map (given its {x,y}
**	pos).
**
**	Toggle bits just place the piece bits on the map.
*/

int		t_fits(const t_tetrimino *t, uint16_t *map)
{
	return (!(*(uint64_t *)(map + t->y) & (t->tetri >> t->x)));
}

void	t_bits(const t_tetrimino *t, uint16_t *map)
{
	*(uint64_t *)(map + t->y) ^= t->tetri >> t->x;
}
