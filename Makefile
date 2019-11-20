# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pfu <spashleyfu@gmail.com>                 +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/17 19:35:01 by pfu               #+#    #+#              #
#    Updated: 2019/11/19 17:44:28 by pfu              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

FLAGS = -Wall -Wextra -Werror

LIBDIR = libft/

SRCDIR = src/

SRC = src/*.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): 
	@make -C $(LIBDIR)
	@gcc $(FLAGS) -o $(NAME) $(SRC) -I $(SRCDIR) -I $(LIBDIR) -L $(LIBDIR) -lft

clean:
	@rm -rf $(OBJ)
	@make -C $(LIBDIR) clean

fclean: clean
	@rm -rf $(NAME)
	@make -C $(LIBDIR) fclean

re: fclean all
