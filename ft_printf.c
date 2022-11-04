/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baltes-g <baltes-g@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 15:14:22 by baltes-g          #+#    #+#             */
/*   Updated: 2022/11/04 17:35:19 by baltes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
		return (ft_printchar(flags, va_arg(args, int), error));
	else if (str[aux] == 's')
		return (ft_printstr(flags, va_arg(args, char *), error));
	else if (str[aux] == 'p')
		return (ft_ptoa(flags, va_arg(args, unsigned long long int), error));
	else if (str[aux] == 'd')
		return (ft_itoa(flags, va_arg(args, int), error));
	else if (str[aux] == 'i')
		return (ft_itoa(flags, va_arg(args, int), error));
	else if (str[aux] == 'u')
		return (ft_uitoa(flags, va_arg(args, unsigned int), error));
	else if (str[aux] == 'x')
		return (ft_htoa(flags, va_arg(args, unsigned int), error, 0));
	else if (str[aux] == 'X')
		return (ft_htoa(flags, va_arg(args, unsigned int), error, 1));
	else if (str[aux] == '%')
		return (ft_printchar(flags, '%', error));
	write(1, "incomplete format specifier\n", 28);
	*error = 1;
	return (-1);
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

/*int	main(void)
{

}*/