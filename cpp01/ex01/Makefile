CC = c++
FLAG = -Wall -Wextra -Werror -std=c++98

NAME = Moar

SRC = main.cpp Zombie.cpp zombieHorde.cpp

OBJ = $(SRC:.cpp=.o)

DEP = $(OBJ:.o=.d)

all : $(NAME)

$(NAME) : $(OBJ)
	@echo "creating $(NAME)"
	@$(CC) $(FLAG) -o $(NAME) $(OBJ)

%.o: %.cpp
	@$(CC) $(FLAG) -c $< -o $@ -MD

.PHONY: clean fclean re
clean : 
	@echo "removing .o & .d files"
	@rm -rf $(OBJ) $(DEP)

fclean : clean
	@echo "removing $(NAME)"
	@rm -rf $(NAME)

re : fclean all

-include $(DEP)
