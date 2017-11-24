/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduriez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 14:03:47 by eduriez           #+#    #+#             */
/*   Updated: 2017/11/13 18:35:57 by eduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*char_src;
	unsigned char		*char_dest;
	size_t				i;

	i = 0;
	char_src = (unsigned char*)src;
	char_dest = (unsigned char*)dst;
	while (i < n && char_src[i] != (unsigned char)c)
	{
		char_dest[i] = char_src[i];
		i++;
	}
	if (char_src[i] == (unsigned char)c)
	{
		char_dest[i] = char_src[i];
		return (char_dest + i + 1);
	}
	else
		return (NULL);
}
