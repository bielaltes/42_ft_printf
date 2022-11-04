CC=gcc
NAME=libftprintf.a
CFLAGS=-Wall -Wextra -Werror
OPTIONS=-c -I
INC = ft_printf.h
LIB = ar rcs

SRC =	ft_itoa.c		\
		ft_printf.c		\
		ft_htoa.c		\
		ft_ptoa.c		\
		ft_printstr.c	\
		ft_uitoa.c		\
		ft_printchar.c

OBJ=$(SRC:.c=.o)

all: $(NAME)

%.o:%.c
	@echo "Compilant $@" 
	@$(CC) $(CFLAGS) -c  $< -o $@

$(NAME): $(OBJ) $(INC)
	@echo "Creant $@"
	@$(LIB) $(NAME) $(OBJ)


clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all	

.PHONY: clean fclean all re
