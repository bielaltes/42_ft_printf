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
	if (str[*i] == 'c')
		return (ft_printchar(flags, args, error));
	else if (str[*i] == 's')
		return (ft_printstr(flags, args, error));
	else if (str[*i] == 'p')
		return (ft_printpointer(flags, args, error));
	else if (str[*i] == 'd')
		return (ft_printdec(flags, args, error));
	else if (str[*i] == 'i')
		return (ft_printint(flags, args, error));
	else if (str[*i] == 'u')
		return (ft_printunsigned(flags, args, error));
	else if (str[*i] == 'x')
		return (ft_printhexmin(flags, args, error));
	else if (str[*i] == 'X')
		return (ft_printhexmaj(flags, args, error));
	else if (str[*i] == '%')
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
