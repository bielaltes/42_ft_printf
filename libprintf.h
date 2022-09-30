/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libprintf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baltes-g <baltes-g@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 14:08:18 by baltes-g          #+#    #+#             */
/*   Updated: 2022/09/30 15:08:31 by baltes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPRINTF__H
# define LIBPRINTF__H

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

typedef struct s_flags
{
	void			*content;
	struct s_list	*next;
}					t_flags;

#endif
