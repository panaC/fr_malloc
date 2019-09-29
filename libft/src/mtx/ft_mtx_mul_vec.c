/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtx_mul_vec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 09:41:36 by pierre            #+#    #+#             */
/*   Updated: 2017/12/20 09:42:06 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <matrix.h>

t_vect			*ft_mtx_mul_vec(t_vect *v, t_matrix *m)
{
	v->x = v->x * m->xx + v->y * m->yx + v->z * m->zx + m->tx;
	v->y = v->x * m->xy + v->y * m->yy + v->z * m->zy + m->ty;
	v->z = v->x * m->xz + v->y * m->yz + v->z * m->zz + m->tz;
	v->w = v->x * m->wx + v->y * m->wy + v->z * m->wz + m->ww;
	if (v->w != 1 && v->w != 0)
	{
		v->x /= v->w;
		v->y /= v->w;
		v->z /= v->w;
	}
	return (v);
}
