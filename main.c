#include "ft_printf.h"

int		main()
{
	int		ret;
	int		ret2;
	char	c;

	ret = 0;
	ret2 = 0;

	ret = ft_printf("|%-020..-.5%|\n");
	ret2 = printf("|%-020..-.5%|\n");
	printf("57[%d]=[%d]\n", ret, ret2);
	return (0);
}