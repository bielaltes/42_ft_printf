/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baltes-g <baltes-g@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 12:22:31 by baltes-g          #+#    #+#             */
/*   Updated: 2022/11/05 14:31:30 by baltes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_printchar(t_flags flags, int c, int *error)
{
	int	aux;

	if (flags.content)
		aux = 0;
	aux = write(1, &c, 1);
	if (aux == -1)
	{
		*error = 1;
		return (0);
	}
	return (1);
}
