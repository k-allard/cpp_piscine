NAME = sorcerer

SRCS = main.cpp Sorcerer.cpp Victim.cpp Peon.cpp Seeker.cpp

OBJS = $(SRCS:.cpp=.o)

FLAGS =-Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@clang++ -o $(NAME) $(SRCS) $(FLAGS)
	@echo "\x1b[32m ./sorcerer is ready! 🔮✨ \x1b[0m"

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY:	all clean fclean re