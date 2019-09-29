/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 18:08:22 by pleroux           #+#    #+#             */
/*   Updated: 2017/11/15 12:40:09 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				i;
	unsigned char		*ss1;
	unsigned char		*ss2;

	if (!n)
		return (0);
	i = 0;
	ss1 = (unsigned char*)s1;
	ss2 = (unsigned char*)s2;
	while ((i < (n - 1) && ss1[i] && ss2[i] && ss1[i] == ss2[i]))
		i++;
	return ((int)(ss1[i] - ss2[i]));
}
