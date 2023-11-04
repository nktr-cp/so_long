# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: knishiok <knishiok@student.42.jp>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/20 09:55:58 by knishiok          #+#    #+#              #
#    Updated: 2023/10/29 14:37:06 by knishiok         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
ARFLAGS = rc
MAND_SRCS = ft_atoi.c \
	ft_bzero.c \
	ft_calloc.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_itoa.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_memset.c \
	ft_putchar_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_putstr_fd.c \
	ft_split.c \
	ft_strchr.c \
	ft_strdup.c \
	ft_striteri.c \
	ft_strjoin.c \
	ft_strlcat.c \
	ft_strlcpy.c \
	ft_strlen.c \
	ft_strmapi.c \
	ft_strcmp.c \
	ft_strncmp.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_strtrim.c \
	ft_substr.c \
	ft_tolower.c \
	ft_toupper.c \
	ft_min.c \
	ft_max.c \
	ft_abs.c \
	ft_printf.c \
	helper1.c \
	helper2.c \
	helper3.c \
	helper4.c \
	printf_parse.c \
	print_c_s_percent.c \
	print_d_i.c \
	print_u.c \
	print_x.c \
	print_upper_x.c \
	get_next_line.c 

MAND_OBJS = $(MAND_SRCS:.c=.o)

BONUS_OBJS = $(BONUS:.c=.o)
INC = -I .

FLG = 0

ifeq ($(FLG), 0)
	OBJS = $(MAND_OBJS)
else
	OBJS = $(MAND_OBJS) $(BONUS_OBJS)
endif

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

bonus:
	@make FLG=1 all

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re