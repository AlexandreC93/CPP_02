NAME		= Fixed
	
CC			= c++
FLAGS		= -Wall -Wextra -Werror
RM			= rm -rf

OBJDIR = .obj

FILES		= Fixed main

SRC			= $(FILES:=.cpp)
OBJ			= $(addprefix $(OBJDIR)/, $(FILES:=.o))
HEADER		= Fixed.hpp

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	@$(CC) $(OBJ) -o $(NAME)
	@printf "Exec ready\n"

$(OBJDIR)/%.o: %.cpp $(HEADER)
	@mkdir -p $(dir $@)
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJDIR) $(OBJ)
	@printf "Objs removed.\n"

fclean: clean
	@$(RM) $(NAME)
	@printf "Exec removed\n"

re: fclean all

.PHONY: all clean fclean re