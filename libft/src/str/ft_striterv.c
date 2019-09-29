/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striterv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 11:33:54 by pleroux           #+#    #+#             */
/*   Updated: 2018/05/01 11:50:41 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_bool		ft_striterv(char *s, int (*f)(int))
{
	if (!s || !f)
		return (FALSE);
	while (*s)
	{
		if (!f(*s))
			return (FALSE);
		++s;
	}
	return (TRUE);
}
