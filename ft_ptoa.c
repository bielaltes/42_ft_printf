#include "ft_printf.h"


static void	ft_putnbr(t_flags flags, unsigned long long int nb, int *error, int *aux, char *base) 
{
	if (nb >= 16) {
		ft_putnbr(flags, nb / 16, error, aux, base);
		nb = nb % 16;
	}
	if (nb < 16) 
	{
		if (*error == 1)
			return ;
		*aux += ft_printchar(flags, base[nb], error);
		if (*error != 0)
			return ;
	}
}

int ft_ptoa(t_flags flags, unsigned long long int c, int *error)
{
    int aux;

	aux = 0;
	aux += ft_printstr(flags, "0x", error);
	if (*error == 0)
    	ft_putnbr(flags, c, error, &aux, "0123456789abcdef");
    return (aux);
}
