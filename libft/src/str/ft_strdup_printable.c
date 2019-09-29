/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 20:45:25 by pierre            #+#    #+#             */
/*   Updated: 2018/06/29 18:21:46 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdio.h>

static int			nb_prt(const t_string str)
{
	int				nb_prt;
	size_t			i;

	i = 0;
	nb_prt = 0;
	while (i < ft_strlen(str))
	{
		if (ft_isprint(str[i]))
			++nb_prt;
		++i;
	}
	return (nb_prt);
}


t_string			ft_strdup_printable(const t_string str)
{
	t_string		s;
	size_t			i;
	size_t			j;

	if (!str)
		return (NULL);
	s = ft_strnew((ft_strlen(str) - nb_prt(str)) * 4 + nb_prt(str) + 1);
	j = 0;
	i = 0;
	while (str[i])
	{
		if (ft_isprint(str[i]))
			s[j++] = str[i];
		else
		{
			s[j++] = '\\';
			s[j++] = 'x';
			j += ft_strlcat(s + j, ft_itoa_base((t_uint32)((t_uint8)str[i]),
						"0123456789abcdef"), 3);
		}
		++i;
	}
	return (s);
}
