/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 20:26:11 by pleroux           #+#    #+#             */
/*   Updated: 2019/09/28 21:19:57 by pleroux          ###   ########.fr       */
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

	ft_putstr("REALLOC\n");
	ft_putnbr((int)ptr);
	ft_putchar('\n');
	if (ptr == NULL)
		return (malloc(size));
	ft_putstr("a\n");
	if ((new = malloc(size)))
	{
		
		ft_putnbr(size);
		ft_putstr("\nb\n");
		ft_memcpy(new, ptr, ((t_alloc*)ptr)->length);
		ft_putstr("c\n");
		errno = 0;
		ft_putstr("d\n");
		free(ptr);
		ft_putstr("e\n");
		if (errno == FREE_ERROR)
		{
			ft_putstr("f\n");
			free(new);
			return (NULL);
		}
		ft_putstr("REALLOC_OUT1\n");
		return (new);
	}
	ft_putstr("REALLOC_OUT2\n");
	return (NULL);
}
