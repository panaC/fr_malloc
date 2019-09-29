/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 13:56:58 by pleroux           #+#    #+#             */
/*   Updated: 2017/11/13 15:08:11 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "../../includes/libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
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
		ret[i] = f(s[i]);
		i++;
	}
	return (ret);
}
