# ========================================================================== #

# <- Color Library -> #

# <-- Text Color --> #
T_BLACK = \033[30m
T_RED = \033[31m
T_GREEN = \033[32m
T_YELLOW = \033[33m
T_BLUE = \033[34m
T_MAGENTA = \033[35m
T_CYAN = \033[36m
T_WHITE = \033[37m

# <-- Text Style --> #
BOLD = \033[1m
ITALIC = \033[3m
UNDERLINE = \033[4m
STRIKETHROUGH = \033[9m

# <-- Background Color --> #
B_BLACK = \033[40m
B_RED = \033[41m
B_GREEN = \033[42m
B_YELLOW = \033[43m
B_BLUE = \033[44m
B_MAGENTA = \033[45m
B_CYAN = \033[46m
B_WHITE = \033[47m

# <-- Reset Everything --> #
RESET = \033[0m

# ========================================================================== #

# <- Library's Name -> #
NAME = gnl.a

# <- Compilation Command -> #
CC = gcc

# <- Compilation Flags -> #
CFLAGS = -Wall -Wextra -Werror

# <- Directories -> #
SRC_DIR = src/
UTILS_DIR = utils/

# <- Files -> #
SRC_FILES = get_next_line.c
UTILS_FILES = get_next_line_utils.c

# <- Directories + Files -> # 
SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
UTILS = $(addprefix $(UTILS_DIR), $(UTILS_FILES))
OBJ_SRC = $(SRC:.c=.o)
OBJ_UTILS = $(UTILS:.c=.o)

# ========================================================================== #

# <- Main Target -> #
all: $(NAME)

# < - Library Creation -> #
$(NAME): $(OBJ_SRC) $(OBJ_UTILS)
	@echo "$(B_GREEN)$(T_YELLOW)$(BOLD)Objects created successfully$(RESET)"
	ar rcs $(NAME) $(OBJ_SRC) $(OBJ_UTILS)
	@echo "$(B_GREEN)$(T_YELLOW)$(BOLD)Library created successfully$(RESET)"

# <- Objects Creation -> #
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# <- Objects Destruction -> #
clean:
	rm -f $(OBJ_SRC)
	@echo "$(B_RED)$(T_YELLOW)$(BOLD)Source Object destroyed successfully$(RESET)"
	rm -f $(OBJ_UTILS)
	@echo "$(B_RED)$(T_YELLOW)$(BOLD)Utils Objects destroyed successfully$(RESET)"

# <- Clean Execution + Library Destruction -> #
fclean: clean
	rm -f $(NAME) ./a.out
	@echo "$(B_RED)$(T_YELLOW)$(BOLD)Library destroyed successfully$(RESET)"

# <- Fclean Execution + All Execution -> #
re: fclean all

# <- test1: Makefile BUFFER_SIZE = 1-> #
test1:
	gcc -g test/main.c src/get_next_line.c utils/get_next_line_utils.c -D BUFFER_SIZE=1
	./a.out test/10line1000chareach

# <- test2: Makefile BUFFER_SIZE = 2-> #
test2:
	gcc -g test/main.c src/get_next_line.c utils/get_next_line_utils.c -D BUFFER_SIZE=2
	./a.out Makefile

# <- test3: Makefile BUFFER_SIZE = 10-> #
test3:
	gcc -g test/main.c src/get_next_line.c utils/get_next_line_utils.c -D BUFFER_SIZE=10
	./a.out Makefile

# <- test4: Makefile BUFFER_SIZE = 100-> #
test4:
	gcc -g test/main.c src/get_next_line.c utils/get_next_line_utils.c -D BUFFER_SIZE=100
	./a.out Makefile

# <- test5: Makefile BUFFER_SIZE = 500-> #
test5:
	gcc -g test/main.c src/get_next_line.c utils/get_next_line_utils.c -D BUFFER_SIZE=500
	./a.out Makefile

# <- test6: Makefile BUFFER_SIZE = 1000-> #
test6:
	gcc -g test/main.c src/get_next_line.c utils/get_next_line_utils.c -D BUFFER_SIZE=1000
	./a.out test/10line1char

# <- Targets Declaration -> #
.PHONY = all clean fclean re test1 test2 test3 test4 test5 test6

# ========================================================================== #
