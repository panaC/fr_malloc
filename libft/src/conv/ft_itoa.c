/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 19:23:25 by pleroux           #+#    #+#             */
/*   Updated: 2018/01/29 09:29:08 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "../../includes/libft.h"

static int		len(int n)
{
	int		len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char			*ft_itoa(int n)
{
	char			*ret;
	size_t			l;
	unsigned int	nb;
	int				i;

	nb = (unsigned int)n;
	if (n < 0)
		nb *= -1;
	l = len(n);
	if (!(ret = ft_strnew(l)))
		return (NULL);
	i = (int)l - 1;
	while ((i && n < 0) || (n >= 0 && i >= 0))
	{
		ret[i] = (nb % 10) + '0';
		nb /= 10;
		i--;
	}
	if (n < 0)
		ret[i] = '-';
	return (ret);
}
