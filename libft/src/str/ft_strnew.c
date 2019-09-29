/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 12:12:24 by pleroux           #+#    #+#             */
/*   Updated: 2017/11/15 13:10:08 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "../../includes/libft.h"

char		*ft_strnew(size_t size)
{
	char		*ret;

	ret = (char*)ft_memalloc(size + 1);
	if (!ret)
		return (NULL);
	return (ret);
}
