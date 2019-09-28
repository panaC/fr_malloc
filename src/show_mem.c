/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 18:15:06 by pleroux           #+#    #+#             */
/*   Updated: 2019/09/28 21:25:59 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <libft.h>
#include "malloc.h"

void				show_zone(t_zone *zone, t_uint64 *total)
{
	t_alloc			*alloc;

	if (!zone)
		return ;
	alloc = (t_alloc*)(zone + 1);
	while (alloc)
	{
		if (alloc->length)
			printf("%p - %p : %zu octets\n", alloc + 1, \
					(void*)(alloc + 1) + alloc->length, alloc->length);
		*total += alloc->length;
		alloc = alloc->next;
	}
}

void				show_all_zone(t_zone *zone, char *name, t_uint64 *total)
{
	if (!zone)
		return ;
	printf("%s : %p\n", name, zone);
	while (zone)
	{
		show_zone(zone, total);
		zone = zone->next;
	}
}

void				show_alloc_mem(void)
{
	t_uint64		total;

	total = 0;
	show_all_zone(g_mem.tiny, "TINY", &total);
	show_all_zone(g_mem.small, "SMALL", &total);
	show_all_zone(g_mem.large, "LARGE", &total);
	printf("Total : %ld octets\n", total);
}
