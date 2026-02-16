# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: codespace <codespace@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/03 13:51:39 by tabading          #+#    #+#              #
#    Updated: 2025/08/10 13:30:39 by codespace        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq

SRC_P = main \
		initi \
        helper

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
	valgrind --leak-check=full ./$(NAME) maps/ex 

val1: $(NAME)
	cat maps/ex | valgrind --leak-check=full ./$(NAME)

ex: $(NAME)
	./$(NAME) maps/ex

ex1: $(NAME)
	cat maps/ex | ./$(NAME)

gg: $(NAME)
	gdb -args ./$(NAME) maps/ex

m: $(NAME)
	echo "\033[1;36m[Test Error handling: Map given]\033[0m"
	echo "\033[0;35m[First line missing]\033[0m"
	./$(NAME) maps/err
	echo "\033[0;35m[First line extra val]\033[0m"
	./$(NAME) maps/err1
	echo "\033[0;35m[First line missing val]\033[0m"
	./$(NAME) maps/err2
	echo "\033[0;35m[First line double val]\033[0m"
	./$(NAME) maps/err3
	echo "\033[0;35m[First line no number]\033[0m"
	./$(NAME) maps/err4
	echo "\033[0;35m[Line Length, first line]\033[0m"
	./$(NAME) maps/err5
	echo "\033[0;35m[Line Length, middle line]\033[0m"
	./$(NAME) maps/err6
	echo "\033[0;35m[Line Length, last line]\033[0m"
	./$(NAME) maps/err7
	echo "\033[0;35m[no newline]\033[0m"
	./$(NAME) maps/err8
	echo "\033[0;35m[no lines]\033[0m"
	./$(NAME) maps/err10
	echo "\033[0;35m[no cells]\033[0m"
	./$(NAME) maps/err11
	echo "\033[0;35m[wrong char in map]\033[0m"
	./$(NAME) maps/err12
	echo "\033[0;35m[PROB EXTRA: given linecount bigger than map]\033[0m"
	./$(NAME) maps/err9

mv: $(NAME)
	echo "\033[1;36m[Test Error handling: valgrind]\033[0m"
	echo "\033[0;35m[First line missing]\033[0m"
	valgrind --leak-check=full ./$(NAME) maps/err
	echo "\033[0;35m[First line extra val]\033[0m"
	valgrind --leak-check=full ./$(NAME) maps/err1
	echo "\033[0;35m[First line missing val]\033[0m"
	valgrind --leak-check=full ./$(NAME) maps/err2
	echo "\033[0;35m[First line double val]\033[0m"
	valgrind --leak-check=full ./$(NAME) maps/err3
	echo "\033[0;35m[First line no number]\033[0m"
	valgrind --leak-check=full ./$(NAME) maps/err4
	echo "\033[0;35m[Line Length, first line]\033[0m"
	valgrind --leak-check=full ./$(NAME) maps/err5
	echo "\033[0;35m[Line Length, middle line]\033[0m"
	valgrind --leak-check=full ./$(NAME) maps/err6
	echo "\033[0;35m[Line Length, last line]\033[0m"
	valgrind --leak-check=full ./$(NAME) maps/err7
	echo "\033[0;35m[no newline]\033[0m"
	valgrind --leak-check=full ./$(NAME) maps/err8
	echo "\033[0;35m[no lines]\033[0m"
	valgrind --leak-check=full ./$(NAME) maps/err10
	echo "\033[0;35m[no cells]\033[0m"
	valgrind --leak-check=full ./$(NAME) maps/err11
	echo "\033[0;35m[wrong char in map]\033[0m"
	valgrind --leak-check=full ./$(NAME) maps/err12
	echo "\033[0;35m[PROB EXTRA: given linecount bigger than map]\033[0m"
	valgrind --leak-check=full ./$(NAME) maps/err9


.PHONY: all clean fclean re val val1 ex ex1 gg m mv
.SILENT: clean fclean re val val1 ex ex1 gg m mv $(NAME) $(OBJ) $(OBJ_DIR) 