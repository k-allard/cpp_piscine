NAME = megaphone

SRCS = main.cpp Megaphone.cpp

OBJS = $(SRCS:.cpp=.o)

FLAGS =-Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@clang++ -o $(NAME) $(SRCS) $(FLAGS)
	@echo "\x1b[32m ./megaphone is ready!\x1b[0m"

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY:	all clean fclean re