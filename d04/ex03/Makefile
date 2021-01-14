NAME = materiaCreator

SRCS = *.cpp

OBJS = $(SRCS:.cpp=.o)

FLAGS =-g -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@clang++ -o $(NAME) $(SRCS) $(FLAGS)
	@echo "\x1b[32m ./materiaCreator is ready! ✨ \x1b[0m"

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY:	all clean fclean re