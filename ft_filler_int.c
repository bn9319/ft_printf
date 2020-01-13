/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_filler_int.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: bnijland <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/05 16:20:45 by bnijland      #+#    #+#                 */
/*   Updated: 2020/01/13 18:50:23 by bnijland      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_atoi(const char *tmp)
{
	int                 i;
    long int            number;
    long int            negative;

    i = 0;
    number = 0;
    negative = 1;
    while (tmp[i] < '0'  && tmp[i] > '9')
        i++;
    if (tmp[i] == '-' || tmp[i] == '+')
    {
        if (tmp[i] == '-')
            negative = -1;
        i++;
    }
    while (tmp[i] >= '0' && tmp[i] <= '9')
    {
        number = number * 10 + tmp[i] - 48;
        if (negative == -1 && number * -1 < number * -10)
            return (0);
        if (negative == 1 && number > number * 10)
            return (-1);
        i++;
    }
    return (number * negative);
}

static int	ft_find_number(const char *to_print, va_list ap)
{
	int number;
	if (to_print[0] == '*')
		return (va_arg(ap, int));
	number = ft_atoi(&to_print[0]);
	return (number);
}

void	ft_length_numb(t_flags_conversions_int *filled)
{
	int count;
	int number;

	count = 0;
	number = filled->number;
	if (number == 0)
		count++;
	while (number != 0)
	{
		number /= 10;
		count++;
	}
	filled->length_number = count;
	if (filled->number < 0)	
	{
		filled->r_justify--;
		filled->l_justify--;
	}
}

void	ft_filler_int(const char *to_print, t_flags_conversions_int *filled, va_list ap)
{
	int 					i;

	i = 0;
	while (to_print[i] != 'd')
	{
		if (to_print[i] == '-')
			filled->l_justify = ft_find_number(&to_print[i + 1], ap);
		if (to_print[i] == '0')
			filled->zero = ft_find_number(&to_print[i + 1], ap);
		if (to_print[i] == '.')
			filled->point = ft_find_number(&to_print[i + 1], ap);
		if ((to_print[0] == '*' && i == 0) || (to_print[0] > '0' && to_print[0] <= '9'))
			filled->r_justify = ft_find_number(&to_print[i], ap);
		i++;
	}
	if (filled->point > 0 && filled->zero > 0)
	{
		filled->r_justify = filled->zero;
		filled->zero = 0;
	}
	filled->number = va_arg(ap, int);
	ft_length_numb(filled);
}
