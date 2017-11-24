/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduriez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 14:18:12 by eduriez           #+#    #+#             */
/*   Updated: 2017/11/14 14:22:04 by eduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list	*current_elem;

	if (lst != NULL)
	{
		current_elem = lst;
		while (current_elem != NULL)
		{
			f(current_elem);
			lst = lst->next;
			current_elem = lst;
		}
	}
}
