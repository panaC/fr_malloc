/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 11:31:28 by pleroux           #+#    #+#             */
/*   Updated: 2018/03/15 13:46:47 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char		*ft_strnjoin(char const *s1, size_t n1, char const *s2, size_t n2)
{
	char		*ret;

	if (!s1 || !s2)
		return (NULL);
	ret = ft_strnew(n1 + n2 + 1);
	if (!ret)
		return (NULL);
	ft_memcpy(ret, s1, n1);
	ft_memcpy(ret + n1, s2, n2);
	ret[n1 + n2] = '\0';
	return (ret);
}
