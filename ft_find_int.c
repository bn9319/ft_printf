/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_find_int.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: bnijland <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/17 17:59:33 by bnijland      #+#    #+#                 */
/*   Updated: 2020/01/17 22:07:53 by bnijland      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_find_int(const char *to_print, va_list ap, int j)
{
	t_flags_conversions filled;

	filled.conversion = to_print[j];
	ft_set_to_zero(&filled);
	ft_filler(to_print, &filled, ap);
	if (filled.point > 0 && filled.zero > 0)
	{
		filled.right = filled.zero;
		filled.zero = 0;
	}
	filled.number = va_arg(ap, int);
	if (filled.number == 0 && filled.point >= 0)
		filled.check = 1;
	ft_length_number(&filled);
	if (filled.point > filled.length && filled.right > 0)
		filled.right -= filled.point;
	if (filled.point >= filled.length && filled.left > 0)
		filled.left -= filled.point;
	ft_write_int(filled, filled.length);
	return (filled.i);
}
