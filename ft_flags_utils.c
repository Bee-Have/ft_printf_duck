/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:54:35 by amarini-          #+#    #+#             */
/*   Updated: 2021/04/14 16:07:37 by amarini-         ###   ########.fr       */
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

void	length_managment(t_list **lst, char extra)
{
	char	*extend;
	int		length;

	if ((*lst)->convert == 's' && (*lst)->length < ft_len((*lst)->print)
		&& (*lst)->len_flag == 1 && (*lst)->neg_len == 0)
		(*lst)->print = strtrim((*lst)->print, (*lst)->length, 0);
	else if (str_cmp((*lst)->convert, NULL, "cs%") == 0
			&& (*lst)->len_flag == 1 && (*lst)->neg_len == 0)
	{
		if ((*lst)->length == 0 && ft_len((*lst)->print) <= 1
			&& (*lst)->print[0] == '0')
			(*lst)->print = strtrim((*lst)->print, 0, 0);
		else if ((*lst)->length > ft_len((*lst)->print)
				&& str_cmp((*lst)->convert, NULL, "pdiuxX") == 1)
		{
			if ((*lst)->pad_char == ' ')
				extra = '0';
			length = (*lst)->length - ft_len((*lst)->print);
			extend = make_extent(extra, length);
			(*lst)->print = ft_strjoin(extend, (*lst)->print, (*lst)->nulchar);
		}
	}
}

void	apply_padding(t_list **list, int *prefix_used)
{
	char	*extra;

	if ((*prefix_used) == 0 && (*list)->prefix[0] == '-')
		(*list)->padding = (*list)->padding - 1;
	(*list)->padding = calc_pad((*list)->padding, ft_len((*list)->print));
	if ((ft_len((*list)->print) == 0
		&& str_cmp((*list)->convert, NULL, "cspdiuxX%") == 1)
		&& (*list)->nulchar == 0)
		(*list)->padding += 1;
	if ((*list)->convert == 'p' && (*prefix_used) == 0
		&& (*list)->padding >= ft_len((*list)->prefix))
		(*list)->padding = (*list)->padding - ft_len((*list)->prefix);
	(*list)->length = ft_len((*list)->print) + (*list)->padding;
	if ((*list)->convert == 'c' && (*list)->print[0] == '\0')
		(*list)->length += 1;
	extra = make_extent((*list)->pad_char, (*list)->padding);
	if ((*list)->neg_padding == 0)
		(*list)->print = ft_strjoin(extra, (*list)->print, (*list)->nulchar);
	else if ((*list)->neg_padding == 1)
		(*list)->print = ft_strjoin((*list)->print, extra, (*list)->nulchar);
}

void	check_for_prefix(t_list **list, int *prefix_used, int first)
{
	if (first == 1 && (*list)->pad_char != ' ')
		return ;
	if ((*prefix_used) == 0 && ((*list)->convert == 'p'
		|| (str_cmp((*list)->convert, NULL, "di") == 1
		&& ((*list)->prefix[0] == '-'))))
	{
		(*list)->print = ft_strjoin((*list)->prefix,
						(*list)->print, (*list)->nulchar);
		(*prefix_used) = 1;
	}
	return ;
}
