# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bepifani <bepifani@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/05 11:48:01 by bepifani          #+#    #+#              #
#    Updated: 2021/10/11 21:11:56 by bepifani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = 	ft_atoi		ft_bzero	ft_isalnum	ft_isalpha\
		ft_isascii	ft_isdigit	ft_isprint	ft_memchr\
		ft_memcmp	ft_memmove	ft_memset	ft_strchr	ft_strlcat\
		ft_strlcpy	ft_strlen	ft_strncmp	ft_strnstr\
		ft_strrchr	ft_tolower	ft_toupper	ft_calloc\
		ft_strdup	ft_memcpy	ft_substr	ft_strjoin\
		ft_strtrim	ft_split	ft_itoa		ft_strmapi\
		ft_striteri	ft_putchar_fd	ft_putstr_fd\
		ft_putendl_fd	ft_putnbr_fd	ft_lstnew\
		ft_lstadd_front	ft_lstsize	ft_lstlast\
		ft_lstadd_back	ft_lstdelone	ft_lstclear\
		ft_lstiter	ft_lstmap

SRCS = $(addsuffix .c, $(SRC))

FLAGS = -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS)
		ar rc $(NAME) $(OBJS)
		ranlib $(NAME)
.c.o :
	gcc $(FLAGS) -c $< -o ${<:.c=.o}

all : $(NAME)

bonus : all	

clean :
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re