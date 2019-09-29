/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 15:19:07 by pleroux           #+#    #+#             */
/*   Updated: 2017/11/16 10:00:31 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "../../includes/libft.h"

void		*ft_memdup(const void *mem, size_t size)
{
	void		*out;

	if (!(out = (void*)ft_memalloc(size)))
		return (NULL);
	ft_memcpy(out, mem, size);
	return (out);
}
