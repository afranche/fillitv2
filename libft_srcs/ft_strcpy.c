/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduriez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 12:21:55 by eduriez           #+#    #+#             */
/*   Updated: 2017/11/09 18:19:49 by eduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	size_t	size_src;

	size_src = ft_strlen(src);
	dst = ft_strncpy(dst, src, size_src);
	dst[size_src] = '\0';
	return (dst);
}
