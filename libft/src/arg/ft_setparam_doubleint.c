/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setparam_doubleint.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 16:06:03 by pierre            #+#    #+#             */
/*   Updated: 2018/01/16 16:17:46 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <arg.h>
#include <stdlib.h>

t_bool			ft_setparam_doubleint(t_arg *a, t_string s, int *ptr, int data)
{
	t_string	*ss;
	t_string	str;
	static int	i = 0;
	int			j;

	j = 0;
	ss = NULL;
	if (!(a || s || ptr))
		return (FALSE);
	*ptr = data;
	if (ft_search_param(a->long_param, &str, s))
	{
		str = ft_split_longparam(str, 1, TRUE);
		ss = ft_strsplit(str, ',');
		ft_memdel((void**)&str);
		if (ss && ss[0] && ss[1])
			*ptr = (ft_atoi(ss[i % 2]) < 3000) ? ft_atoi(ss[i % 2]) : data;
		while (ss && ss[j])
			ft_memdel((void**)&ss[j++]);
		if (ss)
			free(ss);
		i = (!i) & 0x1;
	}
	return (TRUE);
}
