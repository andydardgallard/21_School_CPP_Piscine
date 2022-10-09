NAME 		= ex02

CC 			= c++ -Wall -Wextra -Werror -std=c++98

INC_DIR 	= inc/
SRC_DIR 	= src/
OBJ_DIR 	= obj/

SRC_FILES 	= main.cpp Bureaucrat.cpp Form.cpp \
				ShrubberyCreationForm.cpp \
				RobotomyRequestForm.cpp \
				PresidentialPardonForm.cpp

OBJ_FILES 	= $(SRC_FILES:.cpp=.o)

SRC			=	$(addprefix $(SRC_DIR), $(SRC_FILES))
HDR			=	$(addprefix $(INC_DIR), $(HDR_FILES))
OBJ			=	$(addprefix $(OBJ_DIR), $(OBJ_FILES))

all: $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CC) -I $(INC_DIR) -c $< -o $@

$(NAME): $(OBJ)
	@echo "\nCompiling --->"
	@$(CC) $(OBJ) -o $(NAME)
	@echo "Done\n"

fclean: 		
	@rm -rf $(NAME)
	@rm -rf $(OBJ_DIR)
	@echo "\nRemoved all files\n"

re: all
	@echo  "\nRemake\n"

.PHONY: all fclean re
