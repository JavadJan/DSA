CC = c++
FLAGS = -Wall -Wextra -Werror -Iinclude

NAME = Queue

HEADER = include/Queue.hpp


SRC_F = src/

SRC = main.cpp #Queue.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

OBJ_F = obj/

OBJ_P = $(addprefix $(OBJ_F), $(OBJ))

$(NAME) : $(OBJ_P) $(HEADER)
	$(CC) $(FLAGS) $(OBJ_P) -o $(NAME)
	@echo "successfully create ✅🔨"

$(OBJ_F)%.o :$(SRC_F)%.cpp $(HEADER) | $(OBJ_F)
	$(CC) $(FLAGS) -c $< -o $@
	@echo "create successfully : $@"

$(OBJ_F): 
	@mkdir -p $(OBJ_F)


clean:
	rm -rf $(OBJ_P)

fclean: clean 
	rm -rf $(NAME)

re : fclean $(NAME)

.PHONY: all clean fclean re
