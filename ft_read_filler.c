/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_read_filler.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: bnijland <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/12 14:26:08 by bnijland      #+#    #+#                 */
/*   Updated: 2020/01/12 21:00:24 by bnijland      ########   odam.nl         */
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
	filled->point = 0;
	filled->star_npoint = 0;
	filled->star_point = 0;
	filled->number = 0;
	filled->length_number = 0;
}

void	ft_read_filler(const char *to_print, va_list ap)
{
	t_flags_conversions_int filled;
	int count;
	
	ft_set_to_zero(&filled);
	ft_filler_int(to_print, &filled, ap);
	count = filled.point - filled.length_number;
	while ((filled.r_justify > count && filled.point > 0) || \
	(filled.r_justify > filled.length_number && filled.point == 0))
	{
		write(1, " ", 1);
		filled.r_justify--;
	}
	while (filled.point > filled.length_number || filled.zero > filled.length_number)
	{
		write(1, "0", 1);
		filled.length_number++;
	}
	ft_putnbr_fd(filled.number);
	while ((filled.l_justify > count && filled.point > 0) ||		\
	(filled.l_justify > filled.length_number && filled.point == 0))
	{
		write(1, " ", 1);
		filled.l_justify--;
	}
/*	while (filled.point > 0 && filled.point > filled.length_number)
	{
		write(1, "0", 1);
		filled.point--;
		count++;
	}
	while (filled.star_point > 0 && filled.star_point > filled.length_number)
	{
		write(1, "0", 1);
		filled.star_point--;
		count++;
	}
	while (filled.zero > 0 && filled.zero > count && filled.point == 0 && filled.l_justify == 0)
	{
		write(1, "0", 1);
		filled.zero--;
	}
	while (filled.zero == -1 && filled.star_npoint > count && filled.l_justify == 0 && filled.point == 0)
	{
		write(1, "0", 1);
		filled.star_npoint--;
	}
	while (filled.r_justify > 0 && filled.r_justify > count)
	{
		write(1, " ", 1);
		filled.r_justify--;
	}
	while (filled.r_justify == -1 && filled.star_npoint > count)
	{
		write(1, " ", 1);
		filled.r_justify--;
	}
	ft_putnbr_fd(filled.number);
	while (filled.l_justify > count)
	{
		write(1, " ", 1);
		filled.l_justify--;
	}
	while (filled.l_justify == -1 && filled.star_npoint > count)
	{
		write(1, " ", 1);
		filled.star_npoint--;
		}*/
}
