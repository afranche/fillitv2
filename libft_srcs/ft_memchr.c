/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduriez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 18:25:43 by eduriez           #+#    #+#             */
/*   Updated: 2017/11/13 18:37:18 by eduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str_search;
	size_t			i;

	str_search = (unsigned char*)s;
	i = 0;
	while (i < n && str_search[i] != (unsigned char)c && str_search[i] != '\0')
		i++;
	if (i < n && str_search[i] == (unsigned char)c)
		return (str_search + i);
	return (NULL);
}
