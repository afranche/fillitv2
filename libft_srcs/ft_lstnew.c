/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduriez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 08:38:07 by eduriez           #+#    #+#             */
/*   Updated: 2017/11/14 18:29:25 by eduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"
#include <stdio.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new_elem;

	new_elem = (t_list*)ft_memalloc(sizeof(t_list));
	if (new_elem == NULL)
		return (NULL);
	if (content == NULL)
	{
		new_elem->content = NULL;
		new_elem->content_size = 0;
		new_elem->next = NULL;
	}
	else
	{
		new_elem->content = ft_strdup(content);
		new_elem->content_size = content_size;
		new_elem->next = NULL;
	}
	return (new_elem);
}
