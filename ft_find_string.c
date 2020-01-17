/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_find_string.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: bnijland <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/17 21:46:26 by bnijland      #+#    #+#                 */
/*   Updated: 2020/01/18 00:17:33 by bnijland      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_find_string(const char *to_print, va_list ap, int j)
{
	t_flags_conversions	filled;
	int					length;
	char				*s;

	filled.conversion = to_print[j];
	ft_set_to_zero(&filled);
	ft_filler(to_print, &filled, ap);
	s = va_arg(ap, char *);
	ft_strlen_s(&filled, s);
	length = filled.length;
	if (filled.point > filled.length && filled.right > 0)
		filled.right -= filled.point;
	if (filled.point >= filled.length && filled.left > 0)
		filled.left -= filled.point;
	if (filled.point <= filled.length && filled.point != -1)
		length = filled.point;
	ft_write_string(filled, s, length);
	return (filled.i);
}
