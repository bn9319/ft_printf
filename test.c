#include <stdio.h>

int	main(void)
{
	int d;
	char *s;

	d = 12;
	s = "hello";
	printf("%05d\n", d);
//	printf("%-*.*dhoi\n", 12, 5, d);
//	printf("%d   hoi\n", d);
//	printf("%d     hoi\n", d);
//	printf("%%z");
//	printf("- || %5*d hello\n", 5,  d);
//	printf("0 || %d hello\n", d);
//	printf("", d);
//	printf("", d);
	return (0);
}


/*
flags: 

integer: 

%-5d = 5 spaties na d 
%5d = 5 spaties voor d
%*d = extra variabele die aantal spaties bepaalt voor d
%05d = 5 nullen voor d
%-05d = 0 flag wordt genegeerd
%.5d = 5 nullen voor d
%-.5d = gevolgd door 5 nullen, - genegeerd
 */
