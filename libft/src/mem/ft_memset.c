/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 10:31:39 by pleroux           #+#    #+#             */
/*   Updated: 2017/11/09 12:58:07 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char *ret;

	ret = (unsigned char*)s;
	while (n)
	{
		ret[n - 1] = (unsigned char)c;
		n--;
	}
	return (ret);
}
