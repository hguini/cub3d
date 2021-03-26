/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguini <hguini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 13:06:38 by max               #+#    #+#             */
/*   Updated: 2021/03/18 23:31:02 by hguini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int					get_next_line(int fd, char **line);
int					ft_atoi(char *str);
void				ft_bzero(void *src, size_t num);
void				*ft_calloc(size_t n, size_t size);
int					ft_isalnum(int sym);
int					ft_isalpha(int sym);
int					ft_isascii(int sym);
int					ft_isdigit(int sym);
int					ft_isprint(int sym);
void				*ft_memccpy(void *dest, const void *src, int s,
					size_t count);
void				*ft_memchr(const void *src, int s, size_t count);
int					ft_memcmp(const void *src1, const void *src2, size_t count);
void				*ft_memcpy(void *dest, const void *src, size_t count);
void				*ft_memmove(void *dest, const void *src, size_t count);
void				*ft_memset(void *src, int sym, size_t num);
char				*ft_strchr(const char *str, int sym);
char				*ft_strdup(const char *str);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
size_t				ft_strlcpy(char *dest, const char *src, size_t size);
size_t				ft_strlen(const char *str);
int					ft_strncmp(const char *str1, const char *str2, size_t len);
char				*ft_strnstr(const char *big, const char *small, size_t len);
char				*ft_strrchr(const char *str, int sym);
int					ft_tolower(int sym);
int					ft_toupper(int sym);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void*));
void				ft_lstclear(t_list **lst, void (*del)(void*));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)
					(void *));

#endif
