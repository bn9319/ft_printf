/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_write_int.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: bnijland <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/17 17:15:00 by bnijland      #+#    #+#                 */
/*   Updated: 2020/01/18 00:49:00 by bnijland      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_write_int(t_flags_conversions filled, int length)
{
	while ((filled.right > 0 && filled.point > filled.length) || \
(filled.right > filled.length && filled.point <= filled.length))
	{
		write(1, " ", 1);
		filled.right--;
	}
	while (filled.point > filled.length || filled.zero > filled.length)
	{
		if (filled.number < 0)
		{
			write(1, "-", 1);
			filled.number *= -1;
		}
		write(1, "0", 1);
		filled.length++;
	}
	if (filled.check == 0)
		ft_putnumber(filled.number);
	while ((filled.left > 0 && filled.point > length) || \
(filled.left > length && filled.point <= length))
	{
		write(1, " ", 1);
		filled.left--;
	}
}
