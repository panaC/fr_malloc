/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexlify.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 19:48:56 by pierre            #+#    #+#             */
/*   Updated: 2018/06/30 09:44:07 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static t_string		ft_itoa_base_byte(const t_uint32 nb, const t_string b)
{
	t_string		s;
	t_string		tmp;

	s = ft_itoa_base(nb, b);
	if (ft_strlen(s) == 1)
	{
		tmp = ft_strnew(2);
		tmp[0] = '0';
		tmp[1] = s[0];
		ft_strdel(&s);
		s = tmp;
	}
	return (s);
}

t_string			ft_hexlify(const t_string str, size_t nb)
{
	t_string		s = str;
	t_string		stmp;
	int				i;

	i = 0;
	s = ft_strnew(nb * 2 + 1);
	while (s && str && nb)
	{
		stmp = ft_itoa_base_byte(str[i], "0123456789abcdef");
		s = ft_strncat(s, stmp, 2);
		ft_strdel(&stmp);
		++i;
		--nb;
	}
	return (s);
}
