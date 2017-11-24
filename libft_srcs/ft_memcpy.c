/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduriez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 11:23:11 by eduriez           #+#    #+#             */
/*   Updated: 2017/11/09 18:08:59 by eduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*dest_char;
	const unsigned char *src_char;

	src_char = (const unsigned char*)src;
	dest_char = (unsigned char*)dst;
	i = 0;
	while (i < n)
	{
		dest_char[i] = (unsigned char)src_char[i];
		i++;
	}
	return (dest_char);
}
