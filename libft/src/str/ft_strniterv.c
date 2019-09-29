/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strniterv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 11:36:33 by pleroux           #+#    #+#             */
/*   Updated: 2018/05/01 11:51:09 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <libft.h>

t_bool		ft_strniterv(char *s, size_t n, int (*f)(int))
{
	if (!s || !f)
		return (FALSE);
	while (*s && n)
	{
		if (!f(*s))
			return (FALSE);
		++s;
		--n;
	}
	return (TRUE);
}
