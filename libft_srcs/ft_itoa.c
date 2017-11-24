/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduriez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 11:40:28 by eduriez           #+#    #+#             */
/*   Updated: 2017/11/14 08:08:59 by eduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

static	int		ft_calc_power_max(int n)
{
	int	power_max;

	power_max = 1;
	if (n < 0)
		n *= -1;
	while (n / power_max >= 10)
		power_max *= 10;
	return (power_max);
}

static	char	*ft_treat_sign(int *n, int power_max, size_t *i)
{
	char	*output;

	output = NULL;
	while (power_max > 0)
	{
		power_max /= 10;
		*i = *i + 1;
	}
	if (*n < 0)
	{
		output = ft_strnew(*i + 1);
		if (output == NULL)
			return (NULL);
		output[0] = '-';
		*i = 1;
		*n *= -1;
	}
	else
	{
		output = ft_strnew(*i);
		if (output == NULL)
			return (NULL);
		*i = 0;
	}
	return (output);
}

static	void	ft_do_conv(int n, int power_max, size_t *i, char *output)
{
	while (power_max >= 1)
	{
		output[*i] = n / power_max + 48;
		n -= (output[*i] - 48) * power_max;
		power_max /= 10;
		*i = *i + 1;
	}
}

char			*ft_itoa(int n)
{
	int			power_max;
	char		*output;
	size_t		i;

	output = NULL;
	i = 0;
	if (n == -2147483648)
	{
		output = ft_strnew(12);
		if (output == NULL)
			return (NULL);
		ft_strcpy(output, "-2147483648");
		return (output);
	}
	power_max = ft_calc_power_max(n);
	output = ft_treat_sign(&n, power_max, &i);
	if (output == NULL)
		return (NULL);
	ft_do_conv(n, power_max, &i, output);
	return (output);
}
