/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 15:09:38 by pleroux           #+#    #+#             */
/*   Updated: 2019/07/25 17:40:56 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/mman.h>
#include <ft_printf.h>
#include <libft.h>
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
				ft_bzero((void*)find, (void*)(find + 1) + find->length);
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
	t_list		*l;
	t_list		*previous;

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
			if (munmap((void*)l, t->length + sizeof(t_zone)) < 0)
			{
				ft_printf("ERROR to free %d bytes of memory\n",
						t->length + sizeof(t_zone));
			}
			return ;
		}
		previous = l;
		l = l->next;
	}
}

int				find_and_delete_zone(t_zone **head_zone, \
		t_zone *zone, t_alloc *find)
{
	int			total;

	while (zone)
	{
		total = 0;
		if (find_and_delete_alloc(zone, find, &total))
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
		if (find_and_delete_zone((t_alloc*)(g_mem->large + 1), find))
			return ;
		else if (find_and_delete_zone((t_alloc*)(g_mem->small + 1), find))
			return ;
		find_and_delete_zone((t_alloc*)(g_mem->tiny + 1), find);
	}
}
