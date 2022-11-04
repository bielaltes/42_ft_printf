/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baltes-g <baltes-g@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 16:25:27 by baltes-g          #+#    #+#             */
/*   Updated: 2022/11/04 17:06:25 by baltes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "ft_printf.h"


static void	ft_putnbr(t_flags flags, int nb, int *error, int *aux)
{
	if (nb < 0) {
		ft_printchar(flags, '-', error);
		(*aux)++;
		nb = -nb;
	}
	if (nb >= 10) 
	{
		ft_putnbr(flags, nb / 10, error, aux);
		nb = nb % 10;
	}
	if (nb < 10) 
	{
		ft_printchar(flags, nb + 48, error);
		(*aux)++;
	}
}

int ft_itoa(t_flags flags, int c, int *error)
{
    int aux;

	aux = 0;
	if (c == -2147483648)
		return (ft_printstr(flags, "-2147483648", error));
    ft_putnbr(flags, c, error, &aux);
    return (aux);
}
