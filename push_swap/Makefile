# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oel--mou <oel--mou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/17 10:45:23 by oel--mou          #+#    #+#              #
#    Updated: 2025/11/24 18:05:40 by oel--mou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
FLG = -Wall -Wextra -Werror -g
SRC = push_swap.c push_swap_utils.c push_swap_moves.c push_swap_lst.c push_swap_checks.c\
		push_swap_test.c push_swap_algos.c sort_small.c sort_three.c
OBJ = $(UTL:.c=.o)
NAME = push_swap
LIB = libft/libft.a

$(NAME): $(LIB) $(SRC)
	$(CC) $(FLG) $(SRC) $(LIB) -o $(NAME)

$(LIB): $(OBJ)
	$(MAKE) -C libft
	ar -crs $(LIB) $(OBJ)
	
all: $(NAME)

%.o : %.c
	$(CC) $(FLG) -c $< -o $@
	
clean:
	rm -rf $(OBJ)
	$(MAKE) clean -C libft

fclean: clean
	rm -rf $(NAME)
	$(MAKE) fclean -C libft

re: fclean all

.SECONDARY: $(OBJ)
.PHONY: all clean fclean re