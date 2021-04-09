/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 21:45:17 by amarini-          #+#    #+#             */
/*   Updated: 2021/04/09 14:01:34 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_write(char c)
{
	write(1, &c, 1);
	return ;
}

void	ft_putstr(char *str, int *null_char)
{
	int		i;

	i = 0;
	if (!str)
		return ;
	while (str[i] != '\0')
	{
		if (null_char && null_char[0] == 1 && i == null_char[1])
		{
			ft_write(0);
		}
		else
			ft_write(str[i]);
		i++;
	}
	return ;
}
