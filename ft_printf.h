/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bnijland <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/16 18:44:56 by bnijland      #+#    #+#                 */
/*   Updated: 2020/01/15 17:18:45 by bnijland      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

typedef struct	s_flags_conversions_int{
	int l_justify;
	int r_justify;
	int	zero;
	int	point;
	int star_npoint;
	int star_point;
	int number;
	int length_number;
	int i;
}				t_flags_conversions_int;

void ft_filler_int(const char *to_print, t_flags_conversions_int *filled, va_list ap);
int	ft_read_filler(const char *to_print, va_list ap);
int	ft_printf(const char *to_print, ...);

#endif
