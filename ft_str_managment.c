/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_managment.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 17:09:48 by amarini-          #+#    #+#             */
/*   Updated: 2021/04/14 14:15:05 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_len(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*fill_str(char *str, char fill, int length)
{
	int		i;

	i = 0;
	if (length < 0)
		length = 0;
	str[length] = '\0';
	while (i < length)
	{
		str[i] = fill;
		i++;
	}
	return (str);
}

char	*str_cpy(char *content)
{
	char	*result;
	int		length;
	int		i;

	if (!content)
	{
		result = str_cpy("(null)");
		return (result);
	}
	length = ft_len(content);
	i = 0;
	result = (char *)malloc((length + 1) * sizeof(char));
	if (!result)
		return (NULL);
	result[length] = '\0';
	while (i < length)
	{
		result[i] = content[i];
		i++;
	}
	return (result);
}

char	*ft_strjoin(char *dst, char *src, int null_char)
{
	char	*result;
	int		i;
	int		len;

	if (!dst)
		return (src);
	i = 0;
	len = ft_len(dst) + ft_len(src);
	if (null_char == 1)
		len += 1;
	result = (char *)malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	result[len] = '\0';
	while (i < len)
	{
		result[i] = join_util(dst, src, null_char, i);
		i++;
	}
	free(dst);
	free(src);
	return (result);
}

char	join_util(char *dst, char *src, int null_char, int i)
{
	char	result;

	result = '\0';
	if (i < ft_len(dst) || (null_char == 1 && i < 1))
		result = dst[i];
	else if (null_char == 0)
		result = src[i - ft_len(dst)];
	else if (null_char == 1 && dst[0] == '\0')
		result = src[i - 1];
	else
		result = src[0];
	return (result);
}
