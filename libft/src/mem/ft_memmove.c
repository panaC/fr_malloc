/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:03:30 by pleroux           #+#    #+#             */
/*   Updated: 2017/11/16 14:39:07 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "../../includes/libft.h"

void			*ft_memmove(void *d, const void *s, size_t n)
{
	unsigned char		*dst;
	unsigned char		*src;

	if (d == s || n == 0)
		return (d);
	dst = (unsigned char *)d;
	src = (unsigned char *)s;
	if (src < dst)
		while (n--)
			dst[n] = src[n];
	else
		ft_memcpy(d, s, n);
	return (d);
}
