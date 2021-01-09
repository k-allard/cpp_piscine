NAME = robot4

SRCS = main.cpp FragTrap.cpp ScavTrap.cpp ClapTrap.cpp NinjaTrap.cpp

OBJS = $(SRCS:.cpp=.o)

FLAGS =-Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@clang++ -o $(NAME) $(SRCS) $(FLAGS)
	@echo "\x1b[32m ./robot4 is ready!\x1b[0m"

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY:	all clean fclean re