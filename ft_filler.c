/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_filler.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bnijland <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/17 18:21:13 by bnijland      #+#    #+#                 */
/*   Updated: 2020/02/03 19:32:19 by bnijland      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_atoi_printf(const char *to_print, int *i)
{
	int	number;

	number = 0;
	if (to_print[*i] <= 48 || to_print[*i] > 57)
		(*i)++;
	if (to_print[*i] == '-')
		return (0);
	while (to_print[*i] >= 48 && to_print[*i] <= 57)
	{
		number = number * 10 + to_print[*i] - 48;
		(*i)++;
	}
	return (number);
}

static	int	ft_find_number(const char *to_print, va_list ap, int *i, \
t_flags_conversions *filled)
{
	int number;

	if (to_print[*i] == '*' || to_print[*i + 1] == '*')
	{
		number = va_arg(ap, int);
		if (number < 0 && to_print[*i] == '-')
			number *= -1;
		else if (number < 0 && (to_print[*i] == '0' || to_print[*i] == '*'))
		{
			filled->left = number * -1;
			number = 0;
		}
		else if (number < 0 && filled->conversion == 's')
			number = -1;
		if (to_print[*i + 1] == '*' || to_print[*i] == '*')
			(*i)++;
		return (number);
	}
	number = ft_atoi_printf(to_print, i);
	return (number);
}

void		ft_filler(const char *to_print, t_flags_conversions *filled, \
va_list ap)
{
	int i;

	i = 1;
	while (to_print[i] != filled->conversion)
	{
		if ((to_print[1] == '*' && i == 1) || \
(to_print[1] > 48 && to_print[1] <= 57 && i == 1))
			filled->right = ft_find_number(to_print, ap, &i, filled);
		else if (to_print[i] == '0')
			filled->zero = ft_find_number(to_print, ap, &i, filled);
		else if (to_print[i] == '-')
			filled->left = ft_find_number(to_print, ap, &i, filled);
		else if (to_print[i] == '.')
		{
			filled->point = 0;
			filled->point = ft_find_number(to_print, ap, &i, filled);
		}
		else
			i++;
	}
	filled->i = i;
}
