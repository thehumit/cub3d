# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tquintan <tquintan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/06 12:59:22 by tquintan          #+#    #+#              #
#    Updated: 2020/11/06 17:40:17 by tquintan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

CC		=	gcc

FLAGS	=	-Wall -Werror -Wextra

HEAD	=	libft.h

LIB		=	-L. -lft

HFLAG	=	-I ${HEAD}

SRCS	=	ft_atoi.c \
 			ft_bzero.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_memccpy.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memset.c \
			ft_strchr.c \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_strrchr.c \
			ft_strnstr.c \
			ft_strncmp.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_calloc.c \
			ft_strdup.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_split.c \
			ft_itoa.c \
			ft_strmapi.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c

SRCS_B =	ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c
OBJS	=	${SRCS:.c=.o}

OBJS_B	=	${SRCS_B:.c=.o}
RM		=	rm -f
.c.o: ${CC} ${FLAGS} -c ${SRCS} ${HFLAG}
${NAME}:	${OBJS}
	${CC} ${FLAGS} -c ${SRCS} ${HFLAG}
	ar rc ${NAME} ${OBJS}
	ranlib ${NAME}
bonus:	${OBJS_B} ${OBJS}
	${CC} ${FLAGS} -c ${SRCS_B} ${HFLAG}
	ar rc ${NAME} ${OBJS_B}
	ranlib ${NAME}

all: ${NAME}
clean:
	${RM} ${OBJS} ${OBJS_B}
fclean:clean
	${RM} ${NAME}
re: 	fclean	all

.PHONY: clean fclean re all bonus
