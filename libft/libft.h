/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 11:36:59 by gdelabro          #+#    #+#             */
/*   Updated: 2017/05/21 18:06:30 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# define BUFF_SIZE 500

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_fl
{
	int				ret;
	char			buf[BUFF_SIZE + 1];
}					t_fl;

typedef struct		s_content
{
	char			*str;
	int				fd;
}					t_content;

typedef struct		s_str
{
	char			*p_str;
	char			*new_str;
	char			*ret_str;
	char			*fin_str;
	size_t			len;
}					t_str;

int					get_next_line(const int fd, char **line);
int					taille_tab(char **tab);
void				ft_bzero(void *s, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memcpy(void *dest, const void *src, size_t n);
char				**ft_split_space(char const *s);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
int					ft_strlen_2(char *s, int i);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
void				aff_bin(char *tab);
int					ft_atoi(const char *str);
char				**add_str(char **tab, char *str);
int					ft_isalpha(int c);
void				add_char(char *str, char c);
int					ft_isdigit(int c);
int					ft_taille_nb(long int nb, int base);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				free_ancien(char **tab);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncpy(char *dest, const char *src, size_t len);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *big, const char *little);
char				*ft_strnstr(const char *big, const char *litl, size_t len);
char				*ft_strcat_2(char *s1, const char *s2, int *t);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
int					ft_taille_size_t(size_t nb, int base);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
int					*ft_strsplit_nbr(char const *s, char c);
char				**ft_strsplit2(char const *s, char c);
char				*ft_itoa(int n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putlong(long long n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_swap_char(char *a, char *b);
char				*ft_strccpy(const char *s, int c);
void				ft_swap_str(char **s1, char **s2);
void				ft_swap_int(int *a, int *b);
int					ft_strlen_fd(int fd);
char				**rem_str(char **tab, int r);
int					ft_cpyfile(int fd, char **file2);
char				**cpy_tab(char **tab);
void				ft_putstrw(wchar_t *s);
int					ft_strlenw(wchar_t *s);
char				*ft_strcpyend(char *str, char c);

#endif
