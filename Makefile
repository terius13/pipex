# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ting <ting@student.42singapore.sg>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/09 14:57:42 by ting              #+#    #+#              #
#    Updated: 2024/05/11 15:49:12 by ting             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

FLAGS = -Wall - Werror -Wextra

SRC_PATH = srcs/

SRCS = pipex.c

OBJS = $(addprefix $(SRC_PATH), $(SRCS:.c=.o))

LIBFT = libft/libft.a

$(LIBFT):
			$(MAKE) -C libft

$(NAME): $(OBJS)
			cc $(FLAGS) $(OBJS) $(LIBFT) -o $(NAME)

all: $(LIBFT) $(NAME)

clean:
			$(MAKE) clean -C libft
			rm -rf $(OBJS)

fclean: clean
			$(MAKE) fclean -C libft
			rm -rf $(NAME)
