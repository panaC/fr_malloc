/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lststrfind.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 14:56:00 by pierre            #+#    #+#             */
/*   Updated: 2018/01/09 16:40:45 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_bool		ft_lststrfind(t_list *l, char **r, t_string s)
{
	if (!l || !s || !l->content)
		return (FALSE);
	while (l)
	{
		if (ft_strcmp((t_string)l->content, s) == 0)
		{
			if (r)
				*r = ft_strdup((t_string)l->content);
			return (TRUE);
		}
		l = l->next;
	}
	return (FALSE);
}
