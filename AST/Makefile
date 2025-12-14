CC = cc
FLAGS = -Wall -Wextra -Werror -I.
HEADER = ast.h

SRC = ast.c

OBJ = $(SRC:.c=.o)

NAME =ast

all: $(NAME)

$(NAME) : $(OBJ) $(HEADER)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)
	@echo "creat successfully: $(NAME)"

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all re fclean clean
