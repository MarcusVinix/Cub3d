/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 20:54:41 by mavinici          #+#    #+#             */
/*   Updated: 2021/09/18 20:54:41 by mavinici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H

//default library
# include	<stdlib.h>
# include	<unistd.h>
# include	<limits.h>
# define OPEN_MAX 256
# define BUFFER_SIZE 10

// GNL STRUCT
typedef struct s_gnl
{
	ssize_t			size;
	char			*buffer;
	char			*tmp;
}	t_var;

//signal 1 = visto em variaveis de ambiente
//signal 0 = não visto em variavel de ambiente
typedef struct s_list
{
	char			*key;
	char			*value;
	int				signal;
	struct s_list	*next;
}					t_list;

//gnl functions
int		get_next_line(int fd, char **line);
char	*ft_line(char *s, size_t len);
//mandatory functions
int		ft_isalpha(char c);
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memccpy(void *dest, const void *src, int c, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strnstr(const char *s, const char *find, size_t slen);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_atoi(const char *nptr);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup(const char *s);
//mandatory functions part2
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
//bonus functions
t_list	*ft_lstnew(void *key, void *value, int sig);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(char *, char*, int fd, int sig),
			int fd);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
//new functions
void	ft_swap(int *a, int *b);
void	ft_putnbr_base_fd(unsigned int num, char *base, int fd);
char	*ft_itoa_base(int n, char *base, int len_base);
int		ft_strcmp(const char *s1, const char *s2);
int		is_all_space(char *str);
int		is_all_space2(char *str, char c);
int		ft_strlen_split(char **split);
char	*ft_strdup2(const char *s);
int		find_index(char *str, char c);
char	*ft_split_rev(char **split);
void	concatenate_join(char **aux, char *str);
char	*ft_free_split(char **str);
char	*ft_set_free_and_null(char **str);
char	*ft_free_triple(char ***str);
void	ft_free_ptr(void **ptr);

#endif
