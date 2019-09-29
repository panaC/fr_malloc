/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 15:07:47 by pleroux           #+#    #+#             */
/*   Updated: 2017/11/15 14:03:33 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char		*ft_strstr(const char *s1, const char *s2)
{
	char	*m;
	char	*s;
	size_t	i;
	size_t	j;

	m = (char*)s1;
	s = (char*)s2;
	i = 0;
	j = 0;
	if (!*s)
		return (m);
	while (m[i])
	{
		j = 0;
		while (s[j] && s[j] == m[i + j])
			j++;
		if (s[j] == '\0')
			return (m + i);
		i++;
	}
	return (NULL);
}
