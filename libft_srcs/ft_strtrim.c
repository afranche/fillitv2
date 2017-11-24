/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduriez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:18:08 by eduriez           #+#    #+#             */
/*   Updated: 2017/11/16 16:51:57 by eduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

static	char	*ft_do_trim(char const *s, int start, int end)
{
	char	*str_trimmed;

	if (end - start <= 0)
	{
		str_trimmed = ft_strnew(0);
		if (str_trimmed == NULL)
			return (NULL);
		return (str_trimmed);
	}
	str_trimmed = ft_strsub(s, start, end - start);
	if (str_trimmed == NULL)
		return (NULL);
	return (str_trimmed);
}

char			*ft_strtrim(char const *s)
{
	int		start;
	int		end;
	char	*str_trimmed;

	if (!s)
		return (NULL);
	start = 0;
	end = ft_strlen(s);
	if (end == 0)
	{
		str_trimmed = ft_strnew(0);
		if (str_trimmed == NULL)
			return (NULL);
		return (str_trimmed);
	}
	while (s[start] == '\n' || s[start] == '\t' || s[start] == ' ')
		start++;
	while ((s[end - 1] == '\n' || s[end - 1] == '\t' || s[end - 1] == ' ')
			&& end > start)
		end--;
	return (ft_do_trim(s, start, end));
}
