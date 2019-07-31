# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ozhyhadl <ozhyhadl@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/08 13:45:25 by ozhyhadl          #+#    #+#              #
#    Updated: 2019/07/18 20:06:47 by ozhyhadl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = RTv1

SRC     = src/main.c \
			src/ft_add_figure.c \
			src/ft_add_light.c \
			src/ft_cilindr.c \
			src/ft_cone.c \
			src/ft_key.c \
			src/ft_light.c \
			src/ft_oper.c \
			src/ft_plane.c \
			src/ft_second_fun.c \
			src/ft_spher.c \
			src/ft_valid.c \
			src/parse.c
OBJ     = $(SRC:.c=.o)
LIBFT   = libft/
HDR  = include/rtv1.h 
CC      = /usr/bin/gcc
CFLAGS  = -Wall -Wextra -Werror -flto -Ofast -pipe
FMLX    = -framework OpenGL -framework AppKit -lmlx
DEL      = /bin/rm -f

all:        $(NAME)

$(NAME):    $(OBJ) $(LIBFT)
	@make -C $(LIBFT)	
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -I $(HDR) -L $(LIBFT)  -lft $(FMLX)
	@echo "\x1b[32m -->> Compilation Success: RTv1"

%.o : %.c $(HDR) $(LIBFT)
	@$(CC) $(CFLAGS) -o $@ -c $< -I .

clean:
	@make fclean -C $(LIBFT)
	@$(DEL) $(OBJ)
	@echo "\x1b[32m -->> Object files are deleted"

fclean:     clean
	@make -C $(LIBFT) fclean
	@$(DEL) $(NAME)
	@echo "\x1b[32m -->> RTv1 was deleted"


re:     fclean all

.PHONY:     re all clean fclean



	