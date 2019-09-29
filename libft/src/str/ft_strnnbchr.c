/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnnbchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 11:43:55 by pleroux           #+#    #+#             */
/*   Updated: 2018/05/01 11:49:29 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <libft.h>

t_uint32		ft_strnnbchr(t_string s, size_t size, int c)
{
	t_uint32	n;

	n = 0;
	while (s && *s && size)
	{
		++s;
		--size;
		if (*s == c)
			++n;
	}
	return (n);
}
