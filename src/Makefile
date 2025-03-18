# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBS = -lreadline

# Source files
SRCS = main.c

# Object files
OBJS = $(SRCS:.c=.o)

# Executable
NAME = minishell

# Rules
all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBS)
	@echo "$(NAME) created"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled $<"

clean:
	@rm -f $(OBJS)
	@echo "Cleaned up object files"

fclean: clean
	@rm -f $(NAME)
	@echo "Cleaned up executable and libraries"

re: fclean all

.PHONY: all clean fclean re
