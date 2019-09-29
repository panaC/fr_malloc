/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 15:56:17 by pleroux           #+#    #+#             */
/*   Updated: 2017/11/16 12:31:41 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char		*ret;

	if (!s1 || !s2)
		return (NULL);
	ret = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (!ret)
		return (NULL);
	ft_strcat(ret, s1);
	ft_strcat(ret, s2);
	return (ret);
}
