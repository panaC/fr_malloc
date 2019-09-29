/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 14:56:31 by pleroux           #+#    #+#             */
/*   Updated: 2017/11/15 11:22:04 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "../../includes/libft.h"

char		*ft_strrchr(const char *s, int c)
{
	int		t;

	t = (int)ft_strlen((char*)s);
	while (t >= 0)
	{
		if (s[t] == (char)c)
			return ((char*)(s + t));
		t--;
	}
	return (NULL);
}
