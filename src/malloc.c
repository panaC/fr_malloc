/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 19:14:44 by pleroux           #+#    #+#             */
/*   Updated: 2019/07/25 14:45:44 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/mman.h>
#include <ft_printf.h>
#include "malloc.h"

t_mem			*g_mem = {NULL, NULL, NULL};

void			*malloc_brain(size_t size, t_zone **zone, t_e_size e_size)
{
	t_alloc		*tmp;

	while (((tmp = get_set_alloc_zone(zone, size))) == NULL)
	{
		if (push_back_zone(zone, new_zone(e_sizei, size)) == NULL)
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

