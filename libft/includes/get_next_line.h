/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 09:30:15 by pierre            #+#    #+#             */
/*   Updated: 2017/12/01 21:07:23 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __GET_NEXT_LINE_H
# define __GET_NEXT_LINE_H
# define BUFF_SIZE		4096
# define CHAR			10

typedef unsigned char*	t_ucp;

typedef struct			s_lst_fd
{
	int					fd;
	unsigned char		buf[BUFF_SIZE];
	int					index;
	int					size_buf;
	unsigned char		*mem_buf;
	int					size_mem_buf;
}						t_lst_fd;

int						get_next_line(const int fd, char **line);

#endif
