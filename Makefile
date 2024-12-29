NAME	= so_long

CC      = gcc

CFLAGS  = -Wall -Wextra -Werror -g
LINKS	= -Lmlx -lmlx -framework OpenGL -framework AppKit

SRCS	= $(wildcard game/*.c) $(wildcard utils/*.c) main.c
LIB	= mlx/

OBJS    = $(SRCS:.c=.o)


$(NAME): $(OBJS)
 $(CC) $(CFLAGS) $(OBJS) $(LINKS) -o $(NAME)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

all: $(NAME)
	make -C $(LIB)

RM      = rm -f

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	make clean -C $(LIB)

re: fclean all

.PHONY: all clean fclean re
