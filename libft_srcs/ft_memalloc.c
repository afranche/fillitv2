/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduriez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 20:30:07 by eduriez           #+#    #+#             */
/*   Updated: 2017/11/08 20:57:00 by eduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*mem_area;

	mem_area = malloc(size);
	if (mem_area == NULL)
		return (NULL);
	else
		ft_bzero(mem_area, size);
	return (mem_area);
}
