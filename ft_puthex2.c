/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_puthex2.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bnijland <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/19 16:50:56 by bnijland      #+#    #+#                 */
/*   Updated: 2020/02/13 16:48:48 by bnijland      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex2(unsigned long number)
{
	if (number >= 10)
	{
		ft_puthex2(number / 16);
		if (number % 16 < 10)
			ft_putchar(number % 16 + 48);
		else if (number % 16 >= 10)
			ft_putchar(number % 16 + 55);
	}
	if (number < 10 && number > 0)
		ft_putchar(number % 16 + 48);
}
