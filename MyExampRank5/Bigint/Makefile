CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

NAME = bigint

HEADER = Bigint.hpp


SRC_F = 

SRC = main.cpp Bigint.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

OBJ_F = obj/

OBJ_P = $(addprefix $(OBJ_F), $(OBJ))

$(NAME) : $(OBJ_P) 
	$(CC) $(FLAGS) $(OBJ_P) -o $(NAME)
	@echo "successfully create ✅🔨"

$(OBJ_F)%.o :%.cpp $(HEADER) | $(OBJ_F)
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
