CC=cc -Wall -Wextra -Werror
NAME=libftprintf.a
CFLAGS=-Wall -Wextra -Werror
OPTIONS=-c -I.
SRC=	ft_print%.c			\	
		ft_printchar.c		\	
		ft_printdec.c		\	
		ft_printf.c			\	
		ft_printhexmaj.c	\	
		ft_printhexmin.c	\	
		ft_printpointer.c	\	
		ft_printstr.c		\	
		ft_printunsigned.c

OBJ=$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar -crs $(NAME) $(OBJ)

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) $(OPTIONS) $(SRC)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all	

.PHONY: clean fclean all re
