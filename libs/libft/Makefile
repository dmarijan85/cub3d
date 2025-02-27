# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mclaver- <mclaver-@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/25 17:50:46 by mclaver-          #+#    #+#              #
#    Updated: 2025/02/25 11:53:07 by dmarijan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
HEADERS = ft_printf.h

CC = cc
CFLAGS = -Wall -Wextra -Werror

AR = ar
ARFLAGS = rcs

SRCS = ft_printf.c ft_functions1.c ft_functionshex.c ft_functionsptr.c\
	   ft_itoa.c ft_functionsuint.c
OBJS = $(SRCS:%.c=%.o)
LIBOBJS = $(find ./libft *.c)

all: $(NAME)

$(NAME): $(OBJS) $(LIBOBJS) $(HEADERS)
	@make -C libft
	@cp libft/libft1.a .
	@mv libft1.a libft.a
	@$(AR) $(ARFLAGS) $(NAME) $(OBJS)

%.o: %.c Makefile
	@echo "Compiled $< to $@"
	@$(CC) $(CFLAGS) -MMD -c $< -o $@

clean:
	@rm -f $(OBJS) $(BOBJS)
	@rm -f *.d
	@make -C libft clean

fclean: clean
	@rm -f $(NAME)
	@make -C libft fclean

re: fclean all

.PHONY: all clean fclean re
