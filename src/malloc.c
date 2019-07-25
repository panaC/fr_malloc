/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 19:14:44 by pleroux           #+#    #+#             */
/*   Updated: 2019/07/25 21:27:53 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/mman.h>
#include <unistd.h>
#include <errno.h>
#include <ft_printf.h>
#include "malloc.h"

t_mem			g_mem = { .tiny = NULL, .small = NULL, .large = NULL};

t_zone			*push_back_zone(t_zone **list, t_zone *elem)
{
	t_zone		*ret;

	if (*list == NULL)
	{
		*list = elem;
		return (*list);
	}
	ret = *list;
	while (ret->next)
	{
		ret = ret->next;
	}
	ret->next = elem;
	return (ret->next);
}

t_zone			*new_zone(t_e_size enum_size, size_t size)
{
	t_zone		*ret;

	if (enum_size == TINY)
		size = (size_t)getpagesize();
	else if (enum_size == SMALL)
		size = MUL_ALLOC * (size_t)getpagesize();
	else
		size += sizeof(t_zone) + sizeof(t_alloc);
	ret = (t_zone*)mmap(NULL, size, PROT_WRITE | PROT_READ, \
			MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
	if (ret == MAP_FAILED)
	{
		errno = ENOMEM;
		return (NULL);
	}
	ret->length = enum_size == LARGE ? \
				  size - sizeof(t_zone) - sizeof(t_alloc) : size;
	ret->next = NULL;
	ft_bzero((void*)ret, size);
	return (ret);
}

t_alloc			*get_set_alloc_zone(t_zone *zone, size_t size)
{
	t_alloc		*tmp;
	void		*tmp_end;

	if (zone)
	{
		tmp = (t_alloc*)(zone + 1);
		tmp_end = (void*)(tmp + 1) + tmp->length;
		while (tmp->next)
		{
			if ((void*)tmp->next - tmp_end > (long)size)
			{
				return ((t_alloc*)tmp_end);
			}
			tmp = tmp->next;
			tmp_end = (void*)(tmp + 1) + tmp->length;
		}
		if (zone->length - ((tmp_end - (void*)(zone + 1)) > (long)size))
		{
			tmp->next = 0;
			tmp = tmp_end;
			return (tmp);
		}
	}
	return (NULL);
}

void			*malloc_brain(size_t size, t_zone **head, t_e_size e_size)
{
	t_alloc		*tmp;
	t_zone		*zone;

	zone = *head;
	while (((tmp = get_set_alloc_zone(zone, size))) == NULL)
	{
		if (((zone = push_back_zone(head, new_zone(e_size, size)))) == NULL)
			return (NULL);
	}
	tmp->length = size;
	return ((void*)(tmp + 1));
}

void			*ft_malloc(size_t size)
{
	if (size < (size_t)(getpagesize() / MIN_ALLOC))
	{
		return (malloc_brain(size, &(g_mem.tiny), TINY));
	}
	else if (size < (size_t)(MUL_ALLOC * getpagesize() / MIN_ALLOC))
	{
		return (malloc_brain(size, &(g_mem.small), SMALL));
	}
	return (malloc_brain(size, &(g_mem.large), LARGE));
}
