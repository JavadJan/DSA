CC = c++
FALGS = -Wall -Wextra -Werror -std=c++98

HEADER = includes/Graph.hpp

NAME = graph
SRC_F = srcs/

SRC = main.cpp

all: $(NAME)

OBJ_F = obj/

OBJ = $(SRC:.cpp=.o)

# path of the objects
OBJ_PATH = $(addprefix $(OBJ_F), $(OBJ))

# create a vriable that resolve the path for every oject

$(NAME) : $(OBJ_PATH)
	$(CC) $(FLAGS) $(OBJ_PATH) -o $(NAME)
	@echo "create exe $(NAME) successfully"


$(OBJ_F)%.o : $(SRC_F)%.cpp $(HEADER) | $(OBJ_F)
	$(CC) -c $< -o $@
		@echo "create successfully : $@"

# create obj folder if does not exist

$(OBJ_F): 
	@mkdir -p $(OBJ_F)




clean:
	rm -rf $(OBJ_F)

fclean: clean 
	rm -rf $(NAME)

re : fclean $(NAME)

.PHONY: all clean fclean re