/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   page.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 19:25:01 by pleroux           #+#    #+#             */
/*   Updated: 2019/07/25 14:04:10 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "malloc.h"

t_zone			*new_zone(t_e_size enum_size)
{
	t_zone		*ret;
	size_t		size;

	size = MUL_ALLOC * (size_t)getpagesize();
	if (enum_size == TINY)
	{
		size = (size_t)getpagesize();
	}
	ret = (t_zone*)mmap(NULL, size, PROT_WRITE | PROT_READ, \
			MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
	if (ret == MAP_FAILED)
	{
		ft_printf("ERROR to allocate %s page(s)\n", size / getpagesize());
		return (NULL);
	}
	ft_bzero((void*)ret, size);
	return (ret);
}

t_alloc			*get_set_alloc_zone(t_zone *zone, size_t size, t_e_size e)
{
	t_alloc		*tmp;

	if (zone)
	{
		tmp = (t_alloc*)(zone + 1);
		while(tmp->next)
		{
			if (tmp->length == 0 && \
					((void*)tmp->next - (void*)(tmp + 1)) >= size)
			{
				return (tmp);
			}
			tmp = tmp->next;
		}
		if (zone->length - \
				(((void*)(tmp + 1) + tmp->length) - (void*)(zone + 1)) > size)
		{
			tmp->next = (t_alloc*)((void*)(tmp + 1) + tmp->length);
			tmp = tmp->next;
			tmp->zone = (void*)zone;
			tmp->e_size = e;
			return (tmp);
		}
	}
	return (NULL);
}
