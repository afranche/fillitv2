/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduriez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 08:22:31 by eduriez           #+#    #+#             */
/*   Updated: 2017/11/09 18:07:14 by eduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*buf;
	size_t			i;

	i = 0;
	buf = (unsigned char*)b;
	while (i < len)
	{
		buf[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
