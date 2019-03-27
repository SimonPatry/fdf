# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcordeno <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/22 09:45:37 by lcordeno          #+#    #+#              #
#    Updated: 2019/02/07 16:06:58 by sipatry          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = srcs/center.c \
	  srcs/change_z.c \
	  srcs/check_errors.c \
	  srcs/color.c \
	  srcs/display.c \
	  srcs/hooks.c \
	  srcs/hud.c \
	  srcs/main.c \
	  srcs/move.c \
	  srcs/parsing.c \
	  srcs/parsing_tools.c \
	  srcs/trace.c \
	  srcs/transform.c \
	  srcs/zoom.c

INCLUDE = includes/fdf.h

LIBFT = libft/libft.a

OBJS= $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror -O3

MLX = -L /usr/local/lib/ -lmlx -framework OpenGL -framework Appkit

$(NAME): $(LIBFT) $(OBJS)
	gcc $(FLAGS) -include $(INCLUDE) -o $(NAME) $(OBJS) $(LIBFT) $(MLX)

$(LIBFT):
	make -C libft/

%.o: %.c fdf.h Makefile
	gcc $(FLAGS) -include $(INCLUDE) -o $@ -c $<

all: $(NAME)

.PHONY: clean

clean:
	@make -C libft/ clean
	@rm -f $(OBJS)

fclean: clean
	@make -C libft/ fclean
	@rm -f $(NAME)

re: fclean all
