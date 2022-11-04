/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baltes-g <baltes-g@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 14:08:18 by baltes-g          #+#    #+#             */
/*   Updated: 2022/11/04 17:07:23 by baltes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF__H
# define FT_PRINTF__H

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

typedef struct s_flags
{
	void			*content;
	struct s_list	*next;
}					t_flags;

int ft_htoa(t_flags flags, unsigned int c, int *error, int maj);
int ft_itoa(t_flags flags, int c, int *error);
int ft_printchar(t_flags flags, int c, int *error);
int ft_printf(char const *str, ...);
int ft_printstr(t_flags flags, char* str, int *error);
int ft_ptoa(t_flags flags, unsigned long long int c, int *error);
int ft_uitoa(t_flags flags, unsigned int c, int *error);

#endif
