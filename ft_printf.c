/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolin <ccolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 18:56:11 by ccolin            #+#    #+#             */
/*   Updated: 2024/06/01 16:35:48 by ccolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_reset_settings(t_settings *settings)
{
	settings->left_justify = 0;
	settings->right_justify = 0;
	settings->zero_padding = 0;
	settings->precision = -1;
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
	if (str[*i] == '-' || str[*i] == '.')
		(*i)++;
	if (!(str[*i] >= '0' && str[*i] <= '9'))
		nbr = 0;
	else
	{
		while (str[*i] >= '0' && str[*i] <= '9')
		{
			nbr = nbr * 10 + str[*i] - '0';
			(*i)++;
		}
	}
	(*i)--;
	return (nbr);
}

void print_settings(const t_settings *s)
{
    if (s == NULL) {
        printf("Settings pointer is NULL\n");
        return;
    }
    printf("Settings:\n");
    printf(" Left Justify: %d\n", s->left_justify);
    printf(" Zero Padding: %d\n", s->zero_padding);
    printf(" Precision: %d\n", s->precision);
    printf(" Hex Prefix: %d\n", s->hex_prefix);
    printf(" Plus Sign: %d\n", s->plus_sign);
    printf(" Space: %d\n", s->space);
    printf(" Format: '%c'\n", s->format);
}

void	ft_setflags(const char *str, int *i, t_settings *settings)
{
	while (str[*i] == '-' || str[*i] == '0' || str[*i] == '.' || str[*i] \
	== '#' || str[*i] == ' ' || str[*i] == '+' || (str [*i] <= '9' && str [*i] >= '1'))
	{
		if (str [*i] == '-')
			settings->left_justify = ft_readnbr(str, i);
		else if (str [*i] <= '9' && str [*i] >= '1')
			settings->right_justify = ft_readnbr(str, i);
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
		(*i)++;
	}
}
void	ft_set_settings(const char *str, int *i, t_settings *settings)
{
	int	save;	save = *i;

	ft_setflags(str, i, settings);
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

unsigned int	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	if (dstsize == 0)
		return (ft_strlen(src));
	i = 0;
	while (i != dstsize - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

char	*ft_strdup_printf(const char *s1)
{
	int		i;
	int		size;
	char	*ptr;

	if (!s1)
	{
		ptr = malloc(sizeof(char) * 7);
		ft_strlcpy((char *)ptr, "(null)", 7);
		if (!ptr)
			return (NULL);
		return (ptr);
	}
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

static int	ft_hexlen(unsigned long n)
{
	int		i;

	i = 1;
	while (n > 9)
	{
		n = n / 16;
		i++;
	}
	return (i);
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
		return (ft_strdup_printf("-2147483648"));
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

char	*ft_strrev(char *s)
{
	char	*reversed;
	int		i;
	int		j;

	i = 0;
	j = 0;
	reversed = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!reversed)
		return (NULL);
	while (s[i])
		i++;
	while (--i >= 0)
		reversed[j++] = s[i];
	reversed[j] = '\0';
	free(s);
	return (reversed);
}

char	*ft_uitoa(unsigned int n)
{
	int				i;
	char			*s;

	i = 0;
	s = malloc(sizeof(char) * 20);
	if (!s)
		return (NULL);
	if (n == 0)
		s[i++] = '0';
	else
	{
		while (n != 0)
		{
			s[i++] = (n % 10) + '0';
			n /= 10;
		}
	}
	s[i] = '\0';
	s = ft_strrev(s);
	return (s);
}

char	*ft_cpyhex(unsigned int nbr, t_settings settings, int i)
{
	int				len;
	static char		*s;

	if (i == 0)
	{
		if (nbr == 0)
			return (ft_strdup_printf("0"));
		len = ft_hexlen(nbr);
		s = malloc(sizeof(char) * (len + 1));
		if (s == NULL)
			return (NULL);
	}
	if (nbr == 0 && i)
		s[i] = '\0';
	if (nbr != 0)
	{
		ft_cpyhex(nbr / 16, settings, i + 1);
		if (nbr % 16 < 10)
			s[i] = (nbr % 16) + '0';
		else
			s[i] = (nbr % 16) - 10 + 'a';
	}
	if (i == 0)
		s = ft_strrev(s);
	return (s);
}

char	*ft_cpyptr(uintptr_t ptr, int i)
{
	int				len;
	static char		*s;

	if (i == 0)
	{
		if (ptr == 0)
			return (ft_strdup_printf("0"));
		len = ft_hexlen(ptr);
		s = malloc(sizeof(char) * (len + 1000));
		if (s == NULL)
			return (NULL);
	}
	if (ptr == 0)
		s[i] = '\0';
	if (ptr != 0)
	{
		ft_cpyptr(ptr / 16, i + 1);
		if (ptr % 16 < 10)
			s[i] = (ptr % 16) + '0';
		else
			s[i] = (ptr % 16) - 10 + 'a';
	}
	if (i == 0)
		s = ft_strrev(s);
	return (s);
}

char	*ft_hexprefix(char *str, t_settings *settings)
{
	int		i;
	int		j;
	char	*result;

	i = 0;
	j = 0;
	if (!str)
		return (NULL);
	result = malloc(sizeof(char) * (ft_strlen(str) + 3));
	if (!result)
		return (NULL);
	result[j++] = '0';
	if (settings->format == 'x' || settings->format == 'p')
		result[j++] = 'x';
	if (settings->format == 'X')
		result[j++] = 'X';
	while (str[i])
		result[j++] = str[i++];
	result[j] = '\0';
	free(str);
	return (result);
}

int	ft_count_putstr(char *str, t_settings *settings)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	if (str[0] == 0 && settings->format == 'd')
		return (0);
	if (str[0] == 0)
		count += ft_count_putchar(str[0]);
	while (str[i])
		count += ft_count_putchar(str[i++]);
	return (count);
}

char	*ft_prependminus(char *str)
{
	char	*result;
	int		i;
	int		j;

	i = 0;
	j = 0;
	result = malloc(sizeof(char) * (ft_strlen(str) + 2));
	if (!result)
		return(NULL);
	result[i++] = '-';
	while (str[j])
		result[i++] = str[j++];
	free(str);
	return (result);
}

char	*ft_zpadding_precision(char *str, int	width)
{
	int		length;
	int		i;
	int		j;
	char	*result;

	j = 0;
	length = ft_strlen(str);
	result = malloc(sizeof(char) + (width +1));
	i = width - length;
	while (i > 0)
	{
		result[j++] = '0';
		i--;
	}
	while (str[i])
		result[j++] = str[i++];
	result[j] = '\0';
	while (j-- > 0)
		if (result[j] == '-')
			result[j] = '0';
	if (str[0] == '-')
		result = ft_prependminus(result);
	free(str);
	return (result);
}

char	*ft_precision(char *str, t_settings *settings)
{
	char	*result;
	
	if (settings->format != 's')
	{
		if (str[0] == '0' && settings->precision == 0)
		{
			free(str);
			return (ft_strdup_printf(""));
		}
		if (settings->precision >= (ft_strlen(str)) && settings->format == 'd')
		str = ft_zpadding_precision(str, settings->precision);
		return (str);
	}
	if (settings->precision == 0)
		result = ft_strdup_printf("");
	else
	{
		result = malloc(sizeof(char) * (settings->precision + 1));
		if (!result)
			return (0);
		ft_strlcpy(result, str, settings->precision + 1);
	}
	free(str);
	return (result);
}

char	*ft_plus_space(char *str, t_settings *settings)
{
	int		i;
	int		j;
	char	*result;

	i = 0;
	j = 0;
	if (settings->format != 'd' || settings->format != 'i')
		return (str);
	result = malloc(sizeof(char) * (ft_strlen(str) + 2));
	if (!result)
		return (NULL);
	if (str[0] != '-')
		if (settings->plus_sign != 0)
			result[j++] = '+';
	if (settings->space != 0 && settings->plus_sign == 0)
		result[j++] = ' ';
	while (str[i])
		result[j++] = str[i++];
	result[j] = '\0';
	free(str);
	return (result);
}

char	*ft_zero_padding(char *str, t_settings *settings)
{
	int		width;
	int		length;
	int		i;
	int		j;
	char	*result;

	j = 0;
	width = settings->zero_padding;
	length = ft_strlen(str);
	if (length > width)
		return (str);
	result = malloc(sizeof(char) + (width +1));
	i = width - length;
	while (i > 0)
	{
		result[j++] = '0';
		i--;
	}
	while (str[i])
		result[j++] = str[i++];
	result[j] = '\0';
	free(str);
	return (result);
}

char	*ft_right_justify(char *str, t_settings *settings)
{
	int		width;
	int		length;
	int		i;
	int		j;
	char	*result;

	j = 0;
	width = settings->right_justify;
	length = ft_strlen(str);
	if (length > width)
		return (str);
	result = malloc(sizeof(char) + (width +1));
	i = width - length;
	while (i > 0)
	{
		result[j++] = ' ';
		i--;
	}
	while (str[i])
		result[j++] = str[i++];
	result[j] = '\0';
	free(str);
	return (result);
}

char	*ft_left_justify(char *str, t_settings *settings)
{
	int		width;
	int		length;
	int		i;
	int		j;
	char	*result;

	j = 0;
	i = 0;
	width = settings->left_justify;
	length = ft_strlen(str);
	if (length > width)
		return (str);
	result = malloc(sizeof(char) + (width +1));
	while (str[i])
		result[j++] = str[i++];
	i = width - length;
	while (i > 0)
	{
		result[j++] = ' ';
		i--;
	}
	result[j] = '\0';
	free(str);
	return (result);
}

char	*ft_flags(char *str, t_settings *settings)
{
	if (settings->precision != -1)
		str = ft_precision(str, settings);
	if ((settings->format == 'x' || settings->format == 'X') && \
	settings->hex_prefix != 0)
		str = ft_hexprefix(str, settings);
	if (settings->plus_sign != 0 || settings->space != 0)
		str = ft_plus_space(str, settings);
	if (settings->left_justify != 0)
		str = ft_left_justify(str, settings);
	if (settings->right_justify != 0)
		str = ft_right_justify(str, settings);
	if (settings->zero_padding != 0 && settings->left_justify == 0)
		str = ft_zero_padding(str, settings);
	return (str);
}

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c = c - 32;
	return (c);
}

char	*ft_strupper(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		str[i] = ft_toupper(str[i]);
		i++;
	}
	return (str);
}

int	ft_print(t_settings *settings, va_list ap)
{
	int		count;
	char	*result;

	count = 0;
	if (settings->format == 'c')
		result = ft_charcpy((char)va_arg(ap, int));
	if (settings->format == 's')
		result = ft_strdup_printf(va_arg(ap, char *));
	if (settings->format == 'd' || settings->format == 'i')
		result = ft_itoa(va_arg(ap, int));
	if (settings->format == 'u')
		result = ft_uitoa(va_arg(ap, unsigned int));
	if (settings->format == 'x' || settings->format == 'X')
		result = ft_cpyhex(va_arg(ap, unsigned int), *settings, 0);
	if (settings->format == 'X')
		result = ft_strupper(result);
	if (settings->format == 'p')
		result = ft_hexprefix(ft_cpyptr(va_arg(ap, uintptr_t), 0), settings);
	if (settings->format == '%')
		result = ft_charcpy('%');
	result = ft_flags(result, settings);
	if (settings->format == 's' && result[0] == '\0')
	{
		free(result);
		return (0);
	}
	count = ft_count_putstr(result, settings);
	free(result);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int			*i;
	int			count;
	t_settings	*settings;
	va_list		ap;

	if (ft_initialize(&i, &settings, &count) == 0)
		return (0);
	va_start(ap, str);
	while (str[*i])
	{
		if (str[*i] == '%')
		{
			(*i)++;
			ft_set_settings(str, i, settings);
			// print_settings(settings);
		}
		if (settings->format != '0')
			count += ft_print(settings, ap);
		else
			count += ft_count_putchar(str[(*i)++]);
		ft_reset_settings(settings);
	}
	ft_freeall(&i, &settings);
	return (count);
}

// #include <stdio.h>
// #include "ft_printf.h"

// int main(void)
// {
// 	char			c;
// 	char			*str;
// 	void			*ptr;
// 	int				decimal;
// 	int			 	integer;
// 	unsigned int	uinteger;
// 	unsigned int	hex_lower;
// 	unsigned int	hex_upper;
// 	int			 	ret_printf;
// 	int			 	ret_ft_printf;

// 	c = 'A';
// 	str = "cool";
// 	ptr = str;
// 	decimal = 42;
// 	integer = -42;
// 	uinteger = 42;
// 	hex_lower = 123456789;
// 	hex_upper = 123456789;
// 	printf("\nprintf\n");
// 	ret_printf = printf("%.5d, %.5d, %.5d, %.5d, %.5d, %.5d, %.5d, %.5d", 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX);
// 	printf("\n%d", ret_printf);
// 	printf("\nft_printf\n");
// 	ret_ft_printf = ft_printf("%.5d, %.5d, %.5d, %.5d, %.5d, %.5d, %.5d, %.5d", 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX);
// 	printf("\n%d", ret_ft_printf);
// 	return (0);
// }
