/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_find_char.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: bnijland <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/17 21:14:15 by bnijland      #+#    #+#                 */
/*   Updated: 2020/01/17 21:41:03 by bnijland      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_find_char(const char *to_print, va_list ap, int j)
{
	t_flags_conversions filled;

	filled.conversion = to_print[j];
	ft_set_to_zero(&filled);
	ft_filler(to_print, &filled, ap);
	filled.right--;
	filled.left--;
	filled.c = va_arg(ap, int);
	ft_write_char(filled);
	return (filled.i);
}
