CC = c++

# c++ compiler option
FLAG = -Wall -Wextra -Werror -std=c++98

#linker option
LDFLAGS =

#target
NAME = repetitive

#source file directory
SRC_DIR = .

#object file directory
OBJ_DIR = .

#source files
SRCS = $(notdir $(wildcard $(SRC_DIR)/*.cpp))

#object files
OBJS = $(SRCS:.cpp=.o)

#put path to creating object files
OBJECTS = $(patsubst %.o,$(OBJ_DIR)/%.o,$(OBJS))

#dependancy files
DEPS = $(OBJECTS:.o=.d)

all : $(NAME)

$(NAME) : $(OBJECTS)
	@echo "creating $(NAME)"
	@$(CC) $(FLAG) $(OBJECTS) -o $@ $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@$(CC) $(FLAG) -c $< -o $@ -MD $(LDFLAGS)

.PHONY: clean fclean re
clean :
	@echo "removing .o & .d files"
	@rm -rf $(OBJECTS) $(DEPS)

fclean : clean
	@echo "removing $(NAME)"
	@rm -rf $(NAME)

re : fclean all

-include $(DEPS)
