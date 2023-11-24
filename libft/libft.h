/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marirodr <marirodr@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 10:33:34 by marirodr          #+#    #+#             */
/*   Updated: 2023/11/14 11:40:11 by marirodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdarg.h>
# include <fcntl.h>
//# include "../memory-leaks-master/include/memory_leaks.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

//strings
size_t				ft_strlen(const char *str);
size_t				ft_strlcpy(char *dest, const char *src, size_t destsize);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
int					ft_strcmp(char *s1, char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strnstr(const char *h, const char *n, size_t len);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strdup(const char *s1);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strjoin_sl(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
void				ft_striteri(char *s, void (*f)(unsigned int, char*));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_putstr(char *str);
char				*ft_strcpy(char *dest, char *src);
char				*ft_strrev(char *str);
void				sort_int_tab(int *tab, unsigned int size);

//memory
void				ft_bzero(void *s, size_t n);
void				*ft_memset(void *s, int c, size_t len);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_calloc(size_t count, size_t size);
void				ft_swap(int *a, int *b);

//file descriptors
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);

//conversors
int					ft_atoi(const char *str);
long int			ft_atol(char *str);
char				*ft_itoa(int n);
void				ft_put_lower_hex(int nbr);
void				ft_putnbr(int nb);
int					ft_abs(int nbr);

//chars
void				ft_putchar(char c);
int					ft_isalpha(int i);
int					ft_isdigit(int i);
int					ft_isalnum(int i);
int					ft_isascii(int i);
int					ft_isprint(int i);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_isalnum_plus(int i);
int					ft_isalpha_plus(int i);

//lists
typedef struct s_list
{
	void			*data;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lmap(t_list *l, void *(*f)(void *), void (*d)(void *));
void				ft_list_foreach(t_list *begin_list, void (*f)(void *));
void				ft_list_remove_if(t_list **begin, void *d_r, int (*cmp)());
void				ft_free_double_pointer(char **ptr);

//bits
void				print_bits(unsigned char octet);
unsigned char		reverse_bits(unsigned char octet);
unsigned char		swap_bits(unsigned char octet);

//printf

int					ft_printf(const char *format, ...);
void				ft_printchar(char c, int *count);
void				ft_printstr(char *str, int *count);
void				ft_printnbr(int nb, int *count);
void				ft_printunsigned(unsigned int nb, int *count);
void				ft_printhex(unsigned long h, int *count, char x);
void				ft_printpointer(void *ptr, int *count);

//get_next_line

char				*get_next_line(int fd);
int					ft_strlen_gnl(char *s);
char				*ft_strchr_gnl(char *s, int c);
void				*ft_calloc_gnl(size_t count, size_t size);
char				*ft_strjoin_gnl(char *s1, char *s2);

//minishell
int					ft_is_equal(char c);
int					ft_aux_write(int q, char *s, int *i);
int					mini_count_word(char const *s, char c);
char				**ft_mini_split(char const *s, char c);

//old_split
int					o_count_word(char const *s, char c);
char				**ft_old_split(char const *s, char c);

#endif
