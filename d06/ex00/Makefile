NAME = convert

SRCS = *.cpp

OBJS = $(SRCS:.cpp=.o)

FLAGS =-g -std=c++98 -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	clang++ -o $(NAME) $(SRCS) $(FLAGS)
	@echo "\x1b[32m ./$(NAME) is ready!\x1b[0m"

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY:	all clean fclean re