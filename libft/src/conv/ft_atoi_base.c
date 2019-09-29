/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 11:31:31 by pleroux           #+#    #+#             */
/*   Updated: 2018/01/03 18:36:26 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int	inc(char c, const char *str)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

int			ft_atoi_base(const char *nptr, const char *base)
{
	int		result;
	int		neg;
	int		blen;

	result = 0;
	blen = ft_strlen(base);
	if (blen < 2)
		return (0);
	while (ft_isspace(*nptr))
		nptr++;
	neg = *nptr == '-';
	if (*nptr == '+' || *nptr == '-')
		nptr++;
	while (inc(*nptr, base) < blen)
		result = result * blen - inc(*nptr++, base);
	return (neg ? result : -result);
}
