/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_managment.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 17:09:48 by amarini-          #+#    #+#             */
/*   Updated: 2021/04/09 17:59:03 by amarini-         ###   ########.fr       */
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

char	*ft_strjoin(char *dst, char *src)
{
	char	*result;
	int		i;
	int		len;

	if (!dst)
		return (src);
	i = 0;
	len = ft_len(dst) + ft_len(src);
	result = (char *)malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	result[len] = '\0';
	while (i < len)
	{
		if (i < ft_len(dst))
			result[i] = dst[i];
		else
			result[i] = src[i - ft_len(dst)];
		i++;
	}
	free(dst);
	dst = NULL;
	free(src);
	return (result);
}

/*int		return_to_percent(char *str, int *i, t_list **list)
{
	while (str_cmp(str[(*i)], NULL, "%-0.*") == 1)
		(*i)--;
	write(1, "%", 1);
	free((*list)->prefix);
	free((*list)->print);
	free((*list));
	return (1);
}*/
