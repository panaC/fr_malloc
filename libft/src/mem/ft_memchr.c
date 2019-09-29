/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 09:19:59 by pleroux           #+#    #+#             */
/*   Updated: 2017/11/10 10:14:20 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void		*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ret;
	size_t			i;

	i = 0;
	ret = (unsigned char*)s;
	while (i < n && (unsigned char)c != ret[i])
		i++;
	return (i == n ? NULL : ret + i);
}
