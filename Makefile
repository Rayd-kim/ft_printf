# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youskim <youskim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/24 14:31:07 by youskim           #+#    #+#              #
#    Updated: 2022/02/25 13:41:10 by youskim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
W = -Wall -Wextra -Werror
FILE = ft_printf_idupx.c ft_printf.c hexa.c
OBJS = $(FILE:.c=.o)
LIBDIR = libft

all : $(NAME)

$(OBJS) : $(FILE)
	$(CC) $(W) -c $^

$(NAME) : $(OBJS)
	@$(MAKE) -C ./libft all
	cp ./libft/libft.a ./$(NAME)
	ar rcs $@ $^

clean:
	rm -f $(OBJS)
	@$(MAKE) -C ./libft clean

fclean : clean
	rm -f $(NAME)
	@$(MAKE) -C ./libft fclean
	
re : fclean all

.PHONY: all clean fclean re
