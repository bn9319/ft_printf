/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bnijland <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/11 15:40:34 by bnijland      #+#    #+#                 */
/*   Updated: 2019/12/21 19:51:50 by bnijland      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

int		ft_printf(const char *to_print, ...)
{
	va_list ap;
	int d;
	int i;
	int j;
	

	struct flags {
		int width;
		char *s;
	};

	struct flags flags;
	
	va_start(ap, to_print);
	i = 0;
	while (to_print[i])
	{	
		if (to_print[i] == '%')
		{
			i++;
			if (to_print[i] == '0')
			{
				i++;
				flags.width = to_print[i] - 48;
				j = flags.width;
			}
			i++;
			if (to_print[i] == 'd')
			{
				d = va_arg(ap, int);
				putchar(d + 48);
				//putchar('\n');
			}
		}
		i++;
	}
	va_end(ap);
	while (j > 0)
	{
		putchar('0');
		j--;
	}
//	write(1, d + 48, 1);
	
	
	return (0);
}




int	main(void)
{
	int d;
	char *s;
	
	d = 9;
	s = "hallo";
	ft_printf("%05d", d);
	return (0);
}
