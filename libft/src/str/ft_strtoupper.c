/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoupper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 19:25:03 by pierre            #+#    #+#             */
/*   Updated: 2018/06/27 19:39:51 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdio.h>

t_string			ft_strtoupper(t_string s)
{
	size_t			i;
	size_t			len;

	i = 0;
	len = ft_strlen(s);
	while (s && i < len)
	{
		s[i] = ft_toupper(s[i]);
		i++;
	}
	return (s);
}
