#include "ft_printf.h"


static void	ft_putnbr(t_flags flags, unsigned int nb, int *error, int *aux, char *base)
{
	if (nb >= 16) 
	{
		ft_putnbr(flags, nb / 16, error, aux, base);
		nb = nb % 16;
	}
	if (nb < 16) 
	{
		if (*error == 1)
			return ;
		*aux += ft_printchar(flags, base[nb], error);
		if (*error == 1)
			return ;
	}
}

int ft_htoa(t_flags flags, unsigned int c, int *error, int maj)
{
    int aux;

	aux = 0;
    if (!maj)
        ft_putnbr(flags, c, error, &aux, "0123456789abcdef");
    else
        ft_putnbr(flags, c, error, &aux, "0123456789ABCDEF");
    return (aux);
}