# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lweglarz <lweglarz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/15 14:11:55 by lweglarz          #+#    #+#              #
#    Updated: 2020/07/28 15:20:33 by lweglarz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a

FLAGS= -Wall -Wextra -Werror

SRCS= ft_printf.c utils1display.c utils2.c utils3.c utils4.c ft_flags_init.c ft_print_percent.c ft_print_c.c ft_print_id.c ft_print_p.c ft_print_s.c ft_print_u.c ft_print_x.c \

OBJS= ft_printf.o utils1display.o utils2.o utils3.o utils4.o ft_flags_init.o ft_print_percent.o ft_print_c.o ft_print_id.o ft_print_p.o ft_print_s.o ft_print_u.o ft_print_x.o \

LIBFT= libft/

RM	= rm -f

CC = cc

OBJS = $(SRCS:.c=.o)

.c.o:
	$(CC) $(FLAGS) -c $< -o $@
all: $(NAME)

$(NAME): $(OBJS) ft_printf.h
	make -C $(LIBFT) all
	@gcc -Wall -Wextra -Werror -c $(SRCS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME) 

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re: fclean all
