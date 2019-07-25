/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 18:53:52 by pleroux           #+#    #+#             */
/*   Updated: 2019/07/25 13:59:43 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "malloc.h"

t_alloc			*push_back_alloc(t_alloc *list, t_alloc *elem)
{
	t_alloc		*ret;

	ret = list;
	while (ret->next) {
		ret = ret->next;
	}
	ret->next = elem;
	return (ret);
}

t_zone			*push_back_zone(t_zone **list, t_zone *elem)
{
	t_zone		*ret;

	if (*list == NULL) {
		*list = elem;
		return;
	}
	ret = *list;
	while (ret->next) {
		ret = ret->next;
	}
	ret->next = elem;
	return (ret);
}
