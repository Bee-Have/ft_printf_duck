/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 19:12:49 by amarini-          #+#    #+#             */
/*   Updated: 2021/04/13 15:37:07 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *str, ...)
{
	va_list args;
	char	*rest;
	int		result;
	int		i;

	va_start(args, str);
	result = 0;
	i = 0;
	rest = str_cpy((char *)str);
	rest = fill_str(rest, '\0', ft_len((char *)str));
	while (str[i] != '\0')
	{
		if (str[i] == '%')
			result += analyse_behavior((char *)str, &rest, &i, args);
		else
			rest[ft_len(rest)] = str[i];
		if (i < ft_len((char *)str))
			i++;
	}
	result += end_rest(rest);
	va_end(args);
	return (result);
}

int		data_managment(char *str, int *i, va_list args)
{
	t_list	*list;
	int		result;

	result = 0;
	list = init_struct();
	list->padding = padding_register(str, i, &list, args);
	flags_register(&list, str, args, i);
	if (str_cmp(str[(*i)], NULL, "cspdiuxX%") == 0)
		while (str_cmp(str[(*i)], NULL, "%-0.*123456789") == 0)
			(*i)--;
	list->convert = str[(*i)];
	list->print = convert_arg(str, args, *i);
	if (list->convert == 'c' && list->print[0] == '\0')
		list->null_char = 1;
	flags_managment(&list);
	if (list->length != ft_len(list->print) /*&& list->len_flag == 0*/ && list->null_char == 0)
		list->length = ft_len(list->print);
	write(1, list->print, list->length);
	result = list->length;
	ft_free_list(&list);
	return (result);
}
