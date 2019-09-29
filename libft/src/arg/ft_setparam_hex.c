/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setparam_hex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 17:10:59 by pierre            #+#    #+#             */
/*   Updated: 2018/01/11 17:38:53 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <arg.h>

t_bool		ft_setparam_hex(t_arg *a, t_string s, t_uint32 *ptr, t_uint32 data)
{
	t_string	str;

	if (!(a || s))
		return (FALSE);
	if (ft_search_param(a->long_param, &str, s))
	{
		str = ft_split_longparam(str, 1, TRUE);
		if (!str)
		{
			*ptr = data;
		}
		else
			*ptr = ft_atoi_hex(str);
		ft_memdel((void**)&str);
	}
	else
		*ptr = data;
	return (TRUE);
}
