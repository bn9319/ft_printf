/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_find_string.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: bnijland <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/17 21:46:26 by bnijland      #+#    #+#                 */
/*   Updated: 2020/02/01 17:11:39 by bnijland      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_find_string(const char *to_print, va_list ap, int j, int *counter)
{
	t_flags_conversions	filled;
	char				*s;

	filled.conversion = to_print[j];
	ft_set_to_zero(&filled);
	ft_filler(to_print, &filled, ap);
	s = va_arg(ap, char *);
	ft_strlen_s(&filled, s);
	if (filled.point <= filled.length && filled.point != -1)
		filled.length = filled.point;
	filled.total = filled.right + filled.left + filled.length;
	ft_write_string(&filled, s, filled.length);
	*counter += filled.total - filled.right - filled.left;
	return (filled.i);
}
