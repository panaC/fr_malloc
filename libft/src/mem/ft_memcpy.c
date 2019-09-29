/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:29:03 by pleroux           #+#    #+#             */
/*   Updated: 2017/11/16 14:30:31 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void		*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*ret;
	unsigned char	*src_cpy;
	size_t			i;

	ret = (unsigned char*)dest;
	src_cpy = (unsigned char*)src;
	i = 0;
	while (i < n)
	{
		ret[i] = src_cpy[i];
		i++;
	}
	return (ret);
}
