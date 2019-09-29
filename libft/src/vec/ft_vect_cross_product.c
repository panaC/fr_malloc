/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vect_cross_product.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 09:23:36 by pierre            #+#    #+#             */
/*   Updated: 2018/01/03 18:39:57 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector.h>
#include <string.h>

t_vect				*ft_vect_cross_product(t_vect *a, t_vect *b)
{
	t_vect			*ret;

	if ((!(ret = ft_vect_new(0, 0, 0))))
		return (NULL);
	ret->x = a->y * b->z - a->z * b->y;
	ret->y = a->z * b->x - a->x * b->z;
	ret->z = a->x * b->y - a->y * b->x;
	ret->w = 1;
	return (ret);
}
