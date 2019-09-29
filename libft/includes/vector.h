/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 14:41:51 by pierre            #+#    #+#             */
/*   Updated: 2018/01/03 18:30:18 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _VECTOR_H
# define _VECTOR_H

typedef struct		s_vect
{
	int				x;
	int				y;
	int				z;
	int				w;
}					t_vect;

t_vect				*ft_vect_init(t_vect *v, int x, int y, int z);
t_vect				*ft_vect_new(int x, int y, int z);
void				ft_vect_copy(t_vect *dest, t_vect *src);
double				ft_vect_norm(const t_vect *v);
t_vect				*ft_vect_unit(t_vect *v);
int					ft_vect_scalar_product(t_vect *v1, t_vect *v2);
t_vect				*ft_vect_cross_product(t_vect *a, t_vect *b);
void				ft_print_vect(t_vect *v);

#endif
