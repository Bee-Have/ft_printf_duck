/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:54:35 by amarini-          #+#    #+#             */
/*   Updated: 2021/04/13 15:31:48 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*make_extent(char fill, int length)
{
	char	*result;

	result = (char *)malloc((length + 1) * sizeof(char));
	if (!result)
		return (NULL);
	result = fill_str(result, fill, length);
	return (result);
}

void	length_managment(t_list **list, char extra)
{
	char	*extention;
	int		length;

	if ((*list)->convert == 's' && (*list)->length < ft_len((*list)->print)
		&& (*list)->len_flag == 1 && (*list)->neg_len == 0)
		(*list)->print = strtrim((*list)->print, (*list)->length, 0);
	else if (str_cmp((*list)->convert, NULL, "cs%") == 0
			&& (*list)->len_flag == 1 && (*list)->neg_len == 0)
	{
		if ((*list)->length == 0 && ft_len((*list)->print) <= 1
			&& (*list)->print[0] == '0')
			(*list)->print = strtrim((*list)->print, 0, 0);
		else if ((*list)->length > ft_len((*list)->print)
				&& str_cmp((*list)->convert, NULL, "pdiuxX") == 1)
		{
			if ((*list)->pad_char == ' ')
				extra = '0';
			length = (*list)->length - ft_len((*list)->print);
			extention = make_extent(extra, length);
			(*list)->print = ft_strjoin(extention, (*list)->print, (*list)->null_char);
		}
	}
}

void	apply_padding(t_list **list, int *prefix_used)
{
	char	*extra;

	if ((*prefix_used) == 0 && (*list)->prefix[0] == '-')
		(*list)->padding = (*list)->padding - 1;
	(*list)->padding = calc_pad((*list)->padding, ft_len((*list)->print));
	if ((ft_len((*list)->print) == 0 && str_cmp((*list)->convert, NULL, "cspdiuxX%") == 1)
		&& (*list)->null_char == 0)
		(*list)->padding += 1;
	if ((*list)->convert == 'p' && (*prefix_used) == 0
		&& (*list)->padding >= ft_len((*list)->prefix))
		(*list)->padding = (*list)->padding - ft_len((*list)->prefix);
	(*list)->length = ft_len((*list)->print) + (*list)->padding;
	if ((*list)->convert == 'c' && (*list)->print[0] == '\0')
		(*list)->length += 1;
	extra = make_extent((*list)->pad_char, (*list)->padding);
	if ((*list)->neg_padding == 0)
		(*list)->print = ft_strjoin(extra, (*list)->print, (*list)->null_char);
	else if ((*list)->neg_padding == 1)
		(*list)->print = ft_strjoin((*list)->print, extra, (*list)->null_char);
}

void	check_for_prefix(t_list **list, int *prefix_used, int first)
{
	if (first == 1 && (*list)->pad_char != ' ')
		return ;
	if ((*prefix_used) == 0 && ((*list)->convert == 'p'
		|| (str_cmp((*list)->convert, NULL, "di") == 1
		&& ((*list)->prefix[0] == '-'))))
	{
		(*list)->print = ft_strjoin((*list)->prefix, (*list)->print, (*list)->null_char);
		(*prefix_used) = 1;
	}
	return ;
}
