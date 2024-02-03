NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror -c -o
SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_strcpy.c ft_isalnum.c ft_isalpha.c \
	ft_strlcat.c ft_strcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c \
	ft_isascii.c ft_isdigit.c ft_isprint.c ft_toupper.c ft_memchr.c \
	ft_strchr.c ft_strdup.c ft_strdup.c ft_striteri.c ft_strjoin.c \
	ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
	ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c \
	ft_strnstr.c ft_strtrim.c ft_substr.c ft_tolower.c  ft_itoa.c ft_strrchr.c \
	ft_strmapi.c ft_striteri.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	ft_strcmp.c ft_printf.c ft_pointer_hex.c ft_lower_hex.c ft_itoa_dec.c \
	ft_itoa_unsign.c ft_putchar_fd.c ft_upper_hex.c ft_char.c ft_string.c \
	ft_char_word.c ft_putstr_fd2.c \
ft_char_procent.c
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


