/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitrii <dmitrii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 19:45:05 by dmitrii           #+#    #+#             */
/*   Updated: 2024/10/07 21:37:28 by dmitrii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "stdarg.h"
# include "stddef.h"
# include "stdio.h"
# include "unistd.h"
# include <stdint.h>
# include <stdlib.h>

typedef struct s_flags
{
	int				minus_flag;
	int				zero_flag;
	int				min_width;
	char			sign;
	int				precision;
	int				hash_flag;
	struct s_list	*result;

}					t_flags;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int					ft_printf(const char *fmt, ...);
int					ft_numlen(int n);
int					ft_printf_format(char *fmt_ptr, va_list args, int *count);

void				ft_putnbr_fd(int n, int fd);
int					ft_isdigit(int c);
void				ft_putstr_fd(char *s, int fd);
size_t				ft_strlen(const char *str);
t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));
char				*ft_itoa(int n);
char				*ft_strdup(const char *s);
char				*ft_substr(char const *s, unsigned int start, size_t len);

#endif