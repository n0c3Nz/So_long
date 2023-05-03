# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: guortun- <guortun-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/08 11:09:58 by guortun-          #+#    #+#              #
#    Updated: 2023/02/08 11:09:59 by guortun-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 		= gcc
CFLAGS 	= -Wall -Wextra -Werror -I.
SRCS	= ft_printf.c\
			libft/ft_strlen.c\
			libft/ft_putstr_fd.c\
			libft/ft_putchar_fd.c\
			libft/ft_numlen.c\
			libft/ft_putnbr_fd_base.c\
			libft/ft_putunbr_fd_base.c\
			libft/ft_putaddr_fd.c\
			src/char_handler.c\
			src/str_handler.c\
			src/addr_handler.c\
			src/num_handler.c\
			src/uns_handler.c

OBJS	= $(SRCS:%.c=%.o)
NAME	= libftprintf.a

$(NAME):	$(OBJS)
				ar rc $(NAME) $(OBJS)
				ranlib $(NAME)

all:		$(NAME) 
clean:		
				rm -f $(OBJS)
fclean:		clean
				rm -f $(NAME)
re:		fclean all
.PHONY:		all clean fclean re
