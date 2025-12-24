CC = c++ 
FLAGS = -Wall -Wextra -Werror -Iinclude

H = include/

HEADER = $(H)Config.hpp

NAME = config


SRC_F = src/
OBJ_F = obj/

SRC = main.cpp Config.cpp


OBJ = $(SRC:.cpp=.o)

OBJ_P = $(addprefix $(OBJ_F), $(OBJ))

all: $(NAME)

$(NAME) : $(OBJ_P)
	$(CC) $(FLAGS) $(OBJ_P) -o $(NAME)
	@echo "create successfully $(NAME)"

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