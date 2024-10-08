/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitrii <dmitrii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 19:45:05 by dmitrii           #+#    #+#             */
/*   Updated: 2024/10/08 16:33:06 by dmitrii          ###   ########.fr       */
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
	char			*sign;
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
void				ft_putlstchar(void *c);
int					ft_align(char c, int min_width);
int					ft_extract_num(char **fmt_ptr, int *shift);
void				init_flags(t_flags *flags);
void				print_flags(t_flags *flags);
int					ft_isflag(char c);
int					ft_process_precision(char **fmt_ptr, int *zero_flag,
						int *shift);
void				ft_process_flags(char **fmt_ptr, t_flags *flags,
						int *shift);
int					ft_recalculate_flagnum(int flagnum, const int num_len);
int					ft_process_decimal_type(va_list args, t_flags *flags);
int					ft_add_strtolst(t_list **lst, char *s,
						void (*add_func)(t_list **, t_list *));
int					ft_print_type_with_align(t_flags *flags);
int					ft_process_string_type(va_list args, t_flags *flags);
int					ft_process_hex_type(va_list args, t_flags *flags,
						const int is_upper);
int					ft_add_signtolst(t_list **lst, char *sign);
int					ft_add_zerostolst(t_list **lst, int flagnum, char *sign);

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