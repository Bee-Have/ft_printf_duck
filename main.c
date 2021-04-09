#include "ft_printf.h"

int		main()
{
	int		ret;
	int		ret2;
	char	*freaking_long;

	ret = 0;
	ret2 = 0;

	ret = printf("|%05.7%|\n");
	ret2 = ft_printf("|%05.7%|\n");
	printf("57[%d]=[%d]\n", ret, ret2);
	return (0);
}