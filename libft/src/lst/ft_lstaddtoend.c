/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddtoend.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 20:02:53 by pleroux           #+#    #+#             */
/*   Updated: 2017/11/16 12:18:55 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void		ft_lstaddtoend(t_list **alst, t_list *new)
{
	t_list		*t;

	if (alst && *alst && new)
	{
		t = *alst;
		while (t->next)
			t = t->next;
		t->next = new;
		t->next->next = NULL;
	}
	if (!(*alst))
	{
		*alst = new;
		(*alst)->next = NULL;
	}
}
