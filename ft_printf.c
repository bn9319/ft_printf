/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bnijland <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/17 16:38:56 by bnijland      #+#    #+#                 */
/*   Updated: 2020/01/17 20:20:23 by bnijland      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *to_print, ...)
{
	va_list ap;
	int		i;

	i = 0;
	va_start(ap, to_print);
	while (to_print[i])
	{
		if (to_print[i] != '%')
			write(1, &to_print[i], 1);
		if (to_print[i] == '%')
			i += ft_find_and_write_conversion(&to_print[i], ap);
		i++;
	}
	va_end(ap);
	return (0);
}
