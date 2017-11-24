/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduriez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 09:10:08 by eduriez           #+#    #+#             */
/*   Updated: 2017/11/13 17:40:46 by eduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

static	int	ft_is_number_ok(int size_limit, int sign_number,
					const int number_translated)
{
	if (size_limit == 20 && sign_number == -1)
		return (0);
	else if (size_limit == 20 && sign_number == 1)
		return (-1);
	else
		return (number_translated * sign_number);
}

int			ft_atoi(const char *str)
{
	int		i;
	int		number_translated;
	int		sign_number;
	int		size_limit;

	size_limit = 0;
	sign_number = 1;
	number_translated = 0;
	i = 0;
	while (str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
			|| str[i] == '\r' || str[i] == '\f' || str[i] == ' ')
		i++;
	if (str[i] == '-')
		sign_number = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0' && size_limit < 20)
	{
		number_translated *= 10;
		number_translated = number_translated + (str[i] - 48);
		i++;
		size_limit++;
	}
	return (ft_is_number_ok(size_limit, sign_number, number_translated));
}
