NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
	ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
	ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c \
	ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strnstr.c \
	ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c ft_strncmp.c

BONUS_SRC = ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c \
	ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c

OBJ = ft_atoi.o ft_bzero.o ft_calloc.o ft_isalnum.o ft_isalpha.o ft_isascii.o \
	ft_isdigit.o ft_isprint.o ft_itoa.o ft_memchr.o ft_memcmp.o ft_memcpy.o \
	ft_memmove.o ft_memset.o ft_putchar_fd.o ft_putendl_fd.o ft_putnbr_fd.o \
	ft_putstr_fd.o ft_split.o ft_strchr.o ft_strdup.o ft_striteri.o \
	ft_strjoin.o ft_strlcat.o ft_strlcpy.o ft_strlen.o ft_strmapi.o ft_strnstr.o \
	ft_strrchr.o ft_strtrim.o ft_substr.o ft_tolower.o ft_toupper.o ft_strncmp.o

BONUS_OBJ = ft_lstadd_back.o ft_lstadd_front.o ft_lstclear.o ft_lstdelone.o \
	ft_lstiter.o ft_lstlast.o ft_lstmap.o ft_lstnew.o ft_lstsize.o

HEADER = libft.h

all: $(NAME) bonus

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

bonus: $(BONUS_OBJ)
	ar rc $(NAME) $(BONUS_OBJ)

ft_atoi.o: ft_atoi.c $(HEADER)
	$(CC) $(CFLAGS) -c ft_atoi.c -o ft_atoi.o

ft_bzero.o: ft_bzero.c $(HEADER)
	$(CC) $(CFLAGS) -c ft_bzero.c -o ft_bzero.o

ft_calloc.o: ft_calloc.c $(HEADER)
	$(CC) $(CFLAGS) -c ft_calloc.c -o ft_calloc.o

ft_isalnum.o: ft_isalnum.c $(HEADER)
	$(CC) $(CFLAGS) -c ft_isalnum.c -o ft_isalnum.o

ft_isalpha.o: ft_isalpha.c $(HEADER)
	$(CC) $(CFLAGS) -c ft_isalpha.c -o ft_isalpha.o

ft_isascii.o: ft_isascii.c $(HEADER)
	$(CC) $(CFLAGS) -c ft_isascii.c -o ft_isascii.o

ft_isdigit.o: ft_isdigit.c $(HEADER)
	$(CC) $(CFLAGS) -c ft_isdigit.c -o ft_isdigit.o

ft_isprint.o: ft_isprint.c $(HEADER)
	$(CC) $(CFLAGS) -c ft_isprint.c -o ft_isprint.o

ft_itoa.o: ft_itoa.c $(HEADER)
	$(CC) $(CFLAGS) -c ft_itoa.c -o ft_itoa.o

ft_memchr.o: ft_memchr.c $(HEADER)
	$(CC) $(CFLAGS) -c ft_memchr.c -o ft_memchr.o

ft_memcmp.o: ft_memcmp.c $(HEADER)
	$(CC) $(CFLAGS) -c ft_memcmp.c -o ft_memcmp.o

ft_memcpy.o: ft_memcpy.c $(HEADER)
	$(CC) $(CFLAGS) -c ft_memcpy.c -o ft_memcpy.o

ft_memmove.o: ft_memmove.c $(HEADER)
	$(CC) $(CFLAGS) -c ft_memmove.c -o ft_memmove.o

ft_memset.o: ft_memset.c $(HEADER)
	$(CC) $(CFLAGS) -c ft_memset.c -o ft_memset.o

ft_putchar_fd.o: ft_putchar_fd.c $(HEADER)
	$(CC) $(CFLAGS) -c ft_putchar_fd.c -o ft_putchar_fd.o

ft_putendl_fd.o: ft_putendl_fd.c $(HEADER)
	$(CC) $(CFLAGS) -c ft_putendl_fd.c -o ft_putendl_fd.o

ft_putnbr_fd.o: ft_putnbr_fd.c $(HEADER)
	$(CC) $(CFLAGS) -c ft_putnbr_fd.c -o ft_putnbr_fd.o

