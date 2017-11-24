/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduriez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 14:48:35 by eduriez           #+#    #+#             */
/*   Updated: 2017/11/09 16:26:42 by eduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	length_src;
	size_t	length_initial_dst;
	size_t	number_chars_to_append;
	size_t	size_returned;
	int		i;

	i = 0;
	length_initial_dst = ft_strlen(dst);
	length_src = ft_strlen(src);
	number_chars_to_append = 0;
	if (size <= length_initial_dst)
		size_returned = length_src + size;
	else
	{
		size_returned = length_src + length_initial_dst;
		number_chars_to_append = size - length_initial_dst - 1;
		while (number_chars_to_append > 0)
		{
			dst[length_initial_dst + i] = src[i];
			i++;
			number_chars_to_append--;
		}
		dst[length_initial_dst + i] = '\0';
	}
	return (size_returned);
}
