# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yowoo <yowoo@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/12 20:23:52 by yowoo             #+#    #+#              #
#    Updated: 2024/03/14 19:30:37 by yowoo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
SRC = $(wildcard *.c GET_NEXT_LINE/*.c Libft/*.c )
OBJ = $(SRC:.c=.o)
RM = rm -f

all : $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

$(NAME): $(OBJ)
	@$(CC) $(OBJ) -framework Cocoa -framework OpenGL -framework IOKit libmlx42.a -Iinclude -lglfw -o $(NAME)

clean: 
	@$(RM) $(OBJ)

fclean:
	@$(RM) $(OBJ)
	@$(RM) $(NAME)

re: fclean all