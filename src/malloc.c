/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 19:14:44 by pleroux           #+#    #+#             */
/*   Updated: 2019/09/29 00:10:49 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/mman.h>
#include <unistd.h>
#include <errno.h>
#include <libft.h>
#include "malloc.h"

t_mem			g_mem = { .tiny = NULL, .small = NULL, .large = NULL};

pthread_mutex_t	g_mutex = PTHREAD_MUTEX_INITIALIZER;

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
		size += sizeof(t_zone) + 2 * sizeof(t_alloc);
	ret = (t_zone*)mmap(NULL, size, PROT_WRITE | PROT_READ, \
			MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
	if (ret == MAP_FAILED)
	{
		errno = ENOMEM;
		return (NULL);
	}
	ft_bzero((void*)ret, size);
	ret->length = size - sizeof(t_zone);
	ret->next = NULL;
	return (ret);
}

t_alloc			*get_set_alloc_zone(t_zone *zone, size_t size)
{
	t_alloc		*tmp;
	t_alloc		*tmp_end;

	tmp = (t_alloc*)((void*)zone + sizeof(t_zone));
	tmp_end = (t_alloc*)((void*)tmp + sizeof(t_alloc) + tmp->length);
	while (tmp->next)
	{
		if ((void*)tmp->next - (void*)tmp_end > (long)size)
		{
			tmp_end->length = size;
			tmp_end->next = tmp->next;
			tmp->next = tmp_end;
			return (tmp_end);
		}
		tmp = tmp->next;
		tmp_end = (void*)tmp + sizeof(t_alloc) + tmp->length;
	}
	if ((void*)zone + SZ + zone->length - (void*)tmp_end >= (long)(size + SA))
	{
		tmp_end->length = size;
		tmp_end->next = 0;
		tmp->next = tmp_end;
		return (tmp_end);
	}
	return (NULL);
}

void			*malloc_brain(size_t size, t_zone **head, t_e_size e_size)
{
	t_alloc		*tmp;
	t_zone		*zone;

	zone = *head;
	tmp = NULL;
	while (zone == NULL || ((tmp = get_set_alloc_zone(zone, size))) == NULL)
	{
		if (zone && zone->next)
			zone = zone->next;
		else
		{
			zone = push_back_zone(head, new_zone(e_size, size));
			if (!zone)
				return (NULL);
		}
	}
	return ((void*)tmp + sizeof(t_alloc));
}

void			*malloc(size_t size)
{
	void		*ret;

	pthread_mutex_lock(&g_mutex);
	if (size < (size_t)(getpagesize() / MIN_ALLOC))
	{
		ret = malloc_brain(size, &(g_mem.tiny), TINY);
	}
	else if (size < (size_t)(MUL_ALLOC * getpagesize() / MIN_ALLOC))
	{
		ret = malloc_brain(size, &(g_mem.small), SMALL);
	}
	else
	{
		ret = malloc_brain(size, &(g_mem.large), LARGE);
	}
	pthread_mutex_unlock(&g_mutex);
	return (ret);
}
