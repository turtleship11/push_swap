CC = cc
CFLAGS = -Wall -Wextra -Werror -I. -I./ft_printf


NAME = push_swap

SRCS = main.c ft_atoi.c ft_split.c push_swap.c push_swap_utils.c \
       ft_printf/ft_printf.c ft_printf/ft_printf_utils.c \
       ft_printf/ft_printf_hex.c ft_printf/ft_printf_ptr.c \
       ft_printf/ft_printf_nbr.c ft_printf/ft_printf_un.c \
	   quick_sort.c main_help.c pivot.c sort_three.c \

.SECONDARY: $(OBJS)

OBJS = $(SRCS:.c=.o)


all: $(NAME)


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
