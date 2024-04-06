# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yowoo <yowoo@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/12 20:23:52 by yowoo             #+#    #+#              #
#    Updated: 2024/04/05 22:55:53 by yowoo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = gcc
SRC = $(wildcard *.c GET_NEXT_LINE/*.c Libft/*.c ft_printf/*.c)
OBJ = $(SRC:.c=.o)
RM = rm -rf
CC_FLAGS = -Wall -Wextra -Werror

all : $(NAME)

%.o: %.c
	$(CC)  $(CC_FLAGS) -Imlx -c $< -o $@

$(NAME): $(OBJ)
	@cd MLX42 && cmake -B build && cmake --build build -j4
	@$(CC) $(OBJ) -framework Cocoa -framework OpenGL -framework IOKit ./MLX42/build/libmlx42.a -Iinclude -lglfw -g -o $(NAME)

clean: 
	@$(RM) $(OBJ)
	@$(RM) ./MLX42/build

fclean:
	@$(RM) $(OBJ)
	@$(RM) $(NAME)
	@$(RM) ./MLX42/build

re: fclean all