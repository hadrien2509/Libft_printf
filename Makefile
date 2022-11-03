NAME = libftprintf.a

BASE = ft_printf_tools.c \
       ft_printf.c \

CC = gcc
FLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f
OBJS = ${BASE:.c=.o}

.c.o:
	$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
	$(AR) ${NAME} ${OBJS}

all: ${NAME}

clean:
		${RM} ${OBJS}

fclean: clean
		${RM} ${NAME}

re: fclean all

norm:
	@norminette -R CheckDefine

.PHONY: all clean fclean re norm