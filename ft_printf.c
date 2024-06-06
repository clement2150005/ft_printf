/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolin <ccolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 18:56:11 by ccolin            #+#    #+#             */
/*   Updated: 2024/06/06 13:06:52 by ccolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	*ft_calloc(size_t count, size_t size)
{
	size_t		i;
	void		*ptr;
	char		*ptr1;

	if (count >= 2147483647)
		return (NULL);
	ptr = malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	ptr1 = (char *)ptr;
	i = 0;
	while (i < count * size)
	{
		ptr1[i] = 0;
		i++;
	}
	return (ptr);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_is_fmt_nbr(t_opts *opts)
{
	if ((opts->fmt == 'd' || opts->fmt == 'i' || opts->fmt == 'u' || \
	opts->fmt == 'x' || opts->fmt == 'X'))
		return (1);
	return (0);
}

void	ft_reset_opts(t_opts *opts)
{
	opts->ljust = 0;
	opts->rjust = 0;
	opts->zpad = -1;
	opts->prec = -1;
	opts->hxpfx = 0;
	opts->plssgn = 0;
	opts->spc = 0;
	opts->fmt = '0';
	opts->chrnll = 0;
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

void	ft_setflags(const char *str, int *i, t_opts *opts)
{
	while (str[*i] == '-' || str[*i] == '0' || str[*i] == '.' || str[*i] == \
	'#' || str[*i] == ' ' || str[*i] == '+' || (str [*i] <= '9' && str [*i] \
	>= '1'))
	{
		if (str [*i] == '-')
			opts->ljust = ft_readnbr(str, i);
		else if (str [*i] <= '9' && str [*i] >= '1')
			opts->rjust = ft_readnbr(str, i);
		else if (str [*i] == '.')
			opts->prec = ft_readnbr(str, i);
		else if (str [*i] == '0')
			opts->zpad = ft_readnbr(str, i);
		else if (str [*i] == '#')
			opts->hxpfx = 1;
		else if (str [*i] == ' ')
			opts->spc = 1;
		else if (str [*i] == '+')
			opts->plssgn = 1;
		(*i)++;
	}
}

void	ft_set_opts(const char *str, int *i, t_opts *opts)
{
	int	save;

	save = *i;
	ft_setflags(str, i, opts);
	if (str[*i] == 'c' || str[*i] == 's' || str[*i] == 'p' || str[*i] == 'd'\
	|| str[*i] == 'i' || str[*i] == 'u' || str[*i] == 'x' || str[*i] == 'X'\
	|| str[*i] == '%')
		opts->fmt = str[(*i)++];
	else
		*i = save - 1;
}

int	ft_initialize(int **i, t_opts **opts, int *count)
{
	*i = ft_calloc(1, sizeof(int));
	if (!*i)
		return (0);
	*opts = ft_calloc(1, sizeof(t_opts));
	if (!*opts)
	{
		free(*i);
		return (0);
	}
	**i = 0;
	*count = 0;
	ft_reset_opts(*opts);
	return (1);
}

void	ft_freeall(int **i, t_opts **opts)
{
	free(*i);
	free(*opts);
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
		ptr = ft_calloc(7, sizeof(char));
		if (!ptr)
			return (NULL);
		ft_strlcpy((char *)ptr, "(null)", 7);
		return (ptr);
	}
	i = 0;
	size = ft_strlen(s1);
	ptr = ft_calloc(size + 1, sizeof(char));
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

char	*ft_charcpy(char c, t_opts *opts)
{
	char	*str;

	if (c == '\0')
		opts->chrnll = 1;
	str = ft_calloc(2, sizeof(char));
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
	s = ft_calloc(len + 1, sizeof(char));
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
	reversed = ft_calloc((ft_strlen(s) + 1), sizeof(char));
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
	s = ft_calloc(20, sizeof(char));
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

char	*ft_cpyhex(unsigned int nbr, t_opts opts, int i)
{
	int				len;
	static char		*s;

	if (i == 0)
	{
		if (nbr == 0)
			return (ft_strdup_printf("0"));
		len = ft_hexlen(nbr);
		s = ft_calloc((len + 1), sizeof(char));
		if (s == NULL)
			return (NULL);
	}
	if (nbr == 0 && i)
		s[i] = '\0';
	if (nbr != 0)
	{
		ft_cpyhex(nbr / 16, opts, i + 1);
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
		s = ft_calloc((len + 1), sizeof(char));
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

char	*ft_hxpfx(char *str, t_opts *opts)
{
	int		i;
	int		j;
	char	*result;

	i = 0;
	j = 0;
	if (!str)
		return (NULL);
	if (str[0] == '0' && str[1] == '\0' && opts->fmt != 'p')
		return (str);
	result = ft_calloc((ft_strlen(str) + 3), sizeof(char));
	if (!result)
		return (NULL);
	result[j++] = '0';
	if (opts->fmt == 'x' || opts->fmt == 'p')
		result[j++] = 'x';
	if (opts->fmt == 'X')
		result[j++] = 'X';
	while (str[i])
		result[j++] = str[i++];
	result[j] = '\0';
	free(str);
	return (result);
}

int	ft_count_putstr(char *str, t_opts *opts)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	if (str[0] == 0 && opts->fmt == 'd')
		return (0);
	if (str[0] == 0 && opts->prec == -1)
		count += ft_count_putchar(str[0]);
	while (str[i])
		count += ft_count_putchar(str[i++]);
	if (opts->chrnll == 1 && opts->rjust != 0 && opts->fmt != '%')
	count += ft_count_putchar('\0');
	return (count);
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = (unsigned char *)b;
	i = 0;
	while (i < len)
		ptr[i++] = c;
	return (b);
}

char	*ft_prependminus(char *str)
{
	char	*result;
	int		i;
	int		j;

	i = 0;
	j = 0;
	result = ft_calloc((ft_strlen(str) + 2), sizeof(char));
	if (!result)
		return (NULL);
	result[i++] = '-';
	while (str[j])
		result[i++] = str[j++];
	free(str);
	return (result);
}

char	*prec_prepend0(char *str, int width)
{
	int		length;
	int		i;
	int		j;
	char	*result;

	j = 0;
	length = ft_strlen(str);
	result = ft_calloc((width +1), sizeof(char));
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

char	*ft_prec(char *str, t_opts *opts)
{
	char	*result;

	if (opts->fmt != 's')
	{
		if (str[0] == '0' && opts->prec == 0)
		{
			free(str);
			return (ft_strdup_printf(""));
		}
		if (opts->prec >= (ft_strlen(str)) && ft_is_fmt_nbr(opts))
			str = prec_prepend0(str, opts->prec);
		return (str);
	}
	if (opts->prec == 0)
		result = ft_strdup_printf("");
	else
	{
		result = ft_calloc((opts->prec + 1), sizeof(char));
		if (!result)
			return (0);
		ft_strlcpy(result, str, opts->prec + 1);
	}
	free(str);
	return (result);
}

char	*ft_pls_spc(char *str, t_opts *opts)
{
	int		i;
	int		j;
	char	*result;

	i = 0;
	j = 0;
	if (opts->fmt != 'd' && opts->fmt != 'i')
		return (str);
	result = ft_calloc((ft_strlen(str) + 2), sizeof(char));
	if (!result)
		return (NULL);
	if (str[0] != '-')
		if (opts->plssgn != 0)
			result[j++] = '+';
	if (opts->spc != 0 && opts->plssgn == 0 && str[0] != '-')
		result[j++] = ' ';
	while (str[i])
		result[j++] = str[i++];
	result[j] = '\0';
	free(str);
	return (result);
}

char	*ft_moveminus(char *result)
{
	int	i;

	i = 0;
	while (result[i++])
	{
		if (result[i] == '-')
		{
			result[i] = '0';
			result[0] = '-';
		}
		if (result[i] == ' ')
		{
			result[i] = '0';
			result[0] = ' ';
		}
	}
	return (result);
}

char	*ft_zpad(char *str, t_opts *opts)
{
	int		width;
	int		length;
	int		i;
	int		j;
	char	*result;

	j = 0;
	width = opts->zpad;
	length = ft_strlen(str);
	if (length > width)
		return (str);
	result = ft_calloc((width +1), sizeof(char));
	if (!result)
		return (NULL);
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
	if (opts->fmt == 'd' || opts->fmt == 'i')
		result = ft_moveminus(result);
	return (result);
}

char	*ft_rjust(char *str, t_opts *opts)
{
	int		width;
	int		length;
	int		i;
	int		j;
	char	*result;

	j = 0;
	if (opts->prec != -1 && opts->zpad != -1)
		width = opts->zpad;
	else
		width = opts->rjust;
	length = ft_strlen(str);
	if (length > width)
		return (str);
	result = ft_calloc((width +1), sizeof(char));
	if (!result)
		return (NULL);
	i = width - length;
	if (opts->chrnll == 1 && opts->rjust != 0 && opts->fmt != '%')
		i--;
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

char	*ft_ljust(char *str, t_opts *opts)
{
	int		width;
	int		length;
	int		i;
	int		j;
	char	*result;

	j = 0;
	i = 0;
	width = opts->ljust;
	length = ft_strlen(str);
	if (length > width)
		return (str);
	result = ft_calloc((width +1), sizeof(char));
	if (!result)
		return (NULL);
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

char	*ft_flags(char *str, t_opts *opts)
{
	if (opts->prec != -1)
		str = ft_prec(str, opts);
	if ((opts->fmt == 'x' || opts->fmt == 'X') && opts->hxpfx != 0)
		str = ft_hxpfx(str, opts);
	if (opts->plssgn != 0 || opts->spc != 0)
		str = ft_pls_spc(str, opts);
	if (opts->ljust != 0)
		str = ft_ljust(str, opts);
	if (opts->rjust != 0)
		str = ft_rjust(str, opts);
	if (opts->zpad != -1 && opts->ljust == 0 && opts->prec == -1)
		str = ft_zpad(str, opts);
	if (opts->zpad != -1 && opts->ljust == 0)
		str = ft_rjust(str, opts);
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

char	*ft_setstr(t_opts *opts, va_list ap)
{
	char	*result;

	if (opts->fmt == 'c')
		result = ft_charcpy((char)va_arg(ap, int), opts);
	if (opts->fmt == 's')
		result = ft_strdup_printf(va_arg(ap, char *));
	if (opts->fmt == 'd' || opts->fmt == 'i')
		result = ft_itoa(va_arg(ap, int));
	if (opts->fmt == 'u')
		result = ft_uitoa(va_arg(ap, unsigned int));
	if (opts->fmt == 'x' || opts->fmt == 'X')
		result = ft_cpyhex(va_arg(ap, unsigned int), *opts, 0);
	if (opts->fmt == 'X')
		result = ft_strupper(result);
	if (opts->fmt == 'p')
		result = ft_hxpfx(ft_cpyptr(va_arg(ap, uintptr_t), 0), opts);
	if (opts->fmt == '%')
		result = ft_charcpy('%', opts);
	return (result);
}

int	ft_charljust(char *result, t_opts *opts)
{
	int	count;
	int	i;

	count = 0;
	if (opts->fmt == 'c' && opts->ljust != 0)
	{
		i = opts->ljust;
		count += ft_count_putchar(result[0]);
		while (i > 1)
		{
			count += ft_count_putchar(' ');
			i--;
		}
	}
	return (count);
}

int	ft_print(t_opts *opts, va_list ap)
{
	int		count;
	char	*result;

	count = 0;
	result = ft_setstr(opts, ap);
	count = ft_charljust(result, opts);
	if (count == 0)
	{
		result = ft_flags(result, opts);
		if (opts->fmt == 's' && result[0] == '\0')
		{
			free(result);
			return (0);
		}
		else if (opts->prec == 0 && opts->zpad != -1 && opts->fmt == 'd' \
		&& result[0] == '0')
			result[0] = ' ';
		count = ft_count_putstr(result, opts);
	}
	free(result);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int			*i;
	int			count;
	t_opts		*opts;
	va_list		ap;

	if (ft_initialize(&i, &opts, &count) == 0)
		return (0);
	va_start(ap, str);
	while (str[*i])
	{
		if (str[*i] == '%')
		{
			(*i)++;
			ft_set_opts(str, i, opts);
		}
		if (opts->fmt != '0')
			count += ft_print(opts, ap);
		else
			count += ft_count_putchar(str[(*i)++]);
		ft_reset_opts(opts);
	}
	ft_freeall(&i, &opts);
	return (count);
}

 #include <stdio.h>
 #include "ft_printf.h"

 int main(void)
 {
 	char			c;
 	char			*str;
 	void			*ptr;
 	int				decimal;
 	int			 	integer;
 	unsigned int	uinteger;
 	unsigned int	hex_lower;
 	unsigned int	hex_upper;
 	int			 	ret_printf;
 	int			 	ret_ft_printf;

 	c = 'A';
 	str = "cool";
 	ptr = str;
 	decimal = 42;
 	integer = -42;
 	uinteger = 42;
 	hex_lower = 123456789;
 	hex_upper = 123456789;
 	printf("\nprintf\n");
 	ret_printf = printf(TEST);
 	printf("\n%d", ret_printf);
 	printf("\nft_printf\n");
 	ret_ft_printf = ft_printf(TEST);
 	printf("\n%d", ret_ft_printf);
 	return (0);
 }
