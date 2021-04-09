/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 13:07:24 by amarini-          #+#    #+#             */
/*   Updated: 2021/04/07 18:21:51 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*strtrim(char *str, int length, int start)
{
	char	*result;
	int		i;

	i = 0;
	if (length == 0)
		result = (char *)malloc(sizeof(char));
	else
		result = (char *)malloc((length + 1) * sizeof(char));
	result[length] = '\0';
	while (i < length)
	{
		result[i] = str[start];
		i++;
		start++;
	}
	free(str);
	return (result);
}

int		calc_pad(int padding, int length)
{
	int		result;

	result = 0;
	if (length == 0)
		length = 1;
	if (padding > length)
		result = padding - length;
	else
		result = 0;
	return (result);
}

void	register_negative_padding(char *str, int *i, t_list **list, int *nbr)
{
	if (str[(*i)] == '-' || (*nbr) < 0 || (*list)->padding < 0
		|| (*list)->length < 0)
	{
		if ((*list)->padding < 0 || (*list)->length < 0)
			(*list)->padding = (*list)->padding * -1;
		else if ((*nbr) < 0)
			(*nbr) = (*nbr) * -1;
		if ((*list)->len_flag == 0)
		{
			(*list)->neg_padding = 1;
			(*list)->pad_char = ' ';
		}
		else
			(*list)->neg_len = 1;
	}
	if (str[(*i)] == '-')
		(*i)++;
	return ;
}

int		str_cmp(char c, char *str, char *cmp)
{
	int		i;

	if (!c && !str)
		return (1);
	i = 0;
	if (c && !str)
	{
		while (cmp[i] != '\0')
		{
			if (cmp[i] == c)
				return (1);
			i++;
		}
	}
	else
		while (str[i] != '\0' && cmp[i] != '\0')
		{
			if (str[i] != cmp[i])
				return (1);
			i++;
		}
	return (0);
}
