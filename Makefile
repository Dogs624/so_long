# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jvander- <jvander-@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/02 10:07:20 by jvander-          #+#    #+#              #
#    Updated: 2021/10/21 10:14:30 by jvander-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long
LIBFT	=	./libft
SOURCES =	sources/
ERRORS	=	errors/
CC		=	gcc
INCLUDES = -I./includes/
FLAGS	=	-Wall -Werror -Wextra $(INCLUDES)
MLX		=	./mlx
UTILS	=	utils/

SRCS	=	$(SOURCES)so_long.c \
			$(SOURCES)create_window.c \
			$(SOURCES)create_image.c \
			$(SOURCES)create_bckgrnd.c \
			$(SOURCES)create_map.c \
			$(SOURCES)movments.c \
			$(SOURCES)on_case.c \

SRCS_UTILS	=	$(UTILS)get_height_map.c \
				$(UTILS)get_width_map.c \
				$(UTILS)get_pos_player.c \
				$(UTILS)nbr_collect_left.c \
				$(UTILS)keep_one_player.c \

SRCS_ERRORS	=	$(ERRORS)check_rectangle.c \
				$(ERRORS)surrounded_wall.c \
				$(ERRORS)check_contain.c \
				$(ERRORS)error_handling.c \
				$(ERRORS)check_size_window.c \
				$(ERRORS)check_args.c \

%.o: %.c
		$(CC) $(FLAGS) -Imlx -c $< -o $@

OBJS		=	$(SRCS:.c=.o)

OBJS_UTILS	=	$(SRCS_UTILS:.c=.o)

OBJS_ERRORS	=	$(SRCS_ERRORS:.c=.o)

$(NAME):	$(OBJS) $(OBJS_UTILS) $(OBJS_ERRORS)
			$(MAKE) -C $(LIBFT)
			$(MAKE) -C $(MLX)
			mv ./mlx/libmlx.dylib ./
			$(CC) $(FLAGS) $(OBJS) $(OBJS_UTILS) $(OBJS_ERRORS) libmlx.dylib -L$(LIBFT) -lft -o  $(NAME)

all:	$(NAME)

clean:
		$(MAKE) clean -C $(LIBFT)
		$(MAKE) clean -C $(MLX)
		rm -f $(OBJS) $(OBJS_UTILS) $(OBJS_ERRORS) ./libmlx.dylib

fclean:	clean
		$(MAKE) fclean -C $(LIBFT)
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
