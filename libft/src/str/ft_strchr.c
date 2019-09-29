/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 14:37:24 by pleroux           #+#    #+#             */
/*   Updated: 2017/11/15 13:56:18 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "../../includes/libft.h"

char		*ft_strchr(const char *s, int c)
{
	char		*ret;
	size_t		ts;

	ret = (char*)s;
	ts = ft_strlen(ret);
	while (*ret && *ret != (char)c)
		ret++;
	if (ret == (s + ts) && *ret != (char)c)
		return (NULL);
	return (ret);
}
