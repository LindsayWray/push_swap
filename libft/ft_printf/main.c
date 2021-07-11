#include <stdio.h>
#include "char_count.c"

int ft_printf(const char *format, ...);

int 	main()
{
	char *ptr = NULL;

	printf("%% *.5i 42 == |%*.5i| \n", 8, 42);
	ft_printf("%% *.5i 42 == |%*.5i| \n", 8, 42);

	int ret1 = printf("%*c|CCCCCC|%c\n", -8, (char)211, 'b');
	int ret2 = ft_printf("%*c|CCCCCC|%c\n", -8, (char)211, 'b');
	
	printf("%32.*s|SSSSSS|\n", -2, "Boe");
	ft_printf("%32.*s|SSSSSS|\n", -2, "Boe");

	printf("%08.3s|NNNN|\n", NULL);
	ft_printf("%08.3s|NNNN|\n", NULL);
	
	printf("%3d|DDDDDDD|%*.*d\n", -2147483648, 8, -3, -21);
	ft_printf("%3d|DDDDDDD|%*.*d\n", -2147483648, 8, -3, -21);
	
	printf("%0-5u|UUUUUU|%u\n", 16, 2);
	ft_printf("%0-5u|UUUUUU|%u\n", 16, 2);
	
	printf("%*.*x|xxxxxx|\n", 42, 25, 4294967284);
	ft_printf("%*.*x|xxxxxx|\n", 42, 25, 4294967284);
	
	printf("%*.5X|XXXXXX|%X\n", 8, 55, -8000);
	ft_printf("%*.5X|XXXXXX|%X\n", 8, 55, -8000);
	
	printf("%-*.4p|PPPPPP|%p\n", 0, ptr, ptr);
	ft_printf("%-*.4p|PPPPPP|%p\n", 0, ptr, ptr);

	printf("%05.*f|FFFFFF|%11f\n", -3, -5.0, 0.66);
	ft_printf("%05.*f|FFFFFF|%11f\n", -3, -5.0, 0.66);

	printf("%-.5f!%.f\n", (float)12.34, (float)-6.500000000000001);
	ft_printf("%-.5f!%.f\n", (float)12.34, (float)-6.500000000000001);

	int ret3 = ft_printf("(null)\n", (char)0);
	int ret4 = ft_printf("(null)\n", (char)0);

	//ft_printf("%d\n", ret1);
	//ft_printf("%d\n", ret2);
	ft_printf("%d\n", ret3);
	ft_printf("%d\n", ret4);

	return (0);
}