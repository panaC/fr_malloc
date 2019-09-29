/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 09:43:00 by pierre            #+#    #+#             */
/*   Updated: 2017/12/04 15:13:14 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"
#include "libft.h"

static void			*ft_memcatnew(void **s1, size_t n1, void *s2, size_t n2)
{
	unsigned char	*ret;

	if (!(n1 + n2))
		return (NULL);
	if ((!(ret = ft_memalloc(n1 + n2))))
		return (NULL);
	ft_memcpy(ret, *s1, n1);
	ft_memcpy(ret + n1, s2, n2);
	ft_bzero(s2, BUFF_SIZE);
	ft_memdel(s1);
	return (ret);
}

static t_lst_fd		*lst_search_fd(t_list **l, const int fd)
{
	t_lst_fd	tmp;
	t_list		*lst;

	lst = *l;
	while (lst)
	{
		if (((t_lst_fd*)lst->content)->fd == fd)
			return ((t_lst_fd*)lst->content);
		lst = lst->next;
	}
	tmp.fd = fd;
	ft_bzero(tmp.buf, BUFF_SIZE);
	tmp.index = 0;
	tmp.size_buf = 0;
	tmp.mem_buf = NULL;
	tmp.size_mem_buf = 0;
	ft_lstadd(l, ft_lstnew(&tmp, sizeof(tmp)));
	return (((t_lst_fd*)((*l)->content)));
}

static int			close_fd(t_list **lst, const int fd, int ret)
{
	t_list		*pl;
	t_list		*l;

	pl = NULL;
	l = *lst;
	while (l)
	{
		if (((t_lst_fd*)l->content)->fd == fd)
		{
			if (pl)
				pl->next = l->next;
			else
				*lst = l->next;
			ft_memdel((void**)&(((t_lst_fd*)l->content)->mem_buf));
			ft_memdel(&(l->content));
			ft_memdel((void**)&l);
			return (ret);
		}
		pl = l;
		l = l->next;
	}
	return (ret);
}

static int			setline(t_lst_fd *l, t_ucp ptr_find, char **line, int ret)
{
	unsigned char	*tmp;
	unsigned long	delta;

	delta = ptr_find - l->mem_buf;
	if (ret < 0)
		return (ret);
	else if (ret)
		*line = (char*)ft_memdup((t_ucp)(l->mem_buf), delta + 1);
	else
	{
		tmp = (t_ucp)ft_memalloc(delta);
		*line = ft_memcpy(tmp, (t_ucp)(l->mem_buf), delta);
	}
	(*line)[delta] = '\0';
	l->size_mem_buf = l->mem_buf + l->size_mem_buf - ptr_find - 1;
	tmp = NULL;
	if (l->size_mem_buf)
		tmp = ft_memdup(ptr_find + 1, l->size_mem_buf);
	else
		l->size_mem_buf = 0;
	ft_memdel((void**)&l->mem_buf);
	l->mem_buf = tmp;
	return ((delta ? 1 : ret));
}

int					get_next_line(const int fd, char **line)
{
	static t_list			*lst = NULL;
	t_lst_fd				*l;
	unsigned char			*ptr;

	l = lst_search_fd(&lst, fd);
	while (1)
	{
		if ((ptr = (t_ucp)ft_memchr((t_ucp)l->mem_buf, CHAR, l->size_mem_buf)))
			return (setline(l, ptr, line, 1));
		else
		{
			l->size_buf = read(l->fd, l->buf, BUFF_SIZE);
			l->mem_buf = ft_memcatnew((void**)&(l->mem_buf), l->size_mem_buf,
					l->buf, l->size_buf);
			l->size_mem_buf += l->size_buf;
			if (l->size_buf < 1)
				return (close_fd(&lst, fd,
							setline(l, (t_ucp)(l->mem_buf + l->size_mem_buf),
								line, l->size_buf)));
		}
	}
}
