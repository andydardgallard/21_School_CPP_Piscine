NAME = fixed

SRC = main.cpp Fixed.cpp

OBJ = $(SRC:.c=.o)

CC = c++ -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(%.o): $(%.c)
				$(CC) -o $@

$(NAME): $(OBJ)
				@echo "\nCompiling --->"
				@$(CC) $(SRC) -o $(NAME)
				@echo "Done\n"

fclean: 		
				@rm -rf $(NAME)
				@echo "\nRemoved all files\n"

re: 			all
				@echo  "\nRemake\n"

.PHONY:			all fclean re