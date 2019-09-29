/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 15:19:45 by pleroux           #+#    #+#             */
/*   Updated: 2017/11/16 11:41:26 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char		*ft_strnstr(const char *hay, const char *need, size_t len)
{
	size_t		i;
	size_t		j;

	i = 0;
	while (hay[i] && i < len)
	{
		j = 0;
		while (hay[i + j] == need[j] && hay[i] && need[j]
				&& (i + j) < len)
			j++;
		if (need[j] == '\0')
			return ((char *)(hay + i));
		i++;
	}
	return (NULL);
}
