# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: znaoui <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/09 14:06:35 by znaoui            #+#    #+#              #
#    Updated: 2022/05/11 08:27:25 by znaoui           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

############### SETUP ###############

NAME = so_long

CFLAGS = -Wall -Wextra -Werror -g3

FLAGS = -Imlx -Lmlx -lmlx -lXext -lX11

SRCS = $(addprefix utils/, main.c ft_check_file.c mouv_map2.c mouv_map.c init_window.c parsing.c \
	rules_parsing2.c rules_parsing.c ft_printf.c ft_putchar.c ft_putnbr_adress.c ft_putnbr.c \
	ft_putnbr_hexa.c ft_putnbr_unsigned.c ft_putstr.c ft_size_len.c get_next_line.c get_next_line_utils.c)

OBJS = $(SRCS:.c=.o)

############### COMMANDS ###############

all:
	make --no-print-directory ${NAME}

.c.o:
	clang ${CFLAGS} -Imlx -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	make -C "./mlx/"
	clang ${CFLAGS} -o ${NAME} ${OBJS} ${FLAGS}
	echo "$(WHITE)Compilation in progress..$(DEFAULT)"
	sleep 1
	echo "$(GREEN)The program ${NAME} is ready!$(DEFAULT)"

help:
	echo "$(WHITE)Commands available: all, clean, fclean, re$(DEFAULT)"

clean:
	rm -rf ${OBJS}
	echo "$(YELLOW)All object files have been deleted$(DEFAULT)"

fclean: clean
	rm -rf ${NAME}
	echo "$(RED)The program ${NAME} has been deleted$(DEFAULT)"

re: fclean
	make --no-print-directory all

.PHONY: all clean fclean re

.SILENT: 

################ COLORS ###############
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m
WHITE = \033[1;37m