ft_putstr_fd.o: ft_putstr_fd.c $(HEADER)
	$(CC) $(CFLAGS) -c ft_putstr_fd.c -o ft_putstr_fd.o

ft_split.o: ft_split.c $(HEADER)
	$(CC) $(CFLAGS) -c ft_split.c -o ft_split.o

ft_strchr.o: ft_strchr.c $(HEADER)
	$(CC) $(CFLAGS) -c ft_strchr.c -o ft_strchr.o

ft_strdup.o: ft_strdup.c $(HEADER)
	$(CC) $(CFLAGS) -c ft_strdup.c -o ft_strdup.o

ft_striteri.o: ft_striteri.c $(HEADER)
	$(CC) $(CFLAGS) -c ft_striteri.c -o ft_striteri.o

ft_strjoin.o: ft_strjoin.c $(HEADER)
	$(CC) $(CFLAGS) -c ft_strjoin.c -o ft_strjoin.o

ft_strlcat.o: ft_strlcat.c $(HEADER)
	$(CC) $(CFLAGS) -c ft_strlcat.c -o ft_strlcat.o

ft_strlcpy.o: ft_strlcpy.c $(HEADER)
	$(CC) $(CFLAGS) -c ft_strlcpy.c -o ft_strlcpy.o

ft_strlen.o: ft_strlen.c $(HEADER)
	$(CC) $(CFLAGS) -c ft_strlen.c -o ft_strlen.o

ft_strmapi.o: ft_strmapi.c $(HEADER)
	$(CC) $(CFLAGS) -c ft_strmapi.c -o ft_strmapi.o

ft_strncmp.o: ft_strncmp.c $(HEADER)
	$(CC) $(CFLAGS) -c ft_strncmp.c -o ft_strncmp.o

ft_strnstr.o: ft_strnstr.c $(HEADER)
	$(CC) $(CFLAGS) -c ft_strnstr.c -o ft_strnstr.o

ft_strrchr.o: ft_strrchr.c $(HEADER)
	$(CC) $(CFLAGS) -c ft_strrchr.c -o ft_strrchr.o

ft_strtrim.o: ft_strtrim.c $(HEADER)
	$(CC) $(CFLAGS) -c ft_strtrim.c -o ft_strtrim.o

ft_substr.o: ft_substr.c $(HEADER)
	$(CC) $(CFLAGS) -c ft_substr.c -o ft_substr.o

ft_tolower.o: ft_tolower.c $(HEADER)
	$(CC) $(CFLAGS) -c ft_tolower.c -o ft_tolower.o

ft_toupper.o: ft_toupper.c $(HEADER)
	$(CC) $(CFLAGS) -c ft_toupper.c -o ft_toupper.o

# Bonus
ft_lstadd_back.o: ft_lstadd_back.c $(HEADER)
	$(CC) $(CFLAGS) -c ft_lstadd_back.c -o ft_lstadd_back.o

ft_lstadd_front.o: ft_lstadd_front.c $(HEADER)
	$(CC) $(CFLAGS) -c ft_lstadd_front.c -o ft_lstadd_front.o

ft_lstclear.o: ft_lstclear.c $(HEADER)
	$(CC) $(CFLAGS) -c ft_lstclear.c -o ft_lstclear.o

ft_lstdelone.o: ft_lstdelone.c $(HEADER)
	$(CC) $(CFLAGS) -c ft_lstdelone.c -o ft_lstdelone.o

ft_lstiter.o: ft_lstiter.c $(HEADER)
	$(CC) $(CFLAGS) -c ft_lstiter.c -o ft_lstiter.o

ft_lstlast.o: ft_lstlast.c $(HEADER)
	$(CC) $(CFLAGS) -c ft_lstlast.c -o ft_lstlast.o

ft_lstmap.o: ft_lstmap.c $(HEADER)
	$(CC) $(CFLAGS) -c ft_lstmap.c -o ft_lstmap.o

ft_lstnew.o: ft_lstnew.c $(HEADER)
	$(CC) $(CFLAGS) -c ft_lstnew.c -o ft_lstnew.o

ft_lstsize.o: ft_lstsize.c $(HEADER)
	$(CC) $(CFLAGS) -c ft_lstsize.c -o ft_lstsize.o

clean:
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
