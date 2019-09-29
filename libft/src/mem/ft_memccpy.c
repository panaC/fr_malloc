/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 14:02:12 by pleroux           #+#    #+#             */
/*   Updated: 2017/11/16 12:21:24 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void		*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*ret;
	unsigned char	*src_cpy;
	size_t			i;

	i = 0;
	ret = (unsigned char*)dest;
	src_cpy = (unsigned char*)src;
	while (i < n && (unsigned char)c != src_cpy[i])
	{
		ret[i] = src_cpy[i];
		i++;
	}
	if (i == n)
		return (NULL);
	ret[i] = (unsigned char)c;
	return (dest + i + 1);
}
