#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "ft_printf.h" 

t_flags_conversions	ft_flags_int(const char *to_print, int i)
{
	t_flags_conversions flags;

	while (to_print[i])
	{
		if (to_print[i] == '%')
		{
			i++;
			if (to_print[i] == '.')
			{
				flags.precision_char = to_print[i + 1] - 48;
				return (flags);
			}
		
		}	
	}
		return (flags);
	
}

int	ft_printf(const char *s, ...)
{

}

int	main(void)
{
	t_flags_conversions flags2;

	flags2 = ft_flags_int("%.5s", 0);
	printf("%d\n", flags2.precision_char);
	return (0);
}
