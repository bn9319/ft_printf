/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_find_unsigned.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: bnijland <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/18 20:04:01 by bnijland      #+#    #+#                 */
/*   Updated: 2020/02/01 17:47:00 by bnijland      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_find_unsigned(const char *to_print, va_list ap, int j, int *counter)
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
	filled.unumber = va_arg(ap, unsigned int);
	if (filled.unumber == 0 && filled.point >= 0)
		filled.check = 1;
	ft_length_unsigned(&filled);
	if (filled.point > filled.length && filled.right > 0)
		filled.right -= filled.point;
	if (filled.point >= filled.length && filled.left > 0)
		filled.left -= filled.point;
	filled.total = filled.left + filled.right + filled.length;
	ft_write_unsigned(&filled, filled.length);
	*counter += filled.total - filled.right - filled.left + filled.length;
	return (filled.i);
}
