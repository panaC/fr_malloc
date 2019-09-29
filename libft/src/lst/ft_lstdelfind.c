/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelfind.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 01:49:17 by pleroux           #+#    #+#             */
/*   Updated: 2018/05/05 02:26:45 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

void				ft_lstdelfind(t_list **lst, void *data,
		void *(*f)(void *data_elem, void *data_comp),
		void (*del)(void*, size_t))
{
	t_list		*l;
	t_list		*previous;

	if (!lst && !*lst)
		return ;
	l = *lst;
	previous = NULL;
	while (l)
	{
		if (f(l->content, data))
		{
			if (previous != NULL)
				previous->next = l->next;
			else
				*lst = l->next;
			del(l->content, l->content_size);
			free(l);
			return ;
		}
		previous = l;
		l = l->next;
	}
}
