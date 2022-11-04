#include "ft_printf.h"

static void	ft_putnbr(t_flags flags, unsigned int nb, int *error, int *aux) 
{
	if (nb >= 10) {
		ft_putnbr(flags, nb / 10, error, aux);
		nb = nb % 10;
	}
	if (nb < 10) 
	{
		ft_printchar(flags, nb + 48, error);
		(*aux)++;
	}
}

int ft_uitoa(t_flags flags, unsigned int c, int *error)
{
    int aux;

	aux = 0;
    ft_putnbr(flags, c, error, &aux);
    return (aux);
}