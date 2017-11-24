/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduriez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 13:42:08 by eduriez           #+#    #+#             */
/*   Updated: 2017/11/13 19:47:33 by eduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
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
			dup[i] = f(s[i]);
			i++;
		}
	}
	return (dup);
}
