#include "ft_printf.h"

int		main()
{
	int		ret;
	int		ret2;
	char	*freaking_long;

	ret = 0;
	ret2 = 0;

	ret = ft_printf("%-BLABLABLABLA\n");
	ret2 = printf("%-BLABLABLABLA\n");
	printf("9[%d]=[%d]\n", ret, ret2);
	ret = ft_printf("%0BLABLABLABLA\n");
	ret2 = printf("%0BLABLABLABLA\n");
	printf("10[%d]=[%d]\n", ret, ret2);
	return (0);
}