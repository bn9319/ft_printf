/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_read_filler.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: bnijland <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/12 14:26:08 by bnijland      #+#    #+#                 */
/*   Updated: 2020/01/15 20:04:16 by bnijland      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static void ft_putchar1_fd(char c)
{
    write(1, &c, 1);
}

void        ft_putnbr_fd(int n)
{
    if (n == -2147483648)
    {
        ft_putchar1_fd('-');
        ft_putchar1_fd('2');
        ft_putnbr_fd(147483648);
    }
    if (n < 0 && n != -2147483648)
    {
        ft_putchar1_fd('-');
        n *= -1;
    }
    if (n >= 10)
    {
        ft_putnbr_fd(n / 10);
        ft_putchar1_fd(n % 10 + '0');
    }
    if (n < 10 && n >= 0)
        ft_putchar1_fd(n + '0');
}

void	ft_set_to_zero(t_flags_conversions_int *filled)
{
	filled->l_justify = 0;
	filled->r_justify = 0;
	filled->zero = 0;
	filled->point = -1;
	filled->star_npoint = 0;
	filled->star_point = 0;
	filled->number = 0;
	filled->length_number = 0;
	filled->check = 0;
	filled->i = 0;
}

int	ft_read_filler(const char *to_print, va_list ap)
{
	t_flags_conversions_int filled;
	int	length_number;
	
	ft_set_to_zero(&filled);
	ft_filler_int(to_print, &filled, ap);
	length_number = filled.length_number;
	if (filled.point > filled.length_number && filled.r_justify > 0)
		filled.r_justify = filled.r_justify - filled.point;
	if (filled.point >= filled.length_number && filled.l_justify > 0)
		filled.l_justify = filled.l_justify - filled.point;
	while ((filled.r_justify > 0  && filled.point > 0 && filled.point > filled.length_number) \
	|| (filled.r_justify > filled.length_number && filled.point <= filled.length_number))
	{
		write(1, " ", 1);
		filled.r_justify--;
	}
	while (filled.point > filled.length_number || filled.zero > filled.length_number)
	{
		if (filled.number < 0)
		{
			write(1, "-", 1);
			filled.number *= -1;
		}
		write(1, "0", 1);
		filled.length_number++;
	}
	if (filled.check == 0)
	  ft_putnbr_fd(filled.number);
	while ((filled.l_justify > 0 && filled.point > 0 && filled.point > length_number) || (filled.l_justify > length_number && filled.point <= length_number))
	{
		write(1, " ", 1);
		filled.l_justify--;
	}
	return (filled.i);
}
