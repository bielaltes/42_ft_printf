/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baltes-g <baltes-g@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 12:40:21 by baltes-g          #+#    #+#             */
/*   Updated: 2022/11/05 14:31:37 by baltes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_printstr(t_flags flags, char *str, int *error)
{
	int	aux;
	int	i;

	aux = 0;
	if (flags.content)
		i = 0;
	i = 0;
	if (!str)
		return (ft_printstr(flags, "(null)", error));
	while (str[i] != '\0' && aux != -1 && *error != 1)
	{
		ft_printchar(flags, str[i], error);
		++i;
	}
	return (i);
}
