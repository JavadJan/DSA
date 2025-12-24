CC = c++ -Wall -Wextra -Werror -Iinclude

H = include/

HEADER = $(H)Tree.hpp

SRC_F = src/
OBJ_F = obj/

NAME = tree

SRC = main.cpp

OBJ = $(SRC:.cpp=.o)
OBJ_P = $(addprefix $(OBJ_F), $(OBJ))

all: $(NAME)

$(NAME) : $(OBJ_P)
	$(CC) $(OBJ_P) -o $(NAME)
	@sleep 2.2
	@echo "\033[1;32mcreate successfully : ✅\033[0m"



$(OBJ_F)%.o :$(SRC_F)%.cpp $(HEADER) | $(OBJ_F)
	$(CC) -c $< -o $@
	@echo "create successfully : $@"


$(OBJ_F): 
	@mkdir -p $(OBJ_F)


clean:
	rm -rf $(OBJ_P)

fclean: clean 
	rm -rf $(NAME)

re : fclean $(NAME)

.PHONY: all clean fclean re


