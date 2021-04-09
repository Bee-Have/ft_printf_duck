/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 19:12:52 by amarini-          #+#    #+#             */
/*   Updated: 2021/04/09 16:03:07 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

int						ft_printf(const char *str, ...);
int						data_managment(char *str, int *i, va_list args);
int						analyse_behavior(char *str, char **rest, int *i, va_list args);

typedef	struct			s_list
{
	int		length;
	int		neg_len;
	int		len_flag;
	int		padding;
	int		neg_padding;
	int		null_char[2];
	char	flag;
	char	pad_char;
	char	convert;
	char	*prefix;
	char	*print;
}						t_list;

int						end_rest(char *rest);
void					find_null_char(t_list **list);


int						padding_register(char *str, int *i, t_list **list, va_list args);
void					flags_register(t_list **list, char *str, va_list args, int *i);
char					*convert_arg(char *str, va_list args, int index);
void					flags_managment(t_list **list);

t_list					*init_struct(void);
void					ft_free_list(t_list **list);

int						ft_len(char *str);
char					*fill_str(char *str, char fill, int length);
char					*str_cpy(char *content);
char					*ft_strjoin(char *dst, char *src);
int						return_to_percent(char *str, int *i, t_list **list);

char					*strtrim(char *str, int length, int start);
int						calc_pad(int padding, int length);
void					register_negative_padding(char *str, int *i, t_list **list, int *nbr);
int						str_cmp(char c, char *str, char *cmp);

char					*make_extent(char fill, int length);
void					length_managment(t_list **list, char extra);
void					apply_padding(t_list **list, int *prefix_used);
void					check_for_prefix(t_list **list, int *prefix_used, int first);

char					*char_to_string(int c);
char					*address_to_string(void *address);
char					*int_to_string(unsigned int nbr);
char					*hexa_to_string(unsigned int nbr, int base);
char					*percent_to_string(void);

char					*ft_itoa_base(unsigned long long int n, int base);
char					*ft_itoa(int n);
int						ft_countnbr(long long int nbr, int base);
unsigned long long int	ft_check_negative(long long int n);
char					*ft_toupper(char *str);

void					ft_write(char c);
void					ft_putstr(char *str, int *null_char);

#endif
