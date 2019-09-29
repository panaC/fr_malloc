/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unhexlify.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 18:44:58 by pierre            #+#    #+#             */
/*   Updated: 2018/06/27 19:45:06 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdio.h>

t_string		ft_unhexlify(const t_string c_str)
{
	t_string	s;
	t_string	str;
	char		byte[3];
	int			i;

	i = 0;
	byte[2] = 0;
	str = ft_strdup(c_str);
	str = ft_strtoupper(str);
	s = ft_strnew(ft_strlen(str) / 2 + 1);
	while (s && str && str[i] && str[i + 1])
	{
		byte[0] = str[i];
		byte[1] = str[i + 1];
		s[i / 2] = (char)ft_atoi_base((char*)&byte, "0123456789ABCDEF");
		i += 2;
	}
	if (s && str && str[i])
	{
		byte[0] = str[i];
		byte[1] = 0;
		s[i / 2] = (char)ft_atoi_base((char*)&byte, "0123456789ABCDEF");
	}
	ft_strdel(&str);
	return (s);
}
