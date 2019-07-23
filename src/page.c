/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   page.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 19:25:01 by pleroux           #+#    #+#             */
/*   Updated: 2019/07/23 20:38:01 by pleroux          ###   ########.fr       */
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
	return (ret);
}

t_alloc			*get_set_alloc_zone(t_zone *zone, size_t length, t_e_size e)
{
	t_alloc		*tmp;

	if (zone)
	{
		if (zone->alloc == NULL)
		{
			zone->alloc = page + 1;
		}
		tmp = zone->alloc;
		while(tmp)
		{
			if (tmp->length == 0 && \
					((void*)tmp->next - (void*)(tmp + 1)) >= length)
			{
					return tmp;
			}
			tmp = tmp->next;
		}
		if (((void*)zone + page->length - ((void*)(tmp + 1) + tmp->length)) > \
				length)
		{
			tmp = (t_alloc*)((void*)(tmp + 1) + tmp->length);
			tmp->zone = (void*)zone;
			tmp->e_size = e;
			push_back_alloc(&(zone->alloc), tmp);
			return tmp;
		}
	}
	return NULL;
}
