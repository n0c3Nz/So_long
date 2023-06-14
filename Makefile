NAME = so_long

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LFLAGS = -L./src/printf -lftprintf -L./src/libft -lft -L./mlx42 -lmlx -lXext -lX11 -lm -Iinclude -ldl -lglfw -pthread -lm

SRC = main.c process_map_file.c map_utils.c map_utils_2.c mlx_process.c player_move.c graphic_funcs.c do_moves.c enemies_funcs.c\
src/libft/ft_atoi.c src/libft/ft_bzero.c src/libft/ft_calloc.c src/libft/ft_isalnum.c src/libft/ft_isalpha.c \
src/libft/ft_isascii.c src/libft/ft_isdigit.c src/libft/ft_isprint.c src/libft/ft_itoa.c src/libft/ft_lstadd_back.c \
src/libft/ft_lstadd_front.c src/libft/ft_lstclear.c src/libft/ft_lstdelone.c src/libft/ft_lstiter.c src/libft/ft_lstlast.c \
src/libft/ft_lstmap.c src/libft/ft_lstnew.c src/libft/ft_lstsize.c src/libft/ft_memccpy.c src/libft/ft_memchr.c \
src/libft/ft_memcmp.c src/libft/ft_memcpy.c src/libft/ft_memmove.c src/libft/ft_memset.c src/libft/ft_putchar_fd.c \
src/libft/ft_putendl_fd.c src/libft/ft_putnbr_fd.c src/libft/ft_putstr_fd.c src/libft/ft_split.c \
src/printf/ft_printf.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
