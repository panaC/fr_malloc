/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 11:17:52 by pleroux           #+#    #+#             */
/*   Updated: 2018/06/27 18:58:02 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_uint32			ft_atoi_hex(const char *str)
{
	t_uint32		res;
	size_t			i;
	t_string		s;

	if (!str)
		return (0);
	i = 0;
	s = ft_strdup(str);
	while (i < ft_strlen(s))
	{
		s[i] = ft_toupper(s[i]);
		i++;
	}
	i = 0;
	while (ft_isspace(s[i]))
		i++;
	if (s[i] == '0' && s[i + 1] && s[i + 1] == 'X' && s[i + 2]
			&& !ft_isspace(s[i + 2]))
		i += 2;
	else
		return (0);
	res = (t_uint32)ft_atoi_base(s + i, "0123456789ABCDEF");
	ft_memdel((void**)&s);
	return (res);
}
