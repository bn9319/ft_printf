#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
//	ft_printf("ultimate3 %*.*d %*.*s\n", 1, 50, 5000, 1, 0, "hey");
//	ft_printf("ultimate4 %*.*x %*.*X\n", 1, 50, 5000, 1, 0, 10);
//	ft_printf("ultimate5 %*.*u\n", 1, 50, 5000);
//	ft_printf("neg1 %*s\n", -9, "coucou");
//	printf("neg2 %*.*s\n", -9, 4, "coucou");
//	ft_printf("neg2 %*.*s\n", -9, 4, "coucou");
//	ft_printf("%-3d|", 12);
  float n = -12.12;
  /*  ft_printf("niet chte:%.*d\n", -9, 0);
  printf("de echte: %.*d\n", -9, 0);
	ft_printf("%*.*d\n", 0, -5, 0);
	printf("%*.*d\n", 0, -5, 0);
	ft_printf("%c\n", 65);
  */	printf("%+e\n", n);
}
