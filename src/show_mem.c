/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 18:15:06 by pleroux           #+#    #+#             */
/*   Updated: 2019/07/25 18:30:42 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void					show_zone(t_zone *zone, int *total)
{
	t_alloc			*alloc;

	if (!zone)
		return ;
	alloc = zone + 1;
	while (alloc)
	{
		ft_printf("%x - %x : %d octets\n", \
				alloc + 1, (void*)(alloc + 1) + alloc->length, alloc->length);
		*total += alloc->length;
		alloc = alloc->next;
	}
}

void					show_all_zone(t_zone *zone, char *name, int *total)
{
	if (!zone)
		return ;
	while (zone)
	{
		ft_printf("%s : %x\n", name, zone);
		show_zone(zone, total);
	}
}

void					show_alloc_mem()
{
	unsigned long int	total;

	total = 0;
	show_zone(g_mem->tiny, "TINY",  &total);
	show_zone(g_mem->small, "SMALL", &total);
	show_zone(g_mem->large, "LARGE", &total);
	ft_printf("Total : %ld octets\n", total);
}
