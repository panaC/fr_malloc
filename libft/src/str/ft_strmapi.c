/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 14:43:34 by pleroux           #+#    #+#             */
/*   Updated: 2017/11/16 12:32:35 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "../../includes/libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char		*ret;
	size_t		i;
	size_t		t;

	if (!s)
		return (NULL);
	t = ft_strlen(s);
	ret = (char*)ft_strnew(t);
	if (!ret)
		return (NULL);
	i = 0;
	while (i < t)
	{
		ret[i] = f(i, s[i]);
		i++;
	}
	return (ret);
}
