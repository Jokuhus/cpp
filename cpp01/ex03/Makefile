CC = c++
FLAG = -Wall -Wextra -Werror -std=c++98

NAME = violence

SRC = main.cpp Weapon.cpp HumanA.cpp HumanB.cpp

OBJ = $(SRC:.cpp=.o)

DEP = $(OBJ:.o=.d)

all : $(NAME)

$(NAME) : $(OBJ)
	@echo "creating $(NAME)"
	@$(CC) $(FLAG) -o $(NAME) $(OBJ)

%.o: %.cpp
	@$(CC) $(FLAG) -c $< -o $@ -MD -I.

.PHONY: clean fclean re
clean : 
	@echo "removing .o & .d files"
	@rm -rf $(OBJ) $(DEP)

fclean : clean
	@echo "removing $(NAME)"
	@rm -rf $(NAME)

re : fclean all

-include $(DEP)
