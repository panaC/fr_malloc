/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 18:53:52 by pleroux           #+#    #+#             */
/*   Updated: 2019/07/21 19:02:17 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "malloc.h"

void		push_back(t_alloc **list, t_alloc *elem)
{
	t_alloc		*ret;

	if (*list == NULL) {
		*list = elem;
		return;
	}
	ret = *list;
	while (ret->next) {
		ret = ret->next;
	}
	ret->next = elem;
}
