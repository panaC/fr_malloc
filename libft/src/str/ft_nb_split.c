/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nb_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 15:31:45 by pierre            #+#    #+#             */
/*   Updated: 2018/01/03 18:41:10 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static char		*shift_car(char const *s, char c)
{
	int		i;

	i = 0;
	while (s[i] && s[i] == c)
		i++;
	return ((char*)(s + i));
}

int				ft_nb_split(char const *s, char c)
{
	int			count;
	char		*src;

	count = 0;
	src = (char*)s;
	while (*src)
	{
		if (*src == c || src == s)
		{
			count++;
			src = shift_car(src, c);
		}
		if (*src != '\0')
			src++;
	}
	src--;
	if (*src == c)
		count--;
	return (count);
}
