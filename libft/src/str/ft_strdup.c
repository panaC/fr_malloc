/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 10:38:31 by pleroux           #+#    #+#             */
/*   Updated: 2018/01/15 10:34:16 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../includes/libft.h"

char		*ft_strdup(const char *src)
{
	char	*s;
	int		i;

	i = 0;
	s = NULL;
	s = (char *)ft_memalloc(sizeof(char) * ft_strlen(src) + 1);
	if (!s)
		return (NULL);
	while (src[i] != '\0')
	{
		s[i] = src[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}
