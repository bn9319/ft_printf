/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_filler_int.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: bnijland <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/05 16:20:45 by bnijland      #+#    #+#                 */
/*   Updated: 2020/01/05 20:20:38 by bnijland      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_atoi(char *tmp)
{
	int                 i;
    long int            number;
    long int            negative;

    i = 0;
    number = 0;
    negative = 1;
    while ((tmp[i] >= 9 && tmp[i] <= 13) || tmp[i] == 32\
		)
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
        if (negative == -1 && number * -1 < number * \
			-10)
            return (0);
        if (negative == 1 && number > number * 10)
            return (-1);
        i++;
    }
    return (number * negative);
}

static char	*ft_strndup(const char *to_print, int length)
{
	char *tmp;
	int i;

	i = 0;
	tmp = malloc(length + 1);
	if (tmp == 0)
		return (0);
	while (i < length)
	{
		tmp[i] = to_print[i];
		i++;
	}
	tmp[i] = 0;
	return (tmp);
}

static int	ft_find_number(const char *to_print)
{
	int i;
	int length;
	int number;
	char *tmp;
	
	i = 0;
	if (to_print[i] == '*')
		return (-1);
	while (to_print[i] < 48 || to_print[i] > 57)
		i++;
	length = i;
	while (to_print[length] >= 48 && to_print[length] <= 57)
		length++;
	length -= i;
	tmp = ft_strndup(&to_print[i], length);
	number = ft_atoi(tmp);
	free(tmp);
	return (number);
}

t_flags_conversions_int	ft_filler_int(const char *to_print)
{
	t_flags_conversions_int filled;
	int 					i;

	i = 0;
	while (to_print[i] != 'd')
	{
		if (to_print[i] == '-')
			filled.l_justify = ft_find_number(&to_print[i + 1]);
		if (to_print[i] == '0')
			filled.zero = ft_find_number(&to_print[i + 1]);
		if (to_print[i] == '.')
			filled.point = ft_find_number(&to_print[i + 1]);
		else 
			filled.r_justify = ft_find_number(&to_print[i]);
		i++;
	}
	return (filled);
}

