/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 20:03:28 by pleroux           #+#    #+#             */
/*   Updated: 2017/11/16 12:38:30 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void		ft_putnbr_fd(int n, int fd)
{
	unsigned int	nb;

	nb = (unsigned int)n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		nb *= -1;
	}
	if (nb > 9)
		ft_putnbr_fd((nb / 10), fd);
	ft_putchar_fd(((nb % 10) + '0'), fd);
}
