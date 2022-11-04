/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baltes-g <baltes-g@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 15:14:22 by baltes-g          #+#    #+#             */
/*   Updated: 2022/09/30 15:10:05 by baltes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

/*static t_flags getflags(char const *str, int *i)
{

}*/

static int	ft_parse_type(char const *str, va_list args, int *i, int *error)
{
	t_flags flags;
	int aux;

	//flags = getflags(str, i);
	aux = *i;
	++(*i);
	if (str[aux] == 'c')
		return (ft_printchar(flags, va_args(args, int), error));
	else if (str[aux] == 's')
		return (ft_printstr(flags, va_args(args, char *), error));
	else if :wq(str[aux] == 'p')
		return (ft_printpointer(flags, va_args(args, void *), error));
	else if (str[aux] == 'd')
		return (ft_printdec(flags, va_args(args, int), error));
	else if (str[aux] == 'i')
		return (ft_printint(flags, va_args(args, int), error));
	else if (str[aux] == 'u')
		return (ft_printunsigned(flags, va_args(args, unsigned int), error));
	else if (str[aux] == 'x')
		return (ft_printhexmin(flags, va_args(args, unsigned int), error));
	else if (str[aux] == 'X')
		return (ft_printhexmaj(flags, va_args(args, unsigned int), error));
	else if (str[aux] == '%')
		return (ft_print%(error));
	write(1, "incomplete format specifier\n", 28);	
}

static int	ft_printvar(char const *str, va_list args, int *i, int *error)
{
	if (str[*i] == '%' && str[*(i+1)])
	{
		(*i)++;
		return (ft_parse_type(str, args, i, error));
	}
	else if (str[*i] != '%')
	{
		write(1, &str[*i], 1);
		(*i)++;
		return (1);
	}
	else
	{
		*error = 1;
		write(1, "incomplete format specifier\n", 28);
		return (0);
	}	
}

int ft_printf(char const *str, ...)
{
	va_list	args;
	int 	i;
	int 	error;
	int		sum;

	error = 0;
	i = 0;
    sum = 0;
	va_start(args, str);
	while (str[i] && !error)
		sum += ft_printvar(str, args, &i, &error);
	va_end(args);
	if (error)
		return (-1);
	return (sum);
}

int	main(int argc, char **argv)
{
	printf("%d", ft_printf("Hola\n"));
}
