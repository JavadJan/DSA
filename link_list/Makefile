CC = cc
FLAGS = -Wall -Wextra -Werror -Iinclude

H = include/

HEADER = $(H)link_list.h\


SRC_F = src/

SRC = create_new_node.c main.c add_at_end_lst.c last_node.c\
		display.c recursive_display.c count_recursively.c\
		search.c find_max.c sum_element.c insert.c delete.c\
		check_sorted.c delete_dup.c reverse_link.c concatinate.c\
		merge_list.c isLoop.c


OBJ_F = obj/

NAME = link_list


OBJ = $(SRC:.c=.o)

OBJ_P = $(addprefix $(OBJ_F), $(OBJ))


all: $(NAME) $(SPARSE)

$(NAME) : $(OBJ_P) $(HEADER)
	$(CC) $(FLAGS) $(OBJ_P) -o $(NAME)
	@echo "Successfully created ✅"


$(OBJ_F)%.o:$(SRC_F)%.c | $(OBJ_F) # if it was not exist, create folder
	$(CC) $(FLAGS) -c $< -o $@
	@echo "objects created successfully ✅!"


$(OBJ_F): 
	@mkdir -p $(OBJ_F)

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~SPARSE ~~~~~~~~~~~~~~~~~~~~~~~~#
#                                                            #
#                                                            #
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
#SRC_S = main.c

#SRC_SF = src_s/

#OBJ_SF = obj_s/


#OBJ_S = $(SRC_S:.c=.o)

#OBJ_SP = $(addprefix $(OBJ_SF), $(OBJ_S))

#$(SPARSE) : $(OBJ_SP)
#	$(CC) $(FLAGS) $(OBJ_SP) -o $(SPARSE)
#	@echo "Successfully sparse created ✅"

#$(OBJ_SF)%.o:$(SRC_SF)%.c | $(OBJ_SF) # if it was not exist, create folder
#	$(CC) $(FLAGS) -c $< -o $@
#	@echo "objects created c successfully ✅!"
#$(OBJ_SF): 
#	@mkdir -p $(OBJ_SF)
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

