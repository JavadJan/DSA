CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

NAME = polyset

OBJ_F = obj/
HF = includes/

HEADER = $(HF)bag.hpp \
			$(HF)array_bag.hpp\
			$(HF)tree_bag.hpp \
			$(HF)searchable_bag.hpp \
			$(HF)searchable_tree_bag.hpp \
			$(HF)searchable_array_bag.hpp \
			$(HF)set.hpp \

SRC_F = src/

SRC = main.cpp bag.cpp searchable_bag.cpp array_bag.cpp tree_bag.cpp searchable_tree_bag.cpp set.cpp searchable_array_bag.cpp

all : $(NAME)

OBJ = $(SRC:.cpp=.o)

#SRC_LIST = $(addprefix $(SRC_F), $(SRC))

# OBJ_P is a variable that expands to a list of object file paths.
# It uses the 'addprefix' function to prepend the value of OBJ_F (the object file directory or prefix)
# to each item in OBJ (the list of object file names), resulting in full paths for each object file.

OBJ_P = $(addprefix $(OBJ_F), $(OBJ))

# This rule builds the final executable $(NAME) from the object files listed in $(OBJ_P).
# It uses the compiler $(CC) with the specified $(FLAGS).
# Upon successful creation, it prints a confirmation message.
$(NAME) : $(OBJ_P)
	$(CC) $(FLAGS) $(OBJ_P) -o $(NAME)
	@echo "created successfully: $@ ✅"

# This pattern rule compiles each .cpp source file from $(SRC_F) into a corresponding .o object file in $(OBJ_F).
# The object files are placed in the $(OBJ_F) directory, which is created if it does not exist (order-only prerequisite).
$(OBJ_F)%.o : $(SRC_F)%.cpp $(HEADER) | $(OBJ_F) # ./obj/*.o : ./src/*.cpp
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