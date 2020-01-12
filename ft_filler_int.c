/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_filler_int.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: bnijland <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/05 16:20:45 by bnijland      #+#    #+#                 */
/*   Updated: 2020/01/12 21:18:59 by bnijland      ########   odam.nl         */
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

static int	ft_find_number(const char *to_print, va_list ap)
{
//	int i;
//	int length;
	int number;
//	char *tmp;
	
//	i = 0;
	if (to_print[0] == '*')
		return (va_arg(ap, int));
//	while (to_print[i] < 48 || to_print[i] > 57)
//		i++;
//	length = i;
//	while (to_print[length] >= 48 && to_print[length] <= 57)
//		length++;
//	length -= i;
//	tmp = ft_strndup(&to_print[i], length);
	number = ft_atoi(&to_print[0]);
//	free(tmp);
	return (number);
}

void	ft_length_numb(t_flags_conversions_int *filled)
{
	int count;
	int number;

	count = 0;
	number = filled->number;
	if (number < 0 || number == 0)
	{
		number *= -1;
		count++;
	}
	while (number > 0)
	{
		number /= 10;
		count++;
	}
	filled->length_number = count;
}

void	ft_filler_int(const char *to_print, t_flags_conversions_int *filled, va_list ap)
{
	int 					i;

	i = 0;
	while (to_print[i] != 'd')
	{
		printf("l_justify = %d\n", filled->l_justify);
		printf("r_justify = %d\n", filled->r_justify);
		printf("zero = %d\n", filled->zero);
		printf("point = %d\n", filled->point);
		printf("number = %d\n", filled->number);
		printf("length_number = %d\n", filled->length_number);
		printf("i = %d\n", i);
		if (to_print[i] == '-')
			filled->l_justify = ft_find_number(&to_print[i + 1], ap);
		if (to_print[i] == '0')
			filled->zero = ft_find_number(&to_print[i + 1], ap);
		if (to_print[i] == '.')
			filled->point = ft_find_number(&to_print[i + 1], ap);
		if (to_print[0] == '*' || (to_print[0] >= '0' && to_print[0] <= '9'))
			filled->r_justify = ft_find_number(&to_print[i], ap);
//			filled->star_npoint = va_arg(ap, int);
//		if (to_print[i] == '*' && filled->point == -1)
//			filled->star_point = va_arg(ap, int);
//		else 
//			filled->r_justify = ft_find_number(&to_print[i]);
		i++;
	}
	if (filled->point > 0 && filled->zero > 0)
	{
		filled->r_justify = filled->zero;
		filled->zero = 0;
	}
	filled->number = va_arg(ap, int);
	ft_length_numb(filled);
	printf("l_justify = %d\n", filled->l_justify);
	printf("r_justify = %d\n", filled->r_justify);
	printf("zero = %d\n", filled->zero);
	printf("point = %d\n", filled->point);
	printf("number = %d\n", filled->number);
	printf("length_number = %d\n", filled->length_number);
}
