/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 15:37:07 by pierre            #+#    #+#             */
/*   Updated: 2018/01/09 19:59:07 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _ARG_H
# define _ARG_H

# include <libft.h>

typedef struct	s_arg
{
	t_string	short_param;
	t_list		*long_param;
	t_list		*data_param;
	t_bool		state;
}				t_arg;

t_arg			*ft_get_arg(int ac, char **argv);
t_string		ft_split_longparam(t_string n, int num, t_bool del);
t_bool			ft_setparam_int(t_arg *a, t_string s, int *ptr, int data);
t_bool			ft_setparam_doubleint(t_arg *a, t_string s, int *ptr, int data);
t_bool			ft_setparam_hex(t_arg *a, t_string s, t_uint32 *ptr,
		t_uint32 data);
void			ft_freearg(t_arg **a);
t_bool			ft_check_longparam(t_list *src, t_list *arg, t_bool del);
t_bool			ft_search_param(t_list *l, t_string *r, t_string s);
t_bool			ft_check_shortparam(t_string param, char c);
#endif
