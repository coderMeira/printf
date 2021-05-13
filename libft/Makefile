# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmeira <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/18 20:38:48 by fmeira            #+#    #+#              #
#    Updated: 2021/04/08 17:59:59 by fmeira           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -*- MakeFile -*- 

NAME = libft.a
HEADER = libft.h
SRC = ${wildcard ft_*.c}
OBJ = ${SRC:.c=.o}
FLAGS = -Wall -Wextra -Werror

${NAME}: ${OBJ}
	ar -rs ${NAME} ${OBJ}

%.o: %.c 
	gcc ${FLAGS} -c -o $@ $<

all: ${NAME}

bonus: ${NAME}

clean:
	rm -f ${OBJ}

.PHONY: clean
fclean: clean
	rm -f ${NAME}

re: fclean all
