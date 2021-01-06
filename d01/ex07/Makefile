NAME = replace

SRCS = replace.cpp

OBJS = $(SRCS:.cpp=.o)

FLAGS =-Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@clang++ -o $(NAME) $(SRCS) $(FLAGS)
	@echo "hello world i love you" > text.txt
	@echo "hello you world" >> text.txt
	@echo "hello your world" >> text.txt
	@chmod a+rw text.txt
	@echo "\x1b[32m ./replace is ready!\x1b[0m"

test: re
	./replace text.txt you spagetti
clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)
	@rm -rf *.txt
	@rm -rf *.replace

re: fclean all

.PHONY:	all clean fclean re