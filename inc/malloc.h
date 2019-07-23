/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 21:40:22 by pleroux           #+#    #+#             */
/*   Updated: 2019/07/23 20:49:44 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H
# include <stdlib.h>

# define TINY_SIZE 		0
# define SMALL_SIZE		0
# define MIN_ALLOC		100
# define MUL_ALLOC		8
# define FALSE			0
# define TRUE			1

typedef enum		e_size {
	TINY = 0,
	SMALL,
}					t_e_size;

typedef struct		s_alloc {
	struct s_alloc	*next;
	size_t			length;
	void			*zone;
	t_e_size		e_size;
}					t_alloc;

typedef struct		s_zone {
	struct s_zone	*next;
	size_t			length;
	t_alloc			*alloc;
}					t_zone;

typedef struct		s_mem {
	t_zone			*tiny;
	t_zone			*small;
	t_alloc			*large;
}					t_mem;

extern t_mem		*g_mem;

void				*ft_malloc(size_t size);
void				ft_free(void *ptr);
void				*ft_realloc(void *ptr, size_t size);

void				*malloc_tiny_small(size_t size, \
						t_zone **zone, t_e_size enum_size);

t_alloc				*get_set_alloc_zone(t_zone *zone, \
						size_t length, t_e_size e);
t_zone				*new_zone(t_e_size enum_size);

t_zone				*push_back_zone(t_zone **list, t_zone *elem);
t_alloc				*push_back_alloc(t_alloc **list, t_alloc *elem);

#endif
