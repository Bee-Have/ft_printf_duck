/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data_managment.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 14:51:49 by amarini-          #+#    #+#             */
/*   Updated: 2021/04/14 14:51:18 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		padding_register(char *str, int *i, t_list **list, va_list args)
{
	int		result;

	result = 0;
	register_negative_padding(str, i, list, &result);
	if (str[(*i)] == '0')
		if (zero_flag_check(i, str, list) == 1)
			return (0);
	if (str[(*i)] == '*')
	{
		result = va_arg(args, int);
		(*i)++;
		register_negative_padding(str, i, list, &result);
	}
	else
		while (str[(*i)] != '\0' && str[(*i)] >= '0' && str[(*i)] <= '9')
			result = (result * 10) + (str[(*i)++] - '0');
	return (result);
}

void	flags_register(t_list **list, char *str, va_list args, int *i)
{
	while (str[(*i)] != '\0')
	{
		if (str[(*i)] == '-' || str[(*i)] == '0')
		{
			(*list)->padding = padding_register(str, i, list, args);
			if (str_cmp(str[(*i)], NULL, "-0*123456789") == 0)
				(*i)--;
		}
		else if (str[(*i)] == '.')
		{
			(*list)->len_flag = 1;
			(*i)++;
			(*list)->length = padding_register(str, i, list, args);
			if ((*list)->neg_len == 0)
				(*list)->pad_char = ' ';
		}
		else
			return ;
		if (str_cmp(str[(*i)], NULL, "cspdiuxX%") == 1)
			(*i)--;
		(*list)->flag = str[(*i)];
		(*i)++;
	}
}

char	*convert_arg(char *str, va_list args, int index)
{
	char	*result;

	if (str[index] == 'c')
		result = char_to_string((char)va_arg(args, int));
	else if (str[index] == 's')
		result = str_cpy(va_arg(args, char *));
	else if (str[index] == 'p')
		result = address_to_string(va_arg(args, void *));
	else if (str[index] == 'd' || str[index] == 'i')
		result = int_to_string(va_arg(args, int));
	else if (str[index] == 'u')
		result = hexa_to_string(va_arg(args, unsigned int), 10);
	else if (str[index] == 'x' || str[index] == 'X')
	{
		result = hexa_to_string(va_arg(args, unsigned int), 16);
		if (str[index] == 'X')
			result = ft_toupper(result);
	}
	else if (str[index] == '%')
		result = percent_to_string();
	else
		return (str_cpy(""));
	return (result);
}

void	flags_managment(t_list **list)
{
	int		prefix_used;

	prefix_used = 0;
	if (!(*list)->print)
		return ;
	if (str_cmp((*list)->convert, NULL, "di") == 1 && (*list)->print[0] == '-')
	{
		free((*list)->prefix);
		(*list)->prefix = str_cpy("-");
		(*list)->print = strtrim((*list)->print, ft_len((*list)->print) - 1, 1);
	}
	length_managment(list, (*list)->pad_char);
	check_for_prefix(list, &prefix_used, 1);
	if ((*list)->padding > 0)
		apply_padding(list, &prefix_used);
	check_for_prefix(list, &prefix_used, 0);
	if (prefix_used == 0)
		free((*list)->prefix);
	if ((*list)->nulchar == 0)
		(*list)->length = ft_len((*list)->print);
	if ((*list)->print && (*list)->length == 0 && (*list)->convert != 's')
		(*list)->length = 1;
}
