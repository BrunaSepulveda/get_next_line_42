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

.PHONY: all clean fclean re test run rrun run_stdin rstdin

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c get_next_line.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(EXEC): $(NAME) $(TEST_OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) $(TEST_OBJ) $(NAME) -o $(EXEC)

test: $(EXEC)

ARGS ?=
run: $(EXEC)
	./$(EXEC) $(ARGS)

run_stdin: $(EXEC)
	@echo "Digite texto (Ctrl+D para encerrar):"
	./$(EXEC)

rrun:
	$(MAKE) re
	$(MAKE) test
	$(MAKE) run ARGS=$(ARGS)
	$(MAKE) fclean

rstdin:
	$(MAKE) re
	$(MAKE) test
	$(MAKE) run_stdin
	$(MAKE) fclean

clean:
	rm -f $(OBJ) $(TEST_OBJ)

fclean: clean
	rm -f $(NAME) $(EXEC)

re: fclean all
