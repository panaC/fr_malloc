/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_shortparam.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 19:49:49 by pleroux           #+#    #+#             */
/*   Updated: 2018/01/09 20:02:16 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <arg.h>

t_bool			ft_check_shortparam(t_string param, char c)
{
	if (!param)
		return (FALSE);
	return (!(ft_strrchr(param, c) == NULL));
}
