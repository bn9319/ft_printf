#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "ft_printf.h"


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

/*int	ft_printf(const char *to_print, ...)
{
	va_list ap;
	void	*s;
	int		i;

	i = 0;
	while (to_print[i])
	{
		if (to_print[i] == '%')
		{
			
		}
		else 
			ft_putchar1_fd(to_print[i]);
	}
	}*/


int	ft_printf(const char *to_print, ...)
{
	va_list ap;
	t_flags_conversions_int filled;
	int i;
	
	i = 0;
	va_start(ap, to_print);
//	d = va_arg(ap, int);
//	va_end(ap);
	ft_filler_int(&to_print[i + 1], &filled, ap);
	ft_putnbr_fd(filled.number);
	while (filled.star_npoint > 0)
	{
		ft_putchar1_fd(' ');
		filled.star_npoint--;
	}
	while (to_print[i] != 'd')
		i++;
	i++;
	while (to_print[i])
	{
		ft_putchar1_fd(to_print[i]);
		i++;
	}
	printf("length number || %d\n", filled.length_number);
	return (0);
	
}

int	main(void)
{
	int d;

	d = 1200;
	ft_printf("%----*dhoi\n", 20, d);
	printf("%-*d    hoi\n", 20, d);
	return (0);
}
