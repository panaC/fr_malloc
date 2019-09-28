/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 20:26:11 by pleroux           #+#    #+#             */
/*   Updated: 2019/09/28 23:02:43 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <libft.h>
#include <errno.h>
#include "malloc.h"

void			*realloc(void *ptr, size_t size)
{
	void		*new;

	// ft_putstr("REALLOC\n");
	if (ptr == NULL)
		return (malloc(size));
	if ((new = malloc(size)))
	{
		
		ft_putnbr(size);
		ft_memcpy(new, ptr, ((t_alloc*)ptr)->length);
		errno = 0;
		free(ptr);
		if (errno == FREE_ERROR)
		{
			free(new);
			return (NULL);
		}
		return (new);
	}
	return (NULL);
}
