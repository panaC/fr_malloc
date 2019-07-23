/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 19:14:44 by pleroux           #+#    #+#             */
/*   Updated: 2019/07/23 20:45:27 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/mman.h>
#include <ft_printf.h>
#include "malloc.h"

t_mem			*g_mem = {NULL, NULL, NULL};

void			*malloc_tiny_small(size_t size, t_zone **zone, t_e_size enum_size)
{
	t_alloc		*tmp;

	while (((tmp = get_set_alloc_zone(zone, size))) == NULL)
	{
		if (push_back_zone(zone, new_zone(enum_size)) == NULL)
		{
			return (NULL);
		}
	}
	tmp->length = size;
	return ((void*)(tmp + 1));
}

void			*ft_malloc(size_t size)
{
	t_alloc		*ret
		
	ret = NULL;
	if (size < getpagesize() / MIN_ALLOC)
	{
		return (malloc_tiny_small(size, g_mem->tiny), TINY);
	}
	else if (size < MUL_ALLOC * getpagesize() / MIN_ALLOC)
	{
		return (malloc_tiny_small(size, g_mem->small), SMALL);
	}
	else
	{
		ret = (t_alloc*)mmap(NULL, size + sizeof(t_alloc), PROT_WRITE | PROT_READ, \
				MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
		if (ret == MAP_FAILED)
		{
			ft_printf("ERROR to allocate %d bytes\n", size);
			return (NULL);
		}
		ret->next = NULL;
		ret->length = size;
		push_back(&(g_mem->large), ret);
		return ((void*)(ret + 1));
	}
	return (ret);
}

