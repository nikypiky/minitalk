NAME = libminitalk

SRCS_UTILS :=	write_PID \
				miniatoi

SRCS_EXEC  :=	client \
				server \
				test\

CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g3

OBJS_UTILS  = $(addprefix utils/, $(SRCS_UTILS:=.o))
OBJS_EXEC   = $(SRCS_EXEC:=.o)

# Include directory for utils
INC_DIRS    =	-I./utils \
				-I./include

VPATH       = utils

.PHONY: all clean fclean re run

all: $(NAME).a $(SRCS_EXEC)

$(NAME).a: $(OBJS_UTILS)
	@ar rcs $@ $^

# Generic rule to compile .c files into .o files
%.o: %.c
	@$(CC) $(CFLAGS) $(INC_DIRS) -c $< -o $@

# Rule for executable files
$(SRCS_EXEC): % : %.o $(NAME).a
	@$(CC) $(CFLAGS) $< -L. -l:$(NAME).a -o $@

clean:
	@rm -f $(OBJS_UTILS) $(OBJS_EXEC)

fclean: clean
	@rm -f $(NAME).a $(SRCS_EXEC)

re: fclean all

run: all
	@./client
	@./server
