# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bepifani <bepifani@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/08 17:26:19 by bepifani          #+#    #+#              #
#    Updated: 2022/02/08 17:49:24 by bepifani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

HEADER = so_long.h
LIBFT = libft/libft.a
MLX = mlx/libmlx.a

FLAGS = gcc -Wall -Wextra -Werror
MLXFLAGS = -framework OpenGL -framework AppKit

FILES = 

OBJ = $(FILES: .c=.o)

all : $(NAME)

%.o: %.c $(HEADER)
	$(FLAGS) -o $@ -c $<

$(NAME) : $(OBJ) $(LIBFT) $(MLX) $(HEADER)
	$(FLAGS) $(MLXFLAGS) $(OBJ) $(LIBFT) $(MLX) -o $(NAME)

$(LIBFT):
	$(MAKE) bonus -C libft

$(MLX):
	$(MAKE) -C mlx

clean:
	$(RM) $(OBJ)
	$(MAKE) clean -C libft
	$(MAKE) clean -C mlx

fclean: clean
	$(RM) $(NAME)
	$(RM) $(LIBFT)
	$(RM) $(MLX)

re: fclean all

.PHONY: all clean fclean re bonus