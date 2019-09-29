/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strccat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 16:17:32 by pierre            #+#    #+#             */
/*   Updated: 2017/12/18 18:13:36 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

t_string			ft_strccat(t_string s, char c)
{
	t_string		ptr;
	size_t			size;

	size = ft_strlen(s);
	if ((!(ptr = ft_memalloc(size + 2))))
		return (NULL);
	ptr = ft_strncpy(ptr, s, size);
	ptr[size] = c;
	ptr[size + 1] = '\0';
	ft_memdel((void**)&s);
	s = ptr;
	return (s);
}
