NAME        = get_next_line.a
EXEC        = get_next_line_test

CC          = cc
CFLAGS      = -Wall -Wextra -Werror
BS          ?= 42
CFLAGS      += -D BUFFER_SIZE=$(BS)

FILES       = get_next_line.c get_next_line_utils.c
OBJ         = $(FILES:.c=.o)

TEST_SRC    = main.c
TEST_OBJ    = $(TEST_SRC:.c=.o)

INCLUDES    = -I.

.PHONY: all clean fclean re test run rrun

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c get_next_line.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(EXEC): $(NAME) $(TEST_OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) $(TEST_OBJ) $(NAME) -o $(EXEC)

test: $(EXEC)

run: $(EXEC)
	./$(EXEC) $(ARGS)

rrun: re
	@$(MAKE) --no-print-directory run

clean:
	rm -f $(OBJ) $(TEST_OBJ)

fclean: clean
	rm -f $(NAME) $(EXEC)

re: fclean all
