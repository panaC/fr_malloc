/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 19:14:44 by pleroux           #+#    #+#             */
/*   Updated: 2019/07/25 17:58:30 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/mman.h>
#include <ft_printf.h>
#include "malloc.h"

t_mem			*g_mem = {NULL, NULL, NULL};

t_zone			*push_back_zone(t_zone **list, t_zone *elem)
{
	t_zone		*ret;

	if (*list == NULL) {
		*list = elem;
		return (*list);
	}
	ret = *list;
	while (ret->next) {
		ret = ret->next;
	}
	ret->next = elem;
	return (ret->next);
}

t_zone			*new_zone(t_e_size enum_size, size_t size)
{
	t_zone		*ret;

	if (enum_size == TINY)
	{
		size = (size_t)getpagesize();
	}
	else if (enum_size = SMALL)
	{
		size = MUL_ALLOC * (size_t)getpagesize();
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
	void		*tmp_end;
	void		*zone_end;

	if (zone)
	{
		tmp = (t_alloc*)(zone + 1);
		tmp_end = (void*)(tmp + 1) + tmp->length;
		while(tmp->next)
		{
			if ((void*)tmp->next - tmp_end > size)
			{
				return ((t_alloc*)tmp_end);
			}
			tmp = tmp->next;
			tmp_end = (void*)(tmp + 1) + tmp->length;
		}
		if (zone->length - ((tmp_end - (void*)(zone + 1)) > size))
		{
			tmp->next = 0;
			tmp = tmp->next;
			return (tmp);
		}
	}
	return (NULL);
}

void			*malloc_brain(size_t size, t_zone **zone, t_e_size e_size)
{
	t_alloc		*tmp;

	while (((tmp = get_set_alloc_zone(zone, size))) == NULL)
	{
		if (push_back_zone(zone, new_zone(e_size, size)) == NULL)
		{
			return (NULL);
		}
	}
	tmp->length = size;
	return ((void*)(tmp + 1));
}

void			*ft_malloc(size_t size)
{
	t_alloc		*ret;

	if (size < getpagesize() / MIN_ALLOC)
	{
		return (malloc_brain(size, g_mem->tiny, TINY);
	}
	else if (size < MUL_ALLOC * getpagesize() / MIN_ALLOC)
	{
		return (malloc_brain(size, g_mem->small, SMALL);
	}
	return (malloc_brain(size. g_mem->large LARGE);
}

