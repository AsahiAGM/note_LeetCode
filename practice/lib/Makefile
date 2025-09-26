NAME = testlib.a
SRCS = $(wildcard __*.c)
OBJS = $(SRCS:.c=.o)
GCC = gcc -g -Wall -Wextra -Werror
VALG = valgrind --leak-check=full

PHONY = all clean fclean re

%.o: %.c
	$(GCC) -c $< -o $@ 

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS) 

all: $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all