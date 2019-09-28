/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 21:40:22 by pleroux           #+#    #+#             */
/*   Updated: 2019/09/29 00:10:50 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H
# include <stdlib.h>
# include <pthread.h>

/*
** https://cocoawithlove.com/2010/05/look-at-how-malloc-works-on-mac.html
*/

# define MIN_ALLOC						100
# define MUL_ALLOC						32
# define FALSE							0
# define TRUE							1
# define FREE_ERROR						7777

typedef enum							e_size {
	TINY = 0,
	SMALL,
	LARGE
}										t_e_size;

typedef struct							s_alloc {
	struct s_alloc						*next;
	size_t								length;
}										t_alloc;

typedef struct							s_zone {
	struct s_zone						*next;
	size_t								length;
}										t_zone;

typedef struct							s_mem {
	t_zone								*tiny;
	t_zone								*small;
	t_zone								*large;
}										t_mem;

# define SZ								sizeof(t_zone)
# define SA								sizeof(t_alloc)

extern t_mem							g_mem;
extern pthread_mutex_t					g_mutex;

void									*malloc(size_t size);
void									free(void *ptr);
void									*realloc(void *ptr, size_t size);
void									show_alloc_mem();

#endif
