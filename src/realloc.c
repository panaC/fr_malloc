/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 20:26:11 by pleroux           #+#    #+#             */
/*   Updated: 2019/07/25 18:07:40 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include "malloc.h"

void			*ft_realloc(void *ptr, size_t size)
{
	t_alloc		*arg;
	void		*new;

	arg = (t_alloc*)(ptr - sizeof(t_alloc));
	if (arg->length >= size)
		return (arg);
	if ((new = ft_malloc(size)))
	{
		ft_memcpy(new, ptr, size);
		ft_free(ptr);
		return (new);
	}
	return (NULL);
}
