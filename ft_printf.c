/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolin <ccolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 11:12:29 by ccolin            #+#    #+#             */
/*   Updated: 2024/05/30 14:35:20 by ccolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_reset_settings(t_settings *settings)
{
	settings->left_justify = 0;
	settings->zero_padding = 0;
	settings->precision = 0;
	settings->hex_prefix = 0;
	settings->plus_sign = 0;
	settings->space = 0;
	settings->format = '0';
}

int	ft_count_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_readnbr(const char *str, int *i)
{
	int	nbr;

	nbr = 0;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		nbr = nbr / 10 + str[*i] - '0';
		(*i)++;
	}
	return (nbr);
}

void	ft_set_settings(const char *str, int *i, t_settings *settings)
{
	int	save;

	save = *i;
	while (str[*i] == '-' || str[*i] == '0' || str[*i] == '.' || str[*i] \
	== '#' || str[*i] == ' ' || str[*i] == '+')
	{
		if (str [*i] == '-')
			settings->left_justify = ft_readnbr(str, i);
		else if (str [*i] == '0')
			settings->zero_padding = ft_readnbr(str, i);
		else if (str [*i] == '.')
			settings->precision = ft_readnbr(str, i);
		else if (str [*i] == '#')
			settings->hex_prefix = 1;
		else if (str [*i] == ' ')
			settings->space = 1;
		else if (str [*i] == '+')
			settings->plus_sign = 1;
	}
	if (str[*i] == 'c' || str[*i] == 's' || str[*i] == 'p' || \
			str[*i] == 'd' || str[*i] == 'i' || str[*i] == 'u' || \
				str[*i] == 'x' || str[*i] == 'X' || str[*i] == '%')
		settings->format = str[(*i)++];
	else
		*i = save - 1;
}

int	ft_printf(const char *str, ...)
{
	int			*i;
	int			count;
	t_settings	*settings;
	va_list		ap;

	i = malloc(sizeof(int));
	if (!i)
		return (0);
	settings = malloc(sizeof(t_settings));
	if (!settings)
	{
		free(i);
		return (0);
	}
	ft_reset_settings(settings);
	va_start(ap, str);
	count = 0;
	*i = 0;
	while (str[*i])
	{
		if (str[*i] == '%')
		{
			(*i)++;
			ft_set_settings(str, i, settings);
		}
		// if (settings->format != '0')
		// 	count += ft_print(str, i, settings, ap);
		count += ft_count_putchar(str[(*i)++]);
	}
	return (count);
}

int main() {
    int num_chars;

    // Test ft_printf with a simple string and print the return value
    num_chars = ft_printf("Hello Wo%rld\n");
    printf("ft_printf printed %d characters.\n", num_chars);

    // Test with integer formatting and print the return value
    num_chars = ft_printf("Integer: %d\n", 42);
    printf("ft_printf printed %d characters.\n", num_chars);

    // Test with string formatting and print the return value
    num_chars = ft_printf("String: %s\n", "Test String");
    printf("ft_printf printed %d characters.\n", num_chars);

    // Test with multiple values and print the return value
    num_chars = ft_printf("Multiple values: %d, %s, %f\n", 123, "abc", 123.456);
    printf("ft_printf printed %d characters.\n", num_chars);

    return 0;
}