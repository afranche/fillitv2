/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduriez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 08:17:11 by eduriez           #+#    #+#             */
/*   Updated: 2017/11/10 10:21:29 by eduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

static int			ft_search_str(size_t start, const char *haystack,
					const char *needle, size_t len)
{
	int	j;

	j = 0;
	while (start < len && haystack[start] == needle[j] && needle[j] != '\0')
	{
		start++;
		j++;
	}
	if (needle[j] == '\0')
		return (1);
	else
		return (0);
}

char				*ft_strnstr(const char *haystack, const char *needle,
					size_t len)
{
	size_t	i;
	int		found;
	int		start_word;

	start_word = 0;
	found = 0;
	i = 0;
	if (needle[0] == '\0')
		return (char*)(haystack);
	while (i < len && !found)
	{
		if (haystack[i] == needle[0])
		{
			start_word = i;
			found = ft_search_str(start_word, haystack, needle, len);
		}
		i++;
	}
	if (found)
		return (char*)(haystack + start_word);
	return (NULL);
}
