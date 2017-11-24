/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduriez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 11:23:27 by eduriez           #+#    #+#             */
/*   Updated: 2017/11/10 11:39:10 by eduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	ft_strclr(char *s)
{
	size_t	length_s;

	if (s != NULL)
	{
		length_s = ft_strlen(s);
		ft_bzero(s, length_s);
	}
}
