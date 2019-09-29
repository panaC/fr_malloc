/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base64_encode.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 13:19:46 by pleroux           #+#    #+#             */
/*   Updated: 2018/06/30 20:23:16 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_string		ft_base64_encode(const t_string encod)
{
	const char	b64[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ" \
						 "abcdefghijklmnopqrstuvwxyz0123456789+/";
	t_string	s;
	size_t		i;
	size_t		j;
	int			len;

	i = 0;
	j = 0;
	len = (int)ft_strlen(encod);
	s = ft_strnew((len / 3 * 4) + 5);
	while (s && len > 0)
	{
		s[i] = b64[(unsigned char)(encod[j] >> 2) & 0x3f];
		s[i + 1] = b64[(unsigned char)((encod[j] & 0x03) << 4 |
				(len > 1 ? (encod[j + 1] >> 4) : 0)) & 0x3f];
		s[i + 2] = (len > 1 ? b64[(unsigned char)(((encod[j + 1] & 0x0f) << 2) |
					(len > 2 ? (encod[j + 2] >> 6) : 0))  & 0x3f] : '=');
		s[i + 3] = (len > 2 ? b64[(unsigned char)(encod[j + 2] & 0x3f)] : '=');
		i += 4;
		j += 3;
		len -= 3;
	}
	return (s);
}
