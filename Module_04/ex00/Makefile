NAME = ex00

SRC = main.cpp Animal.cpp Dog.cpp Cat.cpp WrongAnimal.cpp WrongCat.cpp

OBJ = $(SRC:.cpp=.o)

CC = c++ -Wall -Wextra -Werror -std=c++98

all: $(NAME)

%.o: %.cpp
	$(CC) -c $^ -o $@

$(NAME): $(OBJ)
	@echo "\nCompiling --->"
	@$(CC) $(OBJ) -o $(NAME)
	@echo "Done\n"

fclean: 		
	@rm -rf $(NAME)
	@rm -rf $(OBJ)
	@echo "\nRemoved all files\n"

re: all
	@echo  "\nRemake\n"

.PHONY: all fclean re
