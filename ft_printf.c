/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolin <ccolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 11:12:29 by ccolin            #+#    #+#             */
/*   Updated: 2024/05/30 20:09:30 by ccolin           ###   ########.fr       */
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

int	ft_initialize(int **i, t_settings **settings, int *count)
{
	*i = malloc(sizeof(int));
	if (!*i)
		return (0);
	*settings = malloc(sizeof(t_settings));
	if (!*settings)
	{
		free(*i);
		return (0);
	}
	**i = 0;
	*count = 0;
	ft_reset_settings(*settings);
	return (1);
}

void	ft_freeall(int **i, t_settings **settings)
{
	free(*i);
	free(*settings);
}
char	*ft_strdup(const char *s1)
{
	int		i;
	int		size;
	char	*ptr;

	i = 0;
	size = ft_strlen(s1);
	ptr = malloc(sizeof(char) * size + 1);
	if (ptr == NULL)
		return (NULL);
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char *ft_charcpy(char c)
{
	char	*str;

	str = malloc(sizeof(char) * 2);
	if (!str)
		return (NULL);
	str[0] = c;
	str[1] = '\0';
	return (str);
}

static void	ft_minus(char *s, int *n)
{
	if (*n < 0 || *n == -2147483648)
	{
		s[0] = '-';
		*n = *n * -1;
	}
}

static int	ft_intlen(int n)
{
	int		i;

	i = 1;
	if (n == -2147483648)
		return (10);
	if (n < 0)
	{
		n = n * -1;
		i++;
	}
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int				len;
	int				i;
	char			*s;
	unsigned int	nbr;

	len = ft_intlen(n);
	i = len;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
		nbr = -n;
	if (n >= 0)
		nbr = n;
	s = malloc(sizeof(char) * len + 1);
	if (s == NULL)
		return (NULL);
	s[i--] = '\0';
	ft_minus(s, &n);
	while (nbr > 9)
	{
		s[i--] = nbr % 10 + '0';
		nbr = nbr / 10;
	}
	s[i] = nbr % 10 + '0';
	return (s);
}

char	*ft_cpyhex(unsigned long nbr, t_settings settings)
{
	int				len;
	int				i;
	char			*s;

	len = ft_intlen(nbr);
	i = len;
	s = malloc(sizeof(char) * len + 1);
	if (s == NULL)
		return (NULL);
	s[i--] = '\0';mmmmmm
	ft_minus(s, &n);
	while (nbr > 9)
	{
		s[i--] = nbr % 10 + '0';
		nbr = nbr / 10;
	}
	s[i] = nbr % 10 + '0';
	return (s);
}

int	ft_print(t_settings *settings, va_list ap)
{
	int		count;
	char	*result;

	count = 0;
	if (settings->format == 'c')
		result = ft_charcpy((char)va_arg(ap, int));
	if (settings->format == 's')
		result = ft_strdup(va_arg(ap, char *));
	if (settings->format == 'd' || settings->format == 'i'\
	|| settings->format == 'u')
		result = ft_itoa(va_arg(ap, int));
	if (settings->format == 'x' || settings->format == 'X')
		result = ft_cpyhex(va_arg(ap, unsigned long), *settings);
	if (settings->format == 'p')
		result = ft_cpyptr(va_arg(ap, uintptr_t), settings);
	if (!result)
		return (NULL);
	count = ft_flags(result, settings);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int			*i;
	int			count;
	t_settings	*settings;
	va_list		ap;
	char		*arg;

	if (ft_initialize(&i, &settings, &count) == 0)
		return (0);
	va_start(ap, str);
	while (str[*i])
	{
		if (str[*i] == '%')
		{
			(*i)++;
			ft_set_settings(str, i, settings);
		}
		if (settings->format != '0')
			count += ft_print(settings, ap);
		count += ft_count_putchar(str[(*i)++]);
	}
	ft_freeall(&i, &settings);
	return (count);
}

int main(void)
{
	int	num_chars;

	num_chars = ft_printf("Hello Wo%rld\n");
	printf("ft_printf printed %d characters.\n", num_chars);
	num_chars = ft_printf("Integer: %d\n", 42);
	printf("ft_printf printed %d characters.\n", num_chars);
	num_chars = ft_printf("String: %s\n", "Test String");
	printf("ft_printf printed %d characters.\n", num_chars);
	num_chars = ft_printf("Multiple values: %d, %s, %f\n", 123, "abc", 123.456);
	printf("ft_printf printed %d characters.\n", num_chars);
	return (0);
}
