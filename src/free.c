/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 15:09:38 by pleroux           #+#    #+#             */
/*   Updated: 2019/07/21 19:07:59 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/mman.h>
#include <ft_printf.h>
#include <libft.h>
#include "malloc.h"

void		ft_free(void *ptr)
{
	t_alloc		*alloc;
	int			size;

	if (ptr != NULL) {
		alloc = (t_alloc*)(ptr - sizeof(t_alloc));
		size = alloc->length + sizeof(t_alloc);
		if (munmap(alloc, size) < 0)
		{
			ft_printf("ERROR to free %d bytes of memory\n", size);
			return;
		}
		alloc->length = 0; // don't remove from list but set size to 0
	}
}
