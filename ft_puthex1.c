/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_puthex1.c                                        :+:    :+:           */
/*                                                     +:+                    */
/*   By: bnijland <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/19 16:31:49 by bnijland      #+#    #+#                 */
/*   Updated: 2020/02/03 19:44:15 by bnijland      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex1(unsigned long number)
{
	if (number >= 10)
	{
		ft_puthex1(number / 16);
		if (number % 16 < 10)
			ft_putchar(number % 16 + 48);
		else if (number % 16 >= 10)
			ft_putchar(number % 16 + 87);
	}
	if (number < 10 && number > 0)
		ft_putchar(number % 16 + 48);
}
