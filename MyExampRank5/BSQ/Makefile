CC = gcc
FLAGS = -Wall -Werror -Wextra 
NAME = bsq

HEADER = bsq.h
SRC_F = src/

SRC = main.c

OBJ = $(SRC:.c=.o)

OBJ_F = obj/

all : $(NAME)

OBJ_P = $(addprefix $(OBJ_F), $(OBJ))

$(NAME) : $(OBJ_P)
	$(CC) $(FLAGS) $(OBJ_P) -o $(NAME)
	@echo "successfully create ✅🔨"
# Compile rule for object files:
# - Target pattern: $(OBJ_F)%.o
# - Builds from: $(SRC_F)%.c with additional dependency $(HEADER)
# - Order-only prerequisite: | $(OBJ_F) ensures the object directory exists before compiling
# - Recipe: runs $(CC) $(FLAGS) -c $< -o $@ to compile the source ($<) into the object ($@)
# - Post-action: echoes a success message indicating the created object file
# Notes:
# - $< is the first prerequisite (source file), $@ is the target (object file)
# - Using an order-only prerequisite prevents directory creation from triggering recompilation
$(OBJ_F)%.o :$(SRC_F)%.c $(HEADER) | $(OBJ_F)
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