/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduriez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 15:48:58 by eduriez           #+#    #+#             */
/*   Updated: 2017/11/13 19:57:53 by eduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*final_str;
	size_t		length_final_str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	length_final_str = ft_strlen(s1) + ft_strlen(s2);
	final_str = ft_strnew(length_final_str);
	if (final_str == NULL)
		return (NULL);
	ft_strcat(final_str, s1);
	ft_strcat(final_str, s2);
	return (final_str);
}
