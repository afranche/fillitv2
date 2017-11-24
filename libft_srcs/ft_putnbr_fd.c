/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduriez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 15:59:48 by eduriez           #+#    #+#             */
/*   Updated: 2017/11/14 19:02:59 by eduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
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

void			ft_putnbr_fd(int n, int fd)
{
	int		power_max;
	size_t	i;

	i = 0;
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else
	{
		power_max = ft_calc_power_max(n);
		if (n < 0)
		{
			ft_putchar_fd('-', fd);
			n *= -1;
		}
		while (power_max >= 1)
		{
			ft_putchar_fd(n / power_max + 48, fd);
			n -= (n / power_max) * power_max;
			power_max /= 10;
		}
	}
}
