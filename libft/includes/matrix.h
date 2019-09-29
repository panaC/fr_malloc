/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 14:41:51 by pierre            #+#    #+#             */
/*   Updated: 2018/01/03 18:29:18 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _MATRIX_H
# define _MATRIX_H

# include <vector.h>

/*
** | xx xy xz wx |
** | yx yy yz wy |
** | zx zy zz wz |
** | tx ty tz ww |
*/

typedef struct				s_matrix
{
	double					xx;
	double					xy;
	double					xz;
	double					yx;
	double					yy;
	double					yz;
	double					zx;
	double					zy;
	double					zz;
	double					tx;
	double					ty;
	double					tz;
	double					wx;
	double					wy;
	double					wz;
	double					ww;
}							t_matrix;

t_matrix					*ft_mtx_new();
t_matrix					*ft_mtx_identity(t_matrix *m);
t_vect						*ft_mtx_mul_vec(t_vect *v, t_matrix *m);

#endif
