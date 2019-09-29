/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 19:13:12 by pleroux           #+#    #+#             */
/*   Updated: 2018/05/05 22:23:49 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void		ft_lstcpy(t_list *src, t_list **dest)
{
	t_list	*node;

	*dest = NULL;
	while (src)
	{
		if (!(node = (t_list*)ft_memalloc(sizeof(*node))))
			return ;
		node->content = src->content;
		node->content_size = src->content_size;
		node->next = NULL;
		ft_lstaddtoend(dest, node);
		src = src->next;
	}
}
