/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 00:09:35 by pierre            #+#    #+#             */
/*   Updated: 2018/03/15 14:09:38 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "../../includes/libft.h"

static int		len(unsigned long long int n)
{
	int		len;

	len = 0;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char			*ft_itoa_long(long long int n)
{
	char					*ret;
	size_t					l;
	unsigned long long int	nb;
	int						i;

	nb = (unsigned long long int)n;
	if (n == 0)
		return (ft_strdup("0"));
	if (n < 0)
		nb *= -1;
	l = len(nb);
	if (!(ret = ft_strnew(l)))
		return (NULL);
	i = (int)l - 1;
	while (i >= 0)
	{
		ret[i] = (nb % 10) + '0';
		nb /= 10;
		i--;
	}
	return (ret);
}
