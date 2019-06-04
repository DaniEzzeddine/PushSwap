CC = gcc
CFLAGS = -Wall -Wextra -Werror -I $(IDIR) -g
NAME = ft_ssl
IDIR = ./include
SRCDIR = ./src

_DEPS = libft.h push_swap.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_SRC = main.c commands.c pushStack.c stack.c
SRC = $(patsubst %, $(SRCDIR)/%, $(_SRC))

SRC_OBJ =$(SRC:.c=.o)

OBJ = $(SRC_OBJ)
LIBS = ./include/libft.a

all: $(NAME)

%.o: %.c $(DEPS)
	@echo "\033[0;32m\c"
	$(CC) -c -o $@ $< $(CFLAGS)
	@echo "\033[0m\c"

$(NAME): $(OBJ) $(LIBS)
	@echo "\033[0;35m\c"
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)
	@echo "\033[0m\c"

rsa: $(BASE64_OBJ) $(RSA_OBJ) $(LIBS)
	@echo "\033[0;34m\c"
	$(CC) -o ft_ssl_$@ $^ $(CFLAGS) $(LIBS)
	@echo "\033[0m\c"

base64: $(BASE64_OBJ) $(LIBS)
	@echo "\033[0;34m\c"
	$(CC) -o ft_ssl_$@ $^ $(CFLAGS) $(LIBS)
	@echo "\033[0m\c"

des: $(DES_OBJ) $(LIBS)
	@echo "\033[0;34m\c"
	$(CC) -o ft_ssl_$@ $^ $(CFLAGS) $(LIBS)
	@echo "\033[0m\c"

md5: $(MD5_OBJ) $(LIBS)
	@echo "\033[0;34m\c"
	$(CC) -o ft_ssl_$@ $^ $(CFLAGS) $(LIBS)
	@echo "\033[0m\c"

clean:
	@/bin/rm -f $(OBJ)
	@+$(MAKE) clean -C ./libft

fclean: clean
	@/bin/rm -f $(NAME)
	@+$(MAKE) fclean -C ./libft


re: fclean all

.PHONY: clean fclean re
