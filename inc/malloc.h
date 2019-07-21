/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 21:40:22 by pleroux           #+#    #+#             */
/*   Updated: 2019/07/21 20:53:22 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H
# include <stdlib.h>

# define TINY_SIZE 		0
# define SMALL_SIZE		0
# define MIN_ALLOC		100
# define MUL_ALLOC		8

typedef enum		e_size {
	TINY = 0,
	SMALL,
}					t_e_size;

typedef struct		s_alloc {
	struct s_alloc	*next;
	size_t			length;
}					t_alloc;

typedef struct		s_page {
	struct s_page	*next;
	size_t			length;
	t_alloc			*alloc;
}					t_page;

typedef struct		s_mem {
	t_page			*tiny;
	t_page			*small;
	t_alloc			*large;
}					t_mem;

extern t_mem		*g_mem;

void		*ft_malloc(size_t size);
void		ft_free(void *ptr);

#endif
