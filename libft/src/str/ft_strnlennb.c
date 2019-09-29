/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlennb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 14:11:38 by pleroux           #+#    #+#             */
/*   Updated: 2018/05/01 14:20:04 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <libft.h>

int				ft_strnlennb(const char *nptr, size_t n)
{
	t_string	s;
	int			ret;

	s = ft_strsub(nptr, 0, n);
	ret = ft_strlennb(s);
	ft_memdel((void**)&s);
	return (ret);
}
