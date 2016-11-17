# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apetitje <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/02 22:21:20 by apetitje          #+#    #+#              #
#    Updated: 2016/11/16 12:19:43 by apetitje         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I $(INC)
INC = ./includes

SRC = ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memalloc.c ft_memdel.c ft_putchar.c ft_putstr.c ft_strcat.c ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c ft_strlcat.c ft_strlen.c ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnew.c ft_tolower.c ft_toupper.c ft_atoi.c ft_putnbr.c ft_putendl.c ft_itoa.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_strchr.c ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_lstmap.c ft_lstiter.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstnew.c ft_sqrt.c ft_realloc.c ft_strndup.c

BINARY = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(BINARY)
	ar r $@ $^
	ranlib $(NAME)

clean :
	/bin/rm -f $(BINARY)

fclean : clean
	/bin/rm -f $(NAME)

re : fclean all
