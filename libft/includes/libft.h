/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 10:12:55 by pleroux           #+#    #+#             */
/*   Updated: 2018/06/30 20:16:37 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>

# define TRUE		1
# define FALSE		0

typedef unsigned int	t_bool;
typedef unsigned char	t_uint8;
typedef unsigned short	t_uint16;
typedef unsigned int	t_uint32;
typedef unsigned long	t_uint64;
typedef char*			t_string;

typedef union			u_uint
{
	char				v8;
	short				v16;
	int					v32;
	long int			v64;
	char				v[8];
}						t_int;

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

void				*ft_memset (void *s, int c, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memmove(void *d, const void *s, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *src);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncpy(char *dest, const char *src, size_t n);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strncat(char *dest, const char *src, size_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strnstr(const char *hay, const char *need, size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *nptr);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_islower(int c);
int					ft_isupper(int c);
int					ft_isprint(int c);
int					ft_isnum(int c);
char				*ft_strnew(size_t size);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
void				ft_strclr(char *s);
void				ft_strdel(char **as);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strnjoin(char const *s1, size_t n1,
								char const *s2, size_t n2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_itoa_long(long long int n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstaddstr(t_list **alst, t_string s);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_bool				ft_lststrfind(t_list *l, char **r, t_string s);
void				*ft_lstfind(t_list *lst, void *data,
						void *(*f)(void *data_elem, void *data_comp));
void				ft_lstdelfind(t_list **lst, void *data,
		void *(*f)(void *data_elem, void *data_comp),
		void (*del)(void*, size_t));
void				ft_lstcpy(t_list *src, t_list **dest);
void				ft_putlst(t_list *l);
void				*ft_lstpull(t_list **alst);
void				*ft_memdup(const void *mem, size_t size);
int					ft_isspace(int c);
void				ft_lstaddtoend(t_list **alst, t_list *new);
size_t				ft_lstlen(t_list *l);
int					ft_atoi_base(const char *nptr, const char *base);
t_uint32			ft_atoi_hex(const char *str);
char				*ft_itoa_base(unsigned int value, char *basestr);
char				*ft_itoa_base_long(unsigned long long int value,
						char *basestr);
void				ft_print_memory(const void *addr, size_t size);
int					ft_nb_split(char const *s, char c);
t_string			ft_strccat(t_string s, char c);
int					ft_abs(int n);
int					ft_len(int n);
int					ft_strlennb(const char *nptr);
int					ft_strnlennb(const char *nptr, size_t n);
t_bool				ft_striterv(char *s, int(*f)(int));
t_bool				ft_strniterv(char *s, size_t n, int (*f)(int));
t_uint32			ft_strnbchr(t_string s, int c);
t_uint32			ft_strnnbchr(t_string s, size_t size, int c);
t_string			ft_strtoupper(t_string s);
t_string			ft_strdup_printable(const t_string str);

/*
** secu directory
*/
t_string			ft_unhexlify(t_string str);
t_string			ft_hexlify(const t_string str, size_t nb);
t_string			ft_base64_encode(const t_string encod);

#endif
