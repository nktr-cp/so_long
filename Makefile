# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: knishiok <knishiok@student.42.jp>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/22 15:25:41 by knishiok          #+#    #+#              #
#    Updated: 2023/11/11 14:37:48 by knishiok         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

INC = -I mandatory/includes -I bonus/includes

NAME = so_long
BONUS = so_long_bonus

BONUS_SRCS = bonus/srcs/main_bonus.c \
	bonus/srcs/utils_bonus.c \
	bonus/srcs/struct_map_bonus.c \
	bonus/srcs/graphics_bonus.c \
	bonus/srcs/graphics_utils_bonus.c \
	bonus/srcs/handle_map_error1_bonus.c \
	bonus/srcs/handle_map_error2_bonus.c \
	bonus/srcs/enemy_bonus.c

SRCS = mandatory/srcs/main.c \
	mandatory/srcs/utils.c \
	mandatory/srcs/struct_map.c \
	mandatory/srcs/graphics.c \
	mandatory/srcs/handle_map_error1.c \
	mandatory/srcs/handle_map_error2.c \

LIB = libft/libft.a

MLX = mlx/libmlx.dylib

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIB)
	make -C mlx
	cp $(MLX) .
	$(CC) $(CFLAGS) $(INC) $^ -Lmlx -lmlx -framework OpenGL -framework Appkit -o $@

bonus: $(BONUS)

$(BONUS): $(BONUS_OBJS) $(LIB)
	make -C mlx
	cp $(MLX) .
	$(CC) $(CFLAGS) $(BONUS_INC) $^ -Lmlx -lmlx -framework OpenGL -framework Appkit -o $@

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -Imlx -c $< -o $@

$(LIB):
	make -C libft

clean:
	$(RM) $(OBJS)
	$(RM) $(BONUS_OBJS)
	make clean -C libft
	make clean -C mlx

fclean: clean
	$(RM) $(LIB)
	$(RM) $(MLX)
	$(RM) libmlx.dylib
	$(RM) $(NAME)
	$(RM) $(BONUS)

re: fclean all

IMAGE_NAME = so_long_env
build:
	docker build -t $(IMAGE_NAME) .

# this part highly depends on your architecture
IP = $(shell ipconfig getifaddr en0)
login:
	xhost + $(IP)
	docker run -it \
		-e DISPLAY=$(IP):0 \
		-v /tmp/.X11-unix:/tmp/.X11-unix \
		$(IMAGE_NAME)

.PHONY: all clean fclean re
