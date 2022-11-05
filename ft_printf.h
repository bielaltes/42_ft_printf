/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baltes-g <baltes-g@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 14:08:18 by baltes-g          #+#    #+#             */
/*   Updated: 2022/11/05 13:44:30 by baltes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

typedef struct s_flags
{
	int	content;
	int	space;
	int	hash;
	int	plus;
	int	aux;
}				t_flags;

int	ft_htoa(t_flags flags, unsigned int c, int *error, int maj);
int	ft_itoa(t_flags flags, int c, int *error);
int	ft_printchar(t_flags flags, int c, int *error);
int	ft_printf(char const *str, ...);
int	ft_printstr(t_flags flags, char *str, int *error);
int	ft_ptoa(t_flags flags, unsigned long long int c, int *error);
int	ft_uitoa(t_flags flags, unsigned int c, int *error);

#endif
