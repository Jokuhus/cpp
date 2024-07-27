CC = c++
FLAG = -Wall -Wextra -Werror -std=c++98

NAME = account

SRC = tests.cpp Account.cpp

all : $(NAME)

$(NAME) : $(SRC)
	@echo "creating $(NAME)"
	@$(CC) $(FLAG) -o $(NAME) $(SRC)

clean : 
	@echo "removing $(NAME)"
	@rm -rf $(NAME)

fclean : clean

re : fclean $(NAME)
