/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduriez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 10:56:30 by eduriez           #+#    #+#             */
/*   Updated: 2017/11/13 19:44:28 by eduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		size_str;
	int		i;
	char	*dup;

	size_str = ft_strlen(s1);
	dup = ft_strnew(size_str);
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (i < size_str)
	{
		dup[i] = s1[i];
		i++;
	}
	return (dup);
}
