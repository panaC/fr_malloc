/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shift_nb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 17:42:47 by pleroux           #+#    #+#             */
/*   Updated: 2018/05/02 17:39:23 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <libft.h>

int				ft_strlennb(const char *nptr)
{
	size_t		i;
	int			ret;

	i = 0;
	ret = 0;
	if (!nptr)
		return (0);
	while (nptr[i] && ft_isspace((int)nptr[i]))
		++i;
	if (nptr[i] == '-')
		++i;
	else if (nptr[i] == '+')
		++i;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		++i;
		++ret;
	}
	while (nptr[i] && ft_isspace((int)nptr[i]))
		++i;
	if (i == ft_strlen(nptr))
		return (ret);
	return (-1);
}
