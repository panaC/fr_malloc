/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 17:41:00 by pleroux           #+#    #+#             */
/*   Updated: 2018/05/02 18:30:03 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void		*ft_lstfind(t_list *lst, void *data,
		void *(*f)(void *data_elem, void *data_comp))
{
	t_list	*t;
	void	*r;

	t = lst;
	while (t)
	{
		if ((r = f(t->content, data)))
			return (r);
		t = t->next;
	}
	return (NULL);
}
