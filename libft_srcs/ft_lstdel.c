/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduriez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 09:25:19 by eduriez           #+#    #+#             */
/*   Updated: 2017/11/14 18:29:58 by eduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*current_elem;

	if (alst != NULL)
	{
		current_elem = *alst;
		while (current_elem != NULL)
		{
			ft_lstdelone(&current_elem, del);
			*alst = (*alst)->next;
			current_elem = *alst;
		}
		*alst = NULL;
	}
}
