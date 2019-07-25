/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 15:09:38 by pleroux           #+#    #+#             */
/*   Updated: 2019/07/25 20:21:36 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/mman.h>
#include <ft_printf.h>
#include <libft.h>
#include <errno.h>
#include "malloc.h"

int				find_and_delete_alloc(t_alloc *l, t_alloc *find, int *total)
{
	t_alloc		*previous;
	int			delete;

	if (l == NULL)
		return (FALSE);
	previous = NULL;
	delete = FALSE;
	while (l)
	{
		if (l == find)
		{
			if (previous != NULL)
			{
				previous->next = l->next;
				ft_bzero((void*)find, sizeof(t_alloc) + find->length);
				delete = TRUE;
			}
		}
		else
			*total += l->length;
		previous = l;
		l = l->next;
	}
	return (delete);
}

void			delete_zone(t_zone **head, t_zone *zone)
{
	t_zone		*l;
	t_zone		*previous;

	if (!head && !*head)
		return ;
	l = *head;
	previous = NULL;
	while (l)
	{
		if (l == zone)
		{
			if (previous != NULL)
				previous->next = l->next;
			else
				*head = l->next;
			if (munmap((void*)l, l->length + sizeof(t_zone)) < 0)
			{
				ft_printf("ERROR to free %d bytes of memory\n",
						l->length + sizeof(t_zone));
			}
			return ;
		}
		previous = l;
		l = l->next;
	}
}

int				find_and_delete_zone(t_zone **head_zone, t_alloc *find)
{
	int			total;
	t_zone		*zone;

	zone = *head_zone;
	while (zone)
	{
		total = 0;
		if (find_and_delete_alloc((t_alloc*)(zone + 1), find, &total))
		{
			if (total == 0)
				delete_zone(head_zone, zone);
			return (TRUE);
		}
		zone = zone->next;
	}
	return (FALSE);
}

void			ft_free(void *ptr)
{
	t_alloc		*find;

	if (ptr != NULL)
	{
		find = (t_alloc*)(ptr + sizeof(t_alloc));
		if (find_and_delete_zone(&g_mem.large, find))
			return ;
		else if (find_and_delete_zone(&g_mem.small, find))
			return ;
		else if (find_and_delete_zone(&g_mem.tiny, find))
			return ;
		errno = FREE_ERROR;
	}
}
