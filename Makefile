# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hgeissle <hgeissle@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/19 14:22:07 by hgeissle          #+#    #+#              #
#    Updated: 2023/03/06 13:30:59 by hgeissle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = main.c parsing.c radix.c operations.c sorting.c utils.c

SRC_LIBFT = libft_fcts.c ft_printf.c ft_printf_tools.c ft_split.c ft_split_utils.c

FLAGS = -Wall -Wextra -Werror
INCLUDE = 
AR = ar rcs
RM = rm -f
OBJS = $(SRC:.c=.o)
OBJS_LIBFT = $(SRC_LIBFT:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(OBJS_LIBFT)
	cc $(FLAGS) $(OBJS) $(OBJS_LIBFT) $(INCLUDE) -o $(NAME)

clean:
		$(RM) $(OBJS) $(OBJS_LIBFT)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re