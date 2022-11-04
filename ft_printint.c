#include "libprintf.h"

static int	ft_putnbr(int nb) {
	if (nb < 0) {
		ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10) {
		ft_putnbr(nb / 10);
		nb = nb % 10;
	}
	if (nb < 10) ft_putchar(nb + 48);
}

int ft_printint(t_flags, int c, int *error)
{
    int aux;
    aux = ft_putnbr(c);
    if (aux = -1)
        *error = 1;
    return (1);
}


