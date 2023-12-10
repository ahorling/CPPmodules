
############## COLOUR CODES ##########

BOLD	:= \033[1m
BLACK	:= \033[30;1m
RED		:= \033[31;1m
GREEN	:= \033[32;1m
YELLOW	:= \033[33;1m
BLUE	:= \033[34;1m
MAGENTA	:= \033[35;1m
CYAN	:= \033[36;1m
WHITE	:= \033[37;1m
RESET	:= \033[0m

############## CONSTANTS #############

NAME := Scalar
CC := c++
CFLAGS := -Wall -Wextra -Werror -std=c++98 -g

############### SOURCES ##############

SOURCES 	:=	main.cpp \

INCLUDES	:=
				
SOURCE_DIR 	:=	./
OBJECT_DIR	:=	objects
OBJECTS 	:= 	$(addprefix $(OBJECT_DIR)/, $(SOURCES:.cpp=.o))

############### MESSAGES ########

MESSAGE		:=	"Making $(NAME)"
MESSAGE_FIN	:=	"COMPILATION COMPLETE"
MESSAGE_RM	:=	"OBJECTS CLEANED"
MESSAGE_FRM	:=	"EVERYTHING CLEANED"
MESSAGE_LIB	:=	"LIBRARIES READY"

############### RUNNING ##############

all: $(NAME)

$(NAME): $(OBJECTS)
	@echo $(MESSAGE)
	@$(CC) $(CFLAGS) $(INCLUDES) -o $@ $^
	@echo "$(GREEN)$(BOLD)$(MESSAGE_FIN)$(RESET)"

$(OBJECT_DIR)/%.o: $(SOURCE_DIR)/%.cpp
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

run:
	make && ./$(NAME)

clean:
	@rm -f $(OBJECTS)
	@echo "$(RED)$(MESSAGE_RM)$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@if [ -d "$(OBJECT_DIR)" ]; then rm -rf $(OBJECT_DIR); fi
	@echo "$(RED)$(MESSAGE_FRM)$(RESET)"

re: fclean all

.PHONY: all clean fclean re libraries


NAME = scalar
SRCS =	main.cpp
HEADER_FILES =
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
