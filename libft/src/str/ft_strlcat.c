/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 13:21:49 by pleroux           #+#    #+#             */
/*   Updated: 2017/11/16 12:31:57 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "../../includes/libft.h"

size_t			ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t		i;
	size_t		td;
	size_t		ts;

	i = 0;
	td = ft_strlen(dest);
	ts = ft_strlen(src);
	if (td >= size)
		return (size + ts);
	while (src[i] && (td + i) < (size - 1))
	{
		dest[td + i] = src[i];
		i++;
	}
	dest[td + i] = '\0';
	return (td + ts);
}
