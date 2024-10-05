NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c ft_putnbr_fd.c ft_printf_format.c ft_numlen.c ft_isdigit.c
MAIN_SRC = main.c

OBJ = $(SRC:.c=.o)
MAIN_OBJ = $(MAIN_SRC:.c=.o)

HEADER = ft_printf.h

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	ar rc $(NAME) $(OBJ)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -I . -c $< -o $@

program: $(NAME) $(MAIN_OBJ)
	$(CC) $(MAIN_OBJ) $(NAME) -o program

clean:
	rm -f $(OBJ)

# delete program after testing
fclean: clean
	rm -f $(NAME) program

re: fclean all

.PHONY: all clean fclean re
