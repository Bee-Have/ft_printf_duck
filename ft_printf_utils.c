/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 18:02:45 by amarini-          #+#    #+#             */
/*   Updated: 2021/04/14 12:17:53 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		analyse_behavior(char *str, char **rest, int *i, va_list args)
{
	int		result;

	result = 0;
	(*i)++;
	if ((*rest)[0] != '\0')
		write(1, (*rest), ft_len((*rest)));
	if (str_cmp(str[(*i)], NULL, "cspdiuxX%-0.*123456789") == 1)
		result += data_managment(str, i, args) + ft_len((*rest));
	else if ((*i) >= 1)
		(*i)--;
	else
		(*rest)[ft_len((*rest))] = str[(*i)];
	(*rest) = fill_str((*rest), '\0', ft_len((char *)str));
	return (result);
}

int		end_rest(char *rest)
{
	int		result;

	result = 0;
	if (rest[0] != '\0')
	{
		result = ft_len(rest);
		write(1, rest, ft_len(rest));
	}
	free(rest);
	return (result);
}
