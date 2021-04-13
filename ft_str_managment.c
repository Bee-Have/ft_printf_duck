/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_managment.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 17:09:48 by amarini-          #+#    #+#             */
/*   Updated: 2021/04/13 11:51:23 by amarini-         ###   ########.fr       */
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
		if (i < ft_len(dst) || (null_char == 1 && i < 1))
			result[i] = dst[i];
		else if (null_char == 0)
			result[i] = src[i - ft_len(dst)];
		else if (null_char == 1 && dst[0] == '\0')
			result[i] = src[i - 1];
		else
			result[i] = src[0];
		i++;
	}
	free(dst);
	dst = NULL;
	free(src);
	return (result);
}
