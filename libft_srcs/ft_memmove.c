/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduriez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 15:20:32 by eduriez           #+#    #+#             */
/*   Updated: 2017/11/15 16:51:31 by eduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const unsigned char *src_char;
	unsigned char		*dest_char;
	size_t				i;

	i = 0;
	src_char = (const unsigned char*)src;
	dest_char = (unsigned char*)dst;
	if (src < dst)
	{
		while ((int)len - 1 >= 0)
		{
			dest_char[len - 1] = src_char[len - 1];
			len--;
		}
	}
	else
	{
		while (i < len)
		{
			dest_char[i] = src_char[i];
			i++;
		}
	}
	return (dest_char);
}
