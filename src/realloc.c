/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 20:26:11 by pleroux           #+#    #+#             */
/*   Updated: 2019/09/28 23:24:55 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		pthread_mutex_lock(&g_mutex);
		ft_putnbr(size);
		ft_memcpy(new, ptr, ((t_alloc*)ptr)->length);
		errno = 0;
		pthread_mutex_unlock(&g_mutex);
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
