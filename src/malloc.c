/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 19:14:44 by pleroux           #+#    #+#             */
/*   Updated: 2019/09/28 23:01:56 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdlib.h>
// #include <stdio.h>
#include <sys/mman.h>
#include <unistd.h>
#include <errno.h>
#include <libft.h>
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
	// printf("new zone %p : %zu : %p\n", ret, size, ret->next);
	return (ret);
}

t_alloc			*get_set_alloc_zone(t_zone *zone, size_t size)
{
	t_alloc		*tmp;
	t_alloc		*tmp_end;

	if (zone)
	{
		tmp = (t_alloc*)((void*)zone + sizeof(t_zone));
		tmp_end = (t_alloc*)((void*)tmp + sizeof(t_alloc) + tmp->length);

		// printf("   tmp %#018x : tmp_end %#018x\n", tmp, tmp_end);
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
		if ((void*)zone + sizeof(t_zone) + zone->length - (void*)tmp_end >= \
				(long)(size + sizeof(t_alloc)))
		{
			tmp_end->length = size;
			tmp_end->next = 0;
			tmp->next = tmp_end;
			return (tmp_end);
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
		if (zone && zone->next)
			zone = zone->next;
		else
		{
			zone = push_back_zone(head, new_zone(e_size, size));
			if (!zone)
				return (NULL);
			 // printf("new page requested for %d enum\n", e_size);
		}
	 	// printf("zone %p : length %zu : next %p\n", zone, zone->length, zone->next);
	}
	 // printf("new node %p : length %zu : next %p : content %p\n", tmp, tmp->length, tmp->next, (void*)tmp + sizeof(t_alloc));
	return ((void*)tmp + sizeof(t_alloc));
}

void			*malloc(size_t size)
{
	/*	ft_putstr("malloc ");
		ft_putnbr(size);
		ft_putchar('\n');*/
	if (size < (size_t)(getpagesize() / MIN_ALLOC))
	{
		// printf("TINY\n");
		void* ret = malloc_brain(size, &(g_mem.tiny), TINY);
		/*ft_putstr("malloc tiny ");
		  ft_putnbr((int)ret);
		  ft_putchar('\n');*/
		return ret;
	}
	else if (size < (size_t)(MUL_ALLOC * getpagesize() / MIN_ALLOC))
	{
		void* ret = malloc_brain(size, &(g_mem.small), SMALL);
		// printf("SMALL\n");
		/*ft_putstr("malloc small ");
		  ft_putnbr((int)ret);
		  ft_putchar('\n');*/
		return ret;
	}
	// printf("LARGE ");
	void* ret = malloc_brain(size, &(g_mem.large), LARGE);
	/*ft_putstr("malloc large ");
	  ft_putnbr((int)ret);
	  ft_putchar('\n');*/
	return ret;
}
