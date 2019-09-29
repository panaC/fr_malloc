/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 17:39:17 by pleroux           #+#    #+#             */
/*   Updated: 2017/11/15 17:44:07 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "../../includes/libft.h"

size_t		ft_lstlen(t_list *l)
{
	size_t		count;

	count = 0;
	while (l)
	{
		count++;
		l = l->next;
	}
	return (count);
}
