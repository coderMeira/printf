# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmeira <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/19 18:37:53 by fmeira            #+#    #+#              #
#    Updated: 2021/05/10 17:11:35 by fmeira           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

NAME		= libftprintf.a
INCLUDE		= ft_printf.h

SRCS		= ft_chars.c ft_flags.c ft_ints.c ft_printf.c ft_putconversions.c \
		 	ft_strings.c libft/ft_isdigit.o libft/ft_itoa.o libft/ft_strdup.o \
		  	libft/ft_strlen.o libft/ft_bzero.o libft/ft_putchar_fd.o 		  \
			libft/ft_itoa_base_bonus.c ft_uxp.c libft/ft_strjoin.c 			  \
			libft/ft_u_itoa_bonus.c libft/ft_strncmp.c

OBJS		= $(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS) $(INCLUDE)
			ar -rcs $(NAME) $(OBJS)
			ranlib	$(NAME)

.c.o:
			$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $(<:.c=.o)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
