# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oel--mou <oel--mou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/19 16:26:21 by oel--mou          #+#    #+#              #
#    Updated: 2025/10/27 15:18:48 by oel--mou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
FLG = -Wall -Wextra -Werror
SRC = ft_putchar_fd.c ft_putstr_fd.c ft_printf.c ft_strlen.c ft_putnbr_base.c ft_addr.c ft_putnbr_fd.c
OBJ = $(SRC:.c=.o)
NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJ)
	ar -crs $@ $(OBJ)

%.o: %.c
	$(CC) $(FLG) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

test: $(NAME)
	@$(CC) $(FLG) main.c libftprintf.a
	@./a.out

.SECONDARY: $(OBJ)
.PHONY: all clean fclean re test