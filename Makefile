# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/10 15:46:45 by mhaziza           #+#    #+#              #
#    Updated: 2017/01/03 14:56:59 by mhaziza          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fdf
CC		=   gcc
CFLAGS	= 	-Wall -Wextra -Werror -I.
RM		=   rm -f
SRCS	=	ft_hook_utils.c \
			ft_get_coordinates.c \
			ft_draw_utils.c \
			get_next_line.c \
			main.c \
			ft_color_utils.c \
			ft_alloc_points.c \

OBJS	=   $(SRCS:.c=.o)

LIBFT_PATH	= ./libft

all:	$(NAME)

$(NAME):$(OBJS)
	@make -C $(LIBFT_PATH)
	@$(CC) $(CFLAG) $(SRCS) -I/usr/local/include/mlx.h -lmlx -framework OpenGL -framework Appkit -L./libft -lft -o $(NAME)

clean:
	@rm -f $(OBJS)
	@make -C $(LIBFT_PATH) clean

fclean:	clean
	@rm -f $(NAME)
	@make -C $(LIBFT_PATH) fclean

re:		fclean all

.PHONY:		all clean fclean re
