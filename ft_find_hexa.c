/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_find_hexa.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: bnijland <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/21 18:03:35 by bnijland      #+#    #+#                 */
/*   Updated: 2020/02/03 19:35:13 by bnijland      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_find_hexa(const char *to_print, va_list ap, int j, int *counter)
{
	t_flags_conversions filled;

	filled.conversion = to_print[j];
	ft_set_to_zero(&filled);
	ft_filler(to_print, &filled, ap);
	if (filled.point >= 0 && filled.zero > 0)
	{
		filled.right = filled.zero;
		filled.zero = 0;
	}
	filled.unumber = va_arg(ap, unsigned long);
	if (filled.unumber == 0 && filled.point >= 0)
		filled.check = 1;
	ft_length_hex(&filled);
	if (filled.conversion == 'p')
		filled.length += 2;
	if (filled.point > filled.length && filled.right > 0)
		filled.right -= filled.point;
	if (filled.point >= filled.length && filled.left > 0)
		filled.left -= filled.point;
	filled.total = filled.left + filled.right + filled.length;
	ft_write_hexa(&filled, filled.length);
	*counter += filled.total - filled.right - filled.left + filled.length;
	return (filled.i);
}
