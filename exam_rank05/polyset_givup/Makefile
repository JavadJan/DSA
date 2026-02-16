# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tabading <tabading@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/03 13:51:39 by tabading          #+#    #+#              #
#    Updated: 2025/07/31 13:34:01 by tabading         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = polyset

SRC_P = main \
		array_bag \
		tree_bag \
		searchable_array_bag \
		searchable_tree_bag \
		set

SRC_DIR	=	
OBJ_DIR	=	obj/

SRC = 		$(addprefix $(SRC_DIR), $(addsuffix .cpp, $(SRC_P)))
OBJ =		$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_P)))

DEP =		$(OBJ:%.o=%.d)

CFLAGS = -Wall -Wextra -Werror -g -std=c++98

CC = g++

all: $(NAME) 

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	echo "\033[0;36m[$(NAME) created]\033[0m"

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp | $(OBJ_DIR)
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
	valgrind --leak-check=full ./$(NAME)

ex: $(NAME)
	./$(NAME) 1 2 3

gg: $(NAME)
	gdb -args ./$(NAME) 1 2 3

.PHONY: all clean fclean re val ex
.SILENT: clean fclean re val ex $(NAME) $(OBJ) $(OBJ_DIR) 