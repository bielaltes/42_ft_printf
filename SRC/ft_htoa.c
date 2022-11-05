/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baltes-g <baltes-g@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 12:11:42 by baltes-g          #+#    #+#             */
/*   Updated: 2022/11/05 14:31:23 by baltes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	ft_putnbr(t_flags *flags, unsigned int nb, int *error, char *base)
{
	if (nb >= 16)
	{
		ft_putnbr(flags, nb / 16, error, base);
		nb = nb % 16;
	}
	if (nb < 16)
	{
		if (*error == 1)
			return ;
		(*flags).aux += ft_printchar(*flags, base[nb], error);
		if (*error == 1)
			return ;
	}
}

int	ft_htoa(t_flags flags, unsigned int c, int *error, int maj)
{
	flags.aux = 0;
	if (!maj)
		ft_putnbr(&flags, c, error, "0123456789abcdef");
	else
		ft_putnbr(&flags, c, error, "0123456789ABCDEF");
	return (flags.aux);
}
