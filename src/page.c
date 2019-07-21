/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   page.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 19:25:01 by pleroux           #+#    #+#             */
/*   Updated: 2019/07/21 21:18:34 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "malloc.h"

t_page			*new_page(t_e_size enum_size)
{
	t_page		*ret;
	size_t		size;

	size = MUL_ALLOC * (size_t)getpagesize();
	if (enum_size == TINY)
	{
		size = (size_t)getpagesize();
	}
	ret = (t_page*)mmap(NULL, size, PROT_WRITE | PROT_READ, \
			MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
	if (ret == MAP_FAILED)
	{
		ft_printf("ERROR to allocate %s page(s)\n", size / getpagesize());
	}
	return (ret);
}

int				page_is_full(t_page *page, size_t length)
{
	int 		ret;
	t_alloc		*tmp;
	size_t		total;

	ret = 0;
	total = 0;
	if (page)
	{
		tmp = page->alloc;
		while(tmp)
		{
			total += tmp->length;
			tmp = tmp->next;
		}
	}
	return (ret);
}
