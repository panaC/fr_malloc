/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 11:46:01 by pleroux           #+#    #+#             */
/*   Updated: 2018/03/15 14:10:32 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

size_t		ft_intlen_base(unsigned int n, int base)
{
	size_t			i;

	i = 1;
	while (n /= base)
		i++;
	return (i);
}

char		*ft_itoa_base(unsigned int value, char *basestr)
{
	size_t			size;
	size_t			i;
	size_t			base;
	char			*tmp;

	if (value == 0)
		return (ft_strdup("0"));
	base = ft_strlen(basestr);
	size = ft_intlen_base(value, base);
	if (!(tmp = (char*)ft_memalloc(sizeof(char) * size + 1)))
		return (NULL);
	tmp[size] = '\0';
	if (!value)
		tmp[0] = '0';
	i = size - 1;
	while (value)
	{
		tmp[i] = basestr[value % base];
		value = value / base;
		i--;
	}
	return (tmp);
}
