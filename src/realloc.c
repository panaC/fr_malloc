/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 20:26:11 by pleroux           #+#    #+#             */
/*   Updated: 2019/07/23 20:46:33 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "malloc.h"

void			*ft_realloc(void *ptr, size_t size)
{
	t_alloc		*arg;
	char		*new;
	size_t		length;

	arg = (t_alloc*)((t_alloc)ptr - 1);
	if (arg->length >= size)
	{
		return (arg);
	}
	length = arg->length;
	arg->length = 0;
	new = (char*)malloc_tiny_small(size, (t_zone*)ptr->zone, ptr->e_size);
	if (ptr != new && new != NULL)
	{
		ft_memcpy(new, ptr, length);
	}
	return ((void*)new);
}
