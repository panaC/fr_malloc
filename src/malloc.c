/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 19:14:44 by pleroux           #+#    #+#             */
/*   Updated: 2019/07/21 20:54:30 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/mman.h>
#include <ft_printf.h>
#include "malloc.h"

t_mem		*g_mem = {NULL, NULL, NULL};

/*
** divide per 16 : on 64bit
** sizeof(t_alloc) = 16
** sizeof(t_alloc*) = 8
*/
void		*ft_malloc(size_t size)
{
	t_alloc		*ret = NULL;

	if (size < getpagesize() / MIN_ALLOC) {
		
	}
	else if (size < MUL_ALLOC * getpagesize() / MIN_ALLOC)
	{

	}
	else
	{
		ret = (t_alloc*)mmap(NULL, size + sizeof(t_alloc), PROT_WRITE | PROT_READ, \
				MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
		if (ret == MAP_FAILED)
		{
			ft_printf("ERROR to allocate %d bytes\n", size);
		}
		ret->next = NULL;
		ret->length = size;
		push_back(&(g_mem->large), ret);
		return ((void*)(ret + 1));
	}
	return (ret);
}
