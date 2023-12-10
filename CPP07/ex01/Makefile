NAME = iter
SRCS =	main.cpp
HEADER_FILES = iter.hpp
OBJ_FILES = $(patsubst %.cpp, %.o, $(SRCS))
CPPFLAGS = -Wall -Werror -Wextra -std=c++98
CC = c++

all: $(NAME)

$(NAME): $(OBJ_FILES)
	@echo Assembling $(NAME)
	@$(CC) -o $@ $^ $(CFLAGS)
	@echo $(NAME) has been made!

%.o: %.c
	@$(CC) $(HEADER_FILES) -c $(CFLAGS) -o $@ $<

clean:
	@echo Cleaning all object files 
	@rm -f *.o

fclean: clean
	@echo Removing $(NAME)
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
