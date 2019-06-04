CC = gcc
CFLAGS = -Wall -Wextra -Werror -I $(IDIR) -g
NAME = push_swap
IDIR = ./include
SRCDIR = ./src

_DEPS = libft.h push_swap.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_SRC = main.c commands.c pushStack.c stack.c
SRC = $(patsubst %, $(SRCDIR)/%, $(_SRC))

_CHECKER = checker.c stack.c pushStack.c commands.c
CHECKER = $(patsubst %, $(SRCDIR)/%, $(_CHECKER))
CHECKER_NAME = checker

SRC_OBJ =$(SRC:.c=.o)
CHECKER_OBJ = $(CHECKER:.c=.o)

OBJ = $(SRC_OBJ)
LIBS = ./include/libft.a

all: $(NAME) $(CHECKER_NAME)

%.o: %.c $(DEPS)
	@echo "\033[0;32m\c"
	$(CC) -c -o $@ $< $(CFLAGS)
	@echo "\033[0m\c"

$(NAME): $(OBJ) $(LIBS)
	@echo "\033[0;35m\c"
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)
	@echo "\033[0m\c"

$(CHECKER_NAME): $(CHECKER_OBJ) $(LIBS)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

clean:
	@/bin/rm -f $(OBJ)
	@+$(MAKE) clean -C ./libft

fclean: clean
	@/bin/rm -f $(NAME)
	@+$(MAKE) fclean -C ./libft


re: fclean all

.PHONY: clean fclean re
