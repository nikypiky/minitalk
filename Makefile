# Files
NAME       = client \
			server

# Compiler and Flags
Compiler   = cc
CmpFlags   = -Wall -Wextra -Werror -g3

# Targets
all: $(NAME) # Build both executables

$(NAME): %: %.c # Pattern rule for building executables
	@$(Compiler) $(CmpFlags) -o $@ $<

clean:
	@rm -f *.o

fclean: clean
	@rm -f $(NAME)

re: fclean all

run: all # Run all executables after building them
	@./client
	@./server

.PHONY: all, clean, fclean, re, run
