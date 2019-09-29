/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 15:51:36 by pleroux           #+#    #+#             */
/*   Updated: 2017/11/13 16:02:04 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "../../includes/libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*ret;

	if (!s)
		return (NULL);
	ret = ft_strnew(len);
	if (!ret)
		return (NULL);
	ret = ft_strncpy(ret, s + start, len);
	return (ret);
}
