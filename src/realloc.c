/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 20:26:11 by pleroux           #+#    #+#             */
/*   Updated: 2019/07/27 21:57:27 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include <errno.h>
#include "malloc.h"

void			*ft_realloc(void *ptr, size_t size)
{
	void		*new;

	if (ptr == NULL)
		return (NULL);
	if ((new = ft_malloc(size)))
	{
		ft_memcpy(new, ptr, size);
		errno = 0;
		ft_free(ptr);
		if (errno == FREE_ERROR)
		{
			ft_free(new);
			return (NULL);
		}
		return (new);
	}
	return (NULL);
}
