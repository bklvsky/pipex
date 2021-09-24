# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/27 21:46:39 by dselmy            #+#    #+#              #
#    Updated: 2021/09/24 17:05:53 by dselmy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRCS_DIR = ./

INC_DIR = ./includes/

LIBDIR = ./libft/

SRCS = $(addprefix $(SRCS_DIR), $(shell find $(SRCS_DIR) -maxdepth 1 -name "*.c"))

OBJ = $(SRCS:.c=.o)

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
		@make -C $(LIBDIR)
		gcc -o $(NAME) $(FLAGS) -I$(INC_DIR) $(OBJ) $(LIBDIR)libft.a

$(OBJS): %.o: %.c
		gcc -c $(FLAGS) -I$(INC_DIR) $< -o $@

clean:
		@make clean -C $(LIBDIR)
		rm -f $(OBJ)

fclean: clean
		@make fclean -C $(LIBDIR)
		rm -f $(NAME)
		
re: fclean all

.PHONY: all clean fclean re
