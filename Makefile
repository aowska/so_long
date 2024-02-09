NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT = ./Libft/libft.a
SRC = ft_map.c ft_mlx.c get_next_line.c main.c	
INCLUDES = -I/usr/include -Imlx
MLXFLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11

OBJS = $(SRC:.c=.o) 

all: $(NAME)

$(LIBFT):
	$(MAKE) -C ./Libft

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(MLXFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)

clean:
	$(MAKE) clean -C ./Libft
	rm -f $(OBJS)

fclean: clean
	$(MAKE) fclean -C ./Libft
	rm -f $(NAME)

re: fclean all

.PHONY: all check show clean re
