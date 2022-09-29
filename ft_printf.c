/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baltes-g <baltes-g@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 15:14:22 by baltes-g          #+#    #+#             */
/*   Updated: 2022/09/29 18:16:10 by baltes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

int ft_printf(char const *str, ...)
{
	va_list	args;
	int 	i;
	int 	error;
	int		sum;

	error = 1;
	va_start(args, str);
	while (str[i] && error)
	{
		if (str[i] == '%')
		{
			if (0 == ft_printvar())
				error = 1;

		}
		else
		{
			if (0 == fr_printchar())
				error = 1;
			++sum;
			++i;
		}
	}
	va_end(args);
	if (!error)
		return (-1);
	return (sum);
}
