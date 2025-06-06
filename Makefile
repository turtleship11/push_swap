# 컴파일러 설정
CC = cc
CFLAGS = -Wall -Wextra -Werror -I. -I./ft_printf

# 출력 이름
NAME = push_swap

# 소스 파일
SRCS = main.c ft_atoi.c ft_split.c push_swap.c push_swap_utils.c \
       ft_printf/ft_printf.c ft_printf/ft_printf_utils.c \
       ft_printf/ft_printf_hex.c ft_printf/ft_printf_ptr.c \
       ft_printf/ft_printf_nbr.c ft_printf/ft_printf_un.c

# 오브젝트 파일 자동 생성
OBJS = $(SRCS:.c=.o)

# 빌드 타겟
all: $(NAME)

# 컴파일 규칙
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# 실행 파일 생성
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

# 오브젝트 파일 삭제
clean:
	rm -f $(OBJS)

# 실행 파일 삭제
fclean: clean
	rm -f $(NAME)

# 전체 다시 빌드
re: fclean all
