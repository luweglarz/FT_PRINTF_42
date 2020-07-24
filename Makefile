# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lweglarz <lweglarz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/15 14:11:55 by lweglarz          #+#    #+#              #
#    Updated: 2020/07/24 15:45:12 by lweglarz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a

SRCS= ft_printf.c utils1display.c utils2display.c utils3.c utils4.c utils5.c flags.c ft_treat_percent.c ft_treat_c.c ft_treat_id.c ft_treat_p.c ft_treat_s.c ft_treat_u.c ft_treat_x.c \

OBJS= ft_printf.o utils1display.o utils2display.o utils3.o utils4.o utils5.o flags.o ft_treat_percent.o ft_treat_c.o ft_treat_id.o ft_treat_p.o ft_treat_s.o ft_treat_u.o ft_treat_x.o \

RM	= rm -f

all: $(NAME)

$(NAME): $(OBJS) ft_printf.h
	@gcc -Wall -Wextra -Werror -c $(SRCS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME) 

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re: fclean all
