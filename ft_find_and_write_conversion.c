/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_find_and_write_conversion.c                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: bnijland <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/17 16:51:33 by bnijland      #+#    #+#                 */
/*   Updated: 2020/01/19 14:03:56 by bnijland      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_find_and_write_conversion(const char *to_print, va_list ap)
{
	int j;

	j = 1;
	while ((to_print[j] < 65 || to_print[j] > 122) && to_print[j] != '%')
		j++;
	if (to_print[j] == '%')
		return (ft_find_percentage(to_print, ap, j));
	if (to_print[j] == 'c')
		return (ft_find_char(to_print, ap, j));
	if (to_print[j] == 's')
		return (ft_find_string(to_print, ap, j));
	if (to_print[j] == 'p')
		return (0);
	if (to_print[j] == 'd' || to_print[j] == 'i')
		return (ft_find_int(to_print, ap, j));
	if (to_print[j] == 'u')
		return (ft_find_unsigned(to_print, ap, j));
	if (to_print[j] == 'x')
		return (0);
	if (to_print[j] == 'X')
		return (0);
	return (j);
}
