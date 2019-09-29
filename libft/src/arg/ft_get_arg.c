/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 15:30:27 by pierre            #+#    #+#             */
/*   Updated: 2018/01/16 15:52:48 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "arg.h"

static t_bool			is_present_short_param(t_string s, char c)
{
	size_t			i;

	if (!s)
		return (FALSE);
	i = 0;
	while (s[i] && s[i] != c)
		i++;
	if (i == ft_strlen(s))
		return (FALSE);
	return (TRUE);
}

static t_bool			get_short_param(t_arg *a, t_string s)
{
	int			i;

	i = 0;
	while (s[i])
	{
		if (ft_isalpha(s[i]) && !is_present_short_param(a->short_param, s[i]))
			a->short_param = ft_strccat(a->short_param, s[i]);
		else
			return (FALSE);
		i++;
	}
	return (TRUE);
}

static t_bool			get_long_param(t_arg *a, t_string s)
{
	if (!s || s[0] == '\0' || s[0] == '-')
		return (FALSE);
	ft_lstaddtoend(&(a->long_param), ft_lstnew((void*)s, ft_strlen(s) + 1));
	return (TRUE);
}

t_arg					*ft_get_arg(int ac, char **av)
{
	t_arg		*ret;
	t_bool		state;
	int			i;

	if ((!(ret = (t_arg*)ft_memalloc(sizeof(*ret)))))
		return (NULL);
	ret->short_param = NULL;
	ret->long_param = NULL;
	ret->data_param = NULL;
	i = 1;
	state = TRUE;
	while (i < ac)
	{
		if (state && ft_lstlen(ret->data_param) == 0 &&
				av[i][0] == '-' && av[i][1] && av[i][1] == '-')
			state = get_long_param(ret, av[i] + 2);
		else if (state && ft_lstlen(ret->data_param) == 0 && av[i][0] == '-')
			state = get_short_param(ret, av[i] + 1);
		else
			ft_lstaddtoend(&(ret->data_param),
					ft_lstnew((void*)av[i], ft_strlen(av[i]) + 1));
		++i;
	}
	ret->state = state;
	return (ret);
}
