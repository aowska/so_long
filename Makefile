NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -c -o
SRC = ft_printf.c ft_pointer_hex.c ft_lower_hex.c ft_itoa_dec.c ft_itoa_unsign.c ft_putchar_fd.c \
ft_upper_hex.c ft_char.c ft_string.c ft_strlen.c ft_char_word.c ft_putstr_fd.c ft_strdup.c \
ft_char_procent.c
	
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
