#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int i;
	int *p;

	i = 12;
	p = &i;

	printf("%-*.*s", 7, 3, "yolo");
	ft_printf("%-*.*s", 7, 3, "yolo");
}
