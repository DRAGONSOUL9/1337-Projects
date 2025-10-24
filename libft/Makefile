# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oel--mou <oel--mou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/13 18:29:25 by oel--mou          #+#    #+#              #
#    Updated: 2025/10/24 08:43:51 by oel--mou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
FLG = -Wall -Wextra -Werror
SRC = ft_isascii.c ft_isalnum.c ft_isalpha.c ft_isdigit.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c \
	  ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c\
	  ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c
SRC2 = ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c\
	   ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
B_SRC = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c\
		ft_lstiter.c ft_lstmap.c
OBJ = $(SRC:.c=.o) $(SRC2:.c=.o)
B_OBJ = $(B_SRC:.c=.o)
NAME = libft.a

$(NAME): $(OBJ)
	ar -crs $(NAME) $(OBJ)
	
all: $(NAME)

bonus: $(B_OBJ)
	ar -crs $(NAME) $(B_OBJ)

%.o : %.c
	$(CC) $(FLG) -c $< -o $@
	
clean:
	rm -rf $(OBJ) $(B_OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
