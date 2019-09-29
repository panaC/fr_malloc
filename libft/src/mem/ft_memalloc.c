/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 11:56:10 by pleroux           #+#    #+#             */
/*   Updated: 2018/01/15 16:25:23 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "../../includes/libft.h"

void		*ft_memalloc(size_t size)
{
	unsigned char		*ret;

	if (size > 2147483648)
		return (NULL);
	ret = (unsigned char*)malloc(size);
	if (!ret)
		return (NULL);
	ft_bzero(ret, size);
	return (ret);
}
