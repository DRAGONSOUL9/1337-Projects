# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oel--mou <oel--mou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/17 10:45:23 by oel--mou          #+#    #+#              #
#    Updated: 2025/12/02 17:54:34 by oel--mou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
FLG = -Wall -Wextra -Werror -g
P_SRC = main_program/push_swap.c\
		main_program/push_swap_moves.c\
		main_program/sort_big.c\
		main_program/sort_small.c\
		main_program/sort_three.c\
		main_program/push_swap_checks.c\
		main_program/push_swap_lst.c\
		main_program/push_swap_lst2.c\
		main_program/push_swap_utils.c\
		main_program/count.c\

C_SRC = checker_program/checker_bonus.c\
		checker_program/move_push_bonus.c\
		checker_program/move_reverse_rotate_bonus.c\
		checker_program/move_rotate_bonus.c\
		checker_program/move_swap_bonus.c\
		checker_program/checker_checks_bonus.c\
		checker_program/checker_lst_bonus.c\
		checker_program/checker_utils_bonus.c\

P_OBJ = $(P_SRC:.c=.o)
C_OBJ = $(C_SRC:.c=.o)

NAME = push_swap
BONUS = checker
LIB = libft/libft.a

all: $(NAME)

$(NAME): $(P_OBJ) $(LIB)
	$(CC) $(FLG) $(P_OBJ) $(LIB) -o $(NAME)

$(LIB):
	$(MAKE) -C libft

%.o : %.c
	$(CC) $(FLG) -c $< -o $@
	
clean:
	rm -rf $(P_OBJ)
	rm -rf $(C_OBJ)
	$(MAKE) clean -C libft

fclean: clean
	rm -rf $(NAME)
	rm -rf $(BONUS)
	$(MAKE) fclean -C libft

re: fclean all

bonus: $(BONUS)

$(BONUS): $(LIB) $(C_OBJ)
	$(CC) $(FLG) $(C_OBJ) $(LIB) -o $(BONUS)

.SECONDARY: $(P_OBJ) $(C_OBJ)
.PHONY: all clean fclean re bonus