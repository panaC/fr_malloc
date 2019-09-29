/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getarg_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 15:03:17 by pierre            #+#    #+#             */
/*   Updated: 2018/01/16 16:11:02 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <arg.h>
#include <stdlib.h>

t_string		ft_split_longparam(t_string n, int num, t_bool del)
{
	t_string	*s;
	t_string	ret;

	ret = NULL;
	if (!n)
		return (ret);
	s = ft_strsplit(n, '=');
	if (s && s[0] && num == 0)
		ret = ft_strdup(s[0]);
	else if (s && s[0] && s[1] && num == 1)
		ret = ft_strdup(s[1]);
	num = 0;
	while (s && s[num])
		ft_memdel((void**)&(s[num++]));
	free(s);
	if (del)
		free(n);
	return (ret);
}
