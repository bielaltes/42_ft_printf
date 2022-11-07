CC=gcc
NAME=libftprintf.a
CFLAGS=-Wall -Wextra -Werror
INC = ft_printf.h
LIB = ar rcs

SRC =	SRC/ft_itoa.c		\
		SRC/ft_printf.c		\
		SRC/ft_htoa.c		\
		SRC/ft_ptoa.c		\
		SRC/ft_printstr.c	\
		SRC/ft_uitoa.c		\
		SRC/ft_printchar.c

SRC_BNS =	SRC_BONUS/ft_itoa_bonus.c		\
		SRC_BONUS/ft_printf_bonus.c			\
		SRC_BONUS/ft_htoa_bonus.c			\
		SRC_BONUS/ft_ptoa_bonus.c			\
		SRC_BONUS/ft_printstr_bonus.c		\
		SRC_BONUS/ft_uitoa_bonus.c			\
		SRC_BONUS/ft_printchar_bonus.c

OBJ=$(SRC:.c=.o)

OBJ_BNS=$(SRC_BNS:.c=.o)

all: $(NAME)

%.o:%.c $(INC)
	@echo "Compilant $@" 
	@$(CC) $(CFLAGS) -c -I $(INC) $< -o $@

$(NAME): $(OBJ)
	@echo "Creant $@"
	@$(LIB) $(NAME) $(OBJ)

bonus: $(OBJ_BNS)
	@echo "Creant $@"
	@$(LIB) $(NAME) $(OBJ_BNS)

clean:
	rm -f $(OBJ) $(OBJ_BNS)

fclean: clean
	rm -f $(NAME)

re: fclean all	

.PHONY: clean fclean all re bonus
