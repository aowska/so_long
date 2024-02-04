NAME = SO_LONG.ar

CC = cc
CFLAGS = -Wall -Wextra -Werror -c -o
SRC = ft_map.c ft_mlx.c get_next_line.c main.c
	
OBJS = $(SRC:.c=.o) 

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) $@ $<

clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)

re: fclean all
