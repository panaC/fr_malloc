/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtx_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 09:43:50 by pierre            #+#    #+#             */
/*   Updated: 2018/01/03 18:29:13 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <string.h>
#include <matrix.h>

t_matrix			*ft_mtx_new(void)
{
	t_matrix		*ret;

	if ((!(ret = (t_matrix*)ft_memalloc(sizeof(*ret)))))
		return (NULL);
	return (ft_mtx_identity(ret));
}
