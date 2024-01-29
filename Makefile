NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -c -o
SRC = 
	
OBJS = $(SRC:.c=.o) 

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) $@ $<

clean:
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all
