/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 18:15:06 by pleroux           #+#    #+#             */
/*   Updated: 2019/09/28 23:49:38 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		{
			ft_putstr("0x");
			ft_putstr(ft_itoa_base_long(
						(t_uint64)(alloc + 1),
						"0123456789ABCDEF"));
			ft_putstr(" - 0x");
			ft_putstr(ft_itoa_base_long(
						(t_uint64)((void*)(alloc + 1) + alloc->length),
						"0123456789ABCDEF"));
			ft_putstr(" : ");
			ft_putnbr(alloc->length);
			ft_putendl(" octets");
		}
		*total += alloc->length;
		alloc = alloc->next;
	}
}

void				show_all_zone(t_zone *zone, char *name, t_uint64 *total)
{
	if (!zone)
		return ;
	ft_putstr(name);
	ft_putstr(" : 0x");
	ft_putendl(ft_itoa_base_long((t_uint64)zone, "0123456789ABCDEF"));
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
	pthread_mutex_lock(&g_mutex);
	ft_putstr("Total : ");
	ft_putnbr(total);
	ft_putendl(" octets");
	pthread_mutex_unlock(&g_mutex);
}
