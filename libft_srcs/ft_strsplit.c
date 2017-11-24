/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduriez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 18:22:33 by eduriez           #+#    #+#             */
/*   Updated: 2017/11/13 20:08:21 by eduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

static int			ft_count_words(const char *str, char sep)
{
	int	i;
	int	number_words;

	i = 0;
	number_words = 0;
	while (str[i] != '\0')
	{
		if (str[i] != sep)
		{
			while (str[i] != sep && str[i] != '\0')
				i++;
			number_words++;
		}
		else
		{
			while (str[i] == sep && str[i] != '\0')
				i++;
		}
	}
	return (number_words);
}

static char			*ft_fill_word(const char *string_to_split, char sep,
					unsigned int *start_word)
{
	size_t				size_str;
	unsigned	int		i;
	char				*new_str;

	new_str = NULL;
	i = *start_word;
	size_str = 0;
	while (string_to_split[i] != sep && string_to_split[i] != '\0')
		i++;
	size_str = (size_t)i - *start_word;
	new_str = ft_strsub(string_to_split, *start_word, size_str);
	if (string_to_split[i] == sep)
	{
		while (string_to_split[i] == sep)
			i++;
		*start_word = i;
	}
	return (new_str);
}

static char			**ft_do_split(const char *string_to_split, char sep,
					int number_words)
{
	int					i;
	char				**string_splitted;
	unsigned	int		start_word;

	start_word = 0;
	i = 0;
	string_splitted = (char**)ft_memalloc((number_words + 1) * sizeof(char*));
	if (string_splitted == NULL)
		return (NULL);
	else
	{
		while (string_to_split[start_word] == sep)
			start_word++;
		while (i < number_words)
		{
			string_splitted[i] = ft_fill_word(string_to_split, sep,
								&start_word);
			i++;
		}
	}
	return (string_splitted);
}

char				**ft_strsplit(const char *s, char c)
{
	int		number_words;
	char	**string_splitted;

	string_splitted = NULL;
	number_words = 0;
	if (s == NULL)
		return (NULL);
	else
	{
		number_words = ft_count_words(s, c);
		string_splitted = ft_do_split(s, c, number_words);
		if (string_splitted == NULL)
			return (NULL);
		string_splitted[number_words] = 0;
	}
	return (string_splitted);
}
