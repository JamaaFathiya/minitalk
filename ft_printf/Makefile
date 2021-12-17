# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fathjami <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/26 13:37:42 by fathjami          #+#    #+#              #
#    Updated: 2021/12/17 21:39:11 by fathjami         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS= -Wall -Wextra -Werror -I ft_printf.h
NAME=libftprintf.a
FILES=ft_printf ft_putnbr ft_putstr ft_pointer ft_putchar\
	  ft_strlen ft_putnbr_base ft_putuns ft_atoi  
OBJS=$(FILES:=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
%.o: %.c ft_printf.h
	@gcc -c $(FLAGS)  $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all
