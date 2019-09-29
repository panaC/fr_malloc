/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_param.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 16:52:22 by pleroux           #+#    #+#             */
/*   Updated: 2018/01/16 16:10:38 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <arg.h>

t_bool			ft_search_param(t_list *l, t_string *r, t_string s)
{
	t_string	tmp;

	tmp = NULL;
	if (!(l || s || l->content))
	{
		return (FALSE);
	}
	while (l)
	{
		tmp = ft_split_longparam((t_string)l->content, 0, FALSE);
		if (ft_strcmp(tmp, s) == 0)
		{
			if (r)
				*r = ft_strdup((t_string)l->content);
			ft_memdel((void**)&tmp);
			return (TRUE);
		}
		ft_memdel((void**)&tmp);
		l = l->next;
	}
	return (FALSE);
}
