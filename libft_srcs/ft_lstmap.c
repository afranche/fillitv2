/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduriez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 14:24:21 by eduriez           #+#    #+#             */
/*   Updated: 2017/11/17 12:01:07 by eduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*begin_new_list;
	t_list	*current_elem;

	if (lst == NULL)
		return (NULL);
	begin_new_list = f(lst);
	current_elem = begin_new_list;
	lst = lst->next;
	while (lst != NULL)
	{
		current_elem->next = f(lst);
		current_elem = current_elem->next;
		lst = lst->next;
	}
	current_elem = NULL;
	return (begin_new_list);
}
