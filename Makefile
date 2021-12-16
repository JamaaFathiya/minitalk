# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fathjami <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/15 16:00:20 by fathjami          #+#    #+#              #
#    Updated: 2021/12/16 17:08:08 by fathjami         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC= gcc
FLAGS= -Wall -Wextra -Werror
SERVER= server
CLIENT= client
PRINTFLIB= ft_printf/libftprintf.a
PATH= ft_printf

SER_SRC= server.c
SER_OBJ= server.o
CLI_SRC= client.c
CLI_OBJ= client.o

all: $(PRINTFLIB) $(SERVER) $(CLIENT)

$(SERVER): $(SER_OBJ) minitalk.h
	$(CC) $(LIB) -o $@ $(SER_OBJ)

$(CLIENT): $(CLI_OBJ) minitalk.h
	$(CC) $(LIB) -o $@ $(CLI_OBJ)

%.o: %.c
	$(CC) -c $(FLAGS) $< -o $@

$(PRINTFLIB):
	$(MAKE) -C $(PATH)

clean:
	$(MAKE) clean -C $(PATH)
	rm -rf $(SER_OBJ) $(CLI_OBJ)

fclean: clean 
	$(MAKE) fclean -C $(PATH)
	rm -rf $(SERVER) $(CLIENT)

re: fclean all

.PHONY: all clean fclean re
