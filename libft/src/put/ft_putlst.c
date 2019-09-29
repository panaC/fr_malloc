/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 18:23:27 by pleroux           #+#    #+#             */
/*   Updated: 2017/11/16 12:26:28 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>
#include "../../includes/libft.h"

void		ft_putlst(t_list *l)
{
	size_t		t;
	size_t		i;

	while (l)
	{
		i = 0;
		t = l->content_size;
		while (i < t)
		{
			write(1, l->content + i, 1);
			i++;
		}
		ft_putchar('\n');
		l = l->next;
	}
}
