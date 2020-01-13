#include <stdio.h>
#include "ft_printf.h"

int	ft_printf(const char *to_print, ...)
{
	va_list ap;
	int i;

	i = 0;
	va_start(ap, to_print);
	while (to_print[i])
	{
		if (to_print[i] == '%')
		{
			ft_read_filler(&to_print[i + 1], ap);
			while (to_print[i - 1] != 'd')
				i++;
		}
		write(1, &to_print[i], 1);
		i++;
	}
	va_end(ap);
	return (0);
}
