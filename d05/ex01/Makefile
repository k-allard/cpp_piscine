NAME = d05_ex01

SRCS = *.cpp

OBJS = $(SRCS:.cpp=.o)

FLAGS =-std=c++98 -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@clang++ -o $(NAME) $(SRCS) $(FLAGS)
	@echo "\x1b[32m ./d05_ex01 is ready!\x1b[0m"

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY:	all clean fclean re