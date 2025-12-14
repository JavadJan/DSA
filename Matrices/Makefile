CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic -Iinclude

H = include/
HEADER = $(H)Matrices.hpp\
		$(H)LTraingelMatrix.hpp\
		$(H)Diagonal.hpp

SRC_F = src/

SRC = Matrices.cpp main.cpp LTraingleMatrix.cpp
OBJ_F = obj/

NAME = matrix
SPARSE = sparse


OBJ = $(SRC:.cpp=.o)

OBJ_P = $(addprefix $(OBJ_F), $(OBJ))


all: $(NAME) $(SPARSE)

$(NAME) : $(OBJ_P) $(HEADER)
	$(CC) $(FLAGS) $(OBJ_P) -o $(NAME)
	@echo "Successfully created ✅"


$(OBJ_F)%.o:$(SRC_F)%.cpp | $(OBJ_F) # if it was not exist, create folder
	$(CC) $(FLAGS) -c $< -o $@
	@echo "objects created successfully ✅!"


$(OBJ_F): 
	@mkdir -p $(OBJ_F)

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~SPARSE ~~~~~~~~~~~~~~~~~~~~~~~~#
#                                                            #
#                                                            #
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
SRC_S = main.c

SRC_SF = src_s/

OBJ_SF = obj_s/


OBJ_S = $(SRC_S:.c=.o)

OBJ_SP = $(addprefix $(OBJ_SF), $(OBJ_S))

$(SPARSE) : $(OBJ_SP)
	$(CC) $(FLAGS) $(OBJ_SP) -o $(SPARSE)
	@echo "Successfully sparse created ✅"

$(OBJ_SF)%.o:$(SRC_SF)%.c | $(OBJ_SF) # if it was not exist, create folder
	$(CC) $(FLAGS) -c $< -o $@
	@echo "objects created c successfully ✅!"
$(OBJ_SF): 
	@mkdir -p $(OBJ_SF)
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~SPARSE ~~~~~~~~~~~~~~~~~~~~~~~~#
#                                                            #
#                                                            #
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#

clean:
	rm -rf $(OBJ_P)

fclean: clean 
	rm -rf $(NAME)

re : fclean $(NAME)

.PHONY: all clean fclean re

