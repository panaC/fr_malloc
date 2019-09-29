/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setparam_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 15:56:00 by pierre            #+#    #+#             */
/*   Updated: 2018/01/11 17:36:36 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <arg.h>

t_bool			ft_setparam_int(t_arg *a, t_string s, int *ptr, int data)
{
	t_string	param;

	if (!(a || s || ptr))
		return (FALSE);
	if (ft_search_param(a->long_param, &param, s))
	{
		param = ft_split_longparam(param, 1, TRUE);
		*ptr = ft_atoi(param);
		ft_memdel((void**)&param);
	}
	else
		*ptr = data;
	return (TRUE);
}
