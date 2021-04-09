/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converts_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 18:20:38 by amarini-          #+#    #+#             */
/*   Updated: 2021/04/06 11:29:52 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char					*ft_itoa_base(unsigned long long int n, int base)
{
	char						*base_info;
	int							ncount;
	char						*result;

	n = ft_check_negative(n);
	base_info = str_cpy("0123456789abcdef");
	ncount = ft_countnbr((unsigned long int)n, base);
	result = (char *)malloc((ncount + 1) * sizeof(char));
	if (!result)
		return (str_cpy(""));
	result[ncount] = '\0';
	ncount--;
	while (ncount > 0 && n >= (unsigned long long int)base)
	{
		result[ncount] = base_info[n % base];
		ncount--;
		n = n / base;
	}
	if (ncount == 0 || ncount == 1)
		result[ncount] = base_info[n];
	free(base_info);
	return (result);
}

char					*ft_itoa(int n)
{
	int			ncount;
	long int	nbr;
	char		*result;

	ncount = ft_countnbr(n, 10);
	nbr = (long int)ft_check_negative((long long int)n);
	result = (char *)malloc((ncount + 1) * sizeof(char));
	if (!result)
		return (NULL);
	result[ncount] = '\0';
	ncount--;
	while (ncount > 0 && nbr >= 10)
	{
		nbr = ft_check_negative(n) % 10;
		result[ncount] = nbr + '0';
		ncount--;
		n = n / 10;
		nbr = ft_check_negative(n);
	}
	if (ncount == 0 || ncount == 1)
		result[ncount] = nbr + '0';
	if (n < 0)
		result[0] = '-';
	return (result);
}

int						ft_countnbr(long long int nbr, int base)
{
	int		count;

	count = 0;
	if (nbr < 0)
		count++;
	nbr = ft_check_negative(nbr);
	while (nbr > 0)
	{
		nbr = nbr / base;
		count++;
	}
	if (count == 0)
		count++;
	return (count);
}

unsigned long long int	ft_check_negative(long long int n)
{
	if (n < 0)
		n = n * -1;
	return (n);
}

char					*ft_toupper(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		i++;
	}
	return (str);
}
