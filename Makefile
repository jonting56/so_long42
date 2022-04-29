NAME = solong
CC = gcc
CFLAGS = -Wall -Werror -Wextra -Iheaders

PRINTF_A = printf/libftprintf.a

LIBX = libmlx.dylib

RM = rm -f

SRCS = srcs/*.c

CHECKER = tester/checker.c

GET_NEXT_LINE = gnl/get_next_line.c gnl/get_next_line_utils.c

REMOVE_MESSAGE = echo "removing object files"
REMOVE_ARCHIVE = echo "removing archives and application"
COMPILE_PRINTF = echo "compiling printf archive..."
COMPILE_SOLONG = echo "compiling solong application"
COMPILE_COMPLETE = echo "Ready! To play the game:\n./solong maps/<map name>"

all: $(NAME)

$(NAME):
	@$(COMPILE_PRINTF)
	@$(MAKE) -C ./printf >/dev/null
	@$(COMPILE_SOLONG)
	@$(CC) $(CFLAGS) $(SRCS) $(PRINTF_A) $(GET_NEXT_LINE) $(LIBX) -D BUFFER_SIZE=100 -o $(NAME) >/dev/null
	@$(COMPILE_COMPLETE)

bonus: all

clean:
	@$(REMOVE_MESSAGE)
	@$(MAKE) clean -C ./printf >/dev/null
	@$(MAKE) clean -C ./printf/libft >/dev/null

fclean: clean
	@$(REMOVE_ARCHIVE)
	@$(MAKE) fclean -C ./printf >/dev/null
	@$(MAKE) clean -C ./printf/libft >/dev/null
	@$(RM) $(NAME) >/dev/null

re: fclean all

.PHONY: all clean fclean bonus re