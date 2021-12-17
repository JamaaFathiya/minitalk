# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fathjami <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/15 16:00:20 by fathjami          #+#    #+#              #
#    Updated: 2021/12/17 21:52:39 by fathjami         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC    = gcc
FLAGS    = -Wall -Wextra -Werror

SRV    = server
CLI    = client

SRV_C = $(SRV:=.c)
CLI_C = $(CLI:=.c)

SRV_O    = $(SRV:=.o)
CLI_O = $(CLI:=.o)

LIB = ft_printf/libftprintf.a
LIBDIR    = ft_printf

INC = minitalk.h

all: $(LIB) $(SRV) $(CLI)

$(SRV): $(SRV_O) $(INC)
	@ $(CC) $(FLAGS) -I $(INC) $(LIB) $(SRV_O) -o $@
	@ echo "[FATHIYA] Shrif server is ready!"

$(CLI): $(CLI_O) $(INC)
	@ $(CC) $(FLAGS) -I $(INC) $(LIB) $(CLI_O) -o $@
	@ echo "[FATHIYA] Shrif client is ready!"

%.o: %.c
	@ $(CC) $(FLAGS) -c $< -o $@

$(LIB):
	@ $(MAKE) -C $(LIBDIR)

clean:
	@ $(MAKE) clean -C $(LIBDIR)
	@ rm -rf $(SRV_O) $(CLI_O)
	@ echo "[FATHIYA] Shrif everything is clean!"

fclean: clean
	@ $(MAKE) fclean -C $(LIBDIR)
	@ rm -rf $(SRV) $(CLI)
	@ echo "[FATHIYA] Shrif everything is fclean XD!"

re: fclean all

.PHONY: all clean fclean re
