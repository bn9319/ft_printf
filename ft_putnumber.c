/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnumber.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: bnijland <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/17 19:37:04 by bnijland      #+#    #+#                 */
/*   Updated: 2020/01/17 21:24:25 by bnijland      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_putnumber(int number)
{
	if (number == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		ft_putnumber(147483648);
	}
	if (number < 0 && number != -2147483648)
	{
		ft_putchar('-');
		number *= -1;
	}
	if (number >= 10)
	{
		ft_putnumber(number / 10);
		ft_putchar(number % 10 + 48);
	}
	if (number < 10 && number >= 0)
		ft_putchar(number + 48);
}
