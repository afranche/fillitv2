/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduriez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 19:43:00 by eduriez           #+#    #+#             */
/*   Updated: 2017/11/13 18:44:01 by eduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned	char	*char_s1;
	unsigned	char	*char_s2;
	size_t				i;

	i = 0;
	char_s1 = (unsigned char*)s1;
	char_s2 = (unsigned char*)s2;
	while (i < n && char_s1[i] == char_s2[i])
		i++;
	if (i == n)
		return (0);
	else
		return (char_s1[i] - char_s2[i]);
}
