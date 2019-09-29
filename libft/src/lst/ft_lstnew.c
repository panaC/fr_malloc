/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 15:04:50 by pleroux           #+#    #+#             */
/*   Updated: 2017/11/16 10:00:46 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "../../includes/libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*ret;

	if (!(ret = (t_list*)ft_memalloc(sizeof(*ret))))
		return (NULL);
	if (content)
	{
		ret->content = ft_memdup(content, content_size);
		ret->content_size = content_size;
	}
	else
	{
		ret->content = NULL;
		ret->content_size = 0;
	}
	ret->next = NULL;
	return (ret);
}
