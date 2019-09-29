/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_vect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 09:25:00 by pierre            #+#    #+#             */
/*   Updated: 2017/12/20 09:33:07 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector.h>
#include <libft.h>

void				ft_print_vect(t_vect *v)
{
	ft_putstr("x=");
	ft_putnbr(v->x);
	ft_putstr("y=");
	ft_putnbr(v->y);
	ft_putstr("z=");
	ft_putnbr(v->z);
	ft_putstr("\n");
}
