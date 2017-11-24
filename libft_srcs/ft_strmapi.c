/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduriez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 14:10:31 by eduriez           #+#    #+#             */
/*   Updated: 2017/11/13 19:48:36 by eduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*dup;
	int		i;

	i = 0;
	dup = NULL;
	if (s != NULL)
	{
		dup = ft_strdup(s);
		if (dup == NULL)
			return (NULL);
		while (dup[i] != '\0')
		{
			dup[i] = f(i, s[i]);
			i++;
		}
	}
	return (dup);
}
