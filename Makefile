# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: knishiok <knishiok@student.42.jp>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/22 15:25:41 by knishiok          #+#    #+#              #
#    Updated: 2023/11/04 16:43:11 by knishiok         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

INC = -I includes

NAME = so_long

SRCS = srcs/main.c \
	srcs/handle_error1.c \
	srcs/handle_error2.c \

LIB = libft/libft.a

MLX = mlx/libmlx.dylib

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIB)
	make -C mlx
	cp $(MLX) .
	$(CC) $(CFLAGS) $(INC) $^ -Lmlx -lmlx -framework OpenGL -framework Appkit -o $@

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -Imlx -c $< -o $@

$(LIB):
	make -C libft

clean:
	$(RM) $(OBJS)
	make clean -C libft
	make clean -C mlx

fclean: clean
	$(RM) $(LIB)
	$(RM) $(MLX)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
