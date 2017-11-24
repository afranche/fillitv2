/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduriez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 15:18:28 by eduriez           #+#    #+#             */
/*   Updated: 2017/11/13 19:56:26 by eduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char				*substr;
	unsigned	int		i;

	i = 0;
	if (s == NULL)
		return (NULL);
	substr = ft_strnew(len);
	if (substr == NULL)
		return (NULL);
	else
	{
		while (i < len)
		{
			substr[i] = s[start + i];
			i++;
		}
	}
	return (substr);
}
