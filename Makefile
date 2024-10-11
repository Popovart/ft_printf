NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c ft_printf_format.c ft_putlstchar.c ft_process_precision.c ft_process_decimal_type.c \
	ft_flags.c ft_extract_num.c ft_align.c ft_print_type_with_align.c ft_add_strtolst.c ft_process_string_type.c \
	ft_process_hex_type.c ft_add_signtolst.c ft_add_zerostolst.c ft_format_output_and_print.c ft_process_pointer_type.c \
	ft_add_hextolst.c ft_process_unsdecimal_type.c ft_utoa.c
MAIN_SRC = main.c

OBJ = $(SRC:.c=.o)
MAIN_OBJ = $(MAIN_SRC:.c=.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

HEADER = ft_printf.h

all: $(NAME)

bonus: all

$(NAME): $(LIBFT) $(OBJ) 
	cp $(LIBFT) $(NAME)
	ar rc $(NAME) $(OBJ)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -I . -c $< -o $@

program: $(NAME) $(MAIN_OBJ)
	$(CC) $(MAIN_OBJ) $(NAME) $(LIBFT) -o program

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJ)

# delete program after testing
fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME) program

re: fclean all

.PHONY: all bonus clean fclean re
