/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolin <ccolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 11:12:29 by ccolin            #+#    #+#             */
/*   Updated: 2024/05/29 20:26:13 by ccolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_putchar_count(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

int	ft_putnbr_count(int n, int fd, int count)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return (11);
	}
	else
	{
		if (n < 0)
		{
			count += ft_putchar_count('-', 1);
			n = n * -1;
		}
		if (n > 9)
			ft_putnbr_count(n / 10, fd, count);
		count += ft_putchar_count(n % 10 + '0', fd);
	}
	return (count);
}

int	ft_puthex_fd(unsigned long n, int fd, char c, int count)
{
	int	last_digit;
	int	count;

	if (c == 'p')
	{
		write(1, "0x", 2);
		c = 'a';
		count += 2;
	}
	last_digit = n % 16;
	if (n >= 16)
		ft_puthex_fd(n / 16, fd, c, count);
	if (last_digit < 10)
		count += ft_putchar_count(last_digit + '0', fd);
	else
	{
		if (c == 'X')
			count += ft_putchar_count(last_digit - 10 + 'A', fd);
		if (c == 'x' || c == 'a')
			count += ft_putchar_count(last_digit - 10 + 'a', fd);
	}
	return (count);
}

int	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i++], 1);
	}
	return (i - 1);
}

int	ft_flags(const char *str, int i, va_list ap, int *count)
{
	int	j;

	j = i;
	while (str[j] == '%')
	{
		j++;
		if (str[j] == 'i' || str[j] == 'd' || str[j] == 'u')
			*count += ft_putnbr_count(va_arg(ap, int), 1, 0);
		else if (str[j] == 'c')
			*count += ft_putchar_count(va_arg(ap, int), 1);
		else if (str[j] == '%')
			*count += ft_putchar_count('%', 1);
		else if (str[j] == 's')
			*count += ft_putstr_fd(va_arg(ap, char *), 1);
		else if (str[j] == 'X' || str[j] == 'x' || str[j] == 'p')
			*count += ft_puthex_fd(va_arg(ap, unsigned long), 1, str[j], 0);
		else
			return (i);
		j++;
	}
	return (j);
}

int	ft_printf(const char *str, ...)
{
	int		*count;
	int		i;
	va_list	ap;

	*count = 0;
	i = 0;
	va_start(ap, str);
	while (str[i])
	{
		i = ft_flags(str, i, ap, count);
		ft_putchar_count(str[i], 1);
		i++;
	}
	return (count);
}

// int	main(void)
// {
// 	char			c;
// 	char			*str;
// 	void			*ptr;
// 	int				d;
// 	int				i;
// 	unsigned int	u;
// 	unsigned int	x;
// 	unsigned int	X;

// 	c = 'A';
// 	str = "Hello, World!";
// 	ptr = str;
// 	d = 42;
// 	i = -42;
// 	u = 42;
// 	x = 123456789;
// 	X = 123456789;
// 	printf("\nprintf: Character: %c\n", c);
// 	ft_printf("ft_printf: Character: %c\n", c);
// 	printf("\nprintf: String: %s\n", str);
// 	ft_printf("ft_printf: String: %s\n", str);
// 	printf("\nprintf: Pointer: %p\n", ptr);
// 	ft_printf("ft_printf: Pointer: %p\n", ptr);
// 	printf("\nprintf: Decimal: %d\n", d);
// 	ft_printf("ft_printf: Decimal: %d\n", d);
// 	printf("\nprintf: Integer: %i\n", i);
// 	ft_printf("ft_printf: Integer: %i\n", i);
// 	printf("\nprintf: Unsigned: %u\n", u);
// 	ft_printf("ft_printf: Unsigned: %u\n", u);
// 	printf("\nprintf: Hexadecimal (lowercase): %x\n", x);
// 	ft_printf("ft_printf: Hexadecimal (lowercase): %x\n", x);
// 	printf("\nprintf: Hexadecimal (uppercase): %X\n", X);
// 	ft_printf("ft_printf: Hexadecimal (uppercase): %X\n", X);
// 	printf("\nprintf: Percent sign: %%\n");
// 	ft_printf("ft_printf: Percent sign: %%\n");
// 	return (0);
// }
