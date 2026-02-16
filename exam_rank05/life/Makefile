# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: codespace <codespace@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/03 13:51:39 by tabading          #+#    #+#              #
#    Updated: 2025/08/04 09:27:27 by codespace        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = life

SRC_P = main \
		initi \
		fr \
        

SRC_DIR	=	
OBJ_DIR	=	obj/

SRC = 		$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_P)))
OBJ =		$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_P)))

DEP =		$(OBJ:%.o=%.d)

CFLAGS = -Wall -Wextra -Werror -g

CC = gcc

all: $(NAME) 

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	echo "\033[0;36m[$(NAME) created]\033[0m"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -MMD -c $< -o $@

-include $(DEP)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
	echo "\033[0;36m[obj dir created]\033[0m"

clean:
	rm -rf $(OBJ_DIR)
	echo "\033[0;36m[removed obj dir]\033[0m"

fclean: clean
	rm -rf $(NAME)
	echo "\033[0;36m[removed $(NAME)]\033[0m"

re: fclean all

val: $(NAME)
	valgrind --leak-check=full ./$(NAME) 3 3 1

ex1: $(NAME)
	echo "\033[0;35m[./$(NAME) 3 3 0]\033[0m"
	./$(NAME) 3 3 0
	echo "\033[0;35m[./$(NAME) 3 3 1]\033[0m"
	./$(NAME) 3 3 1
	echo "\033[0;35m[./$(NAME) 3 3 2]\033[0m"
	./$(NAME) 3 3 2

ex2: $(NAME)
	echo "\033[0;35m[./$(NAME) 5 5 0]\033[0m"
	./$(NAME) 5 5 0
	echo "\033[0;35m[./$(NAME) 5 5 1]\033[0m"
	./$(NAME) 5 5 1
	echo "\033[0;35m[./$(NAME) 5 5 2]\033[0m"
	./$(NAME) 5 5 2
	echo "\033[0;35m[./$(NAME) 5 5 3]\033[0m"
	./$(NAME) 5 5 3
	echo "\033[0;35m[./$(NAME) 5 5 4]\033[0m"
	./$(NAME) 5 5 4
	echo "\033[0;35m[./$(NAME) 5 5 5]\033[0m"
	./$(NAME) 5 5 5

gg: $(NAME)
	gdb -args ./$(NAME) 3 3 1

.PHONY: all clean fclean re val ex1 ex2
.SILENT: clean fclean re val ex1 ex2 $(NAME) $(OBJ) $(OBJ_DIR) 