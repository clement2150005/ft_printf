/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolin <ccolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 18:56:11 by ccolin            #+#    #+#             */
/*   Updated: 2024/06/11 13:58:57 by ccolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

char	*ft_flags(char *str, t_opts *opts)
{
	if (opts->prec != -1)
		str = ft_prec(str, opts);
	if ((opts->fmt == 'x' || opts->fmt == 'X') && opts->hxpfx != 0)
		str = ft_hxpfx(str, opts);
	if (opts->plssgn != 0 || opts->spc != 0)
		str = ft_pls_spc(str, opts);
	if (opts->ljust != -1)
		str = ft_ljust(str, opts);
	if (opts->rjust != 0 && opts->zpad == -1 && opts->ljust == -1)
		str = ft_rjust(str, opts);
	if (opts->rjust != 0 && opts->ljust == -1 && opts->zpad != -1 && \
	(opts->plssgn != 0 || opts->spc != 0))
		str = ft_rjust(str, opts);
	if (opts->zpad != -1 && opts->ljust == -1 && opts->prec == -1)
		str = ft_zpad(str, opts-> width, opts);
	if (opts->zpad != -1 && opts->ljust == -1)
		str = ft_rjust(str, opts);
	if (!(opts->zpad != -1 && opts->rjust != 0 && \
	(opts->plssgn != 0 || opts->spc != 0) && opts->prec != -1))
		if (opts->zpad != -1 && opts->rjust != 0 && \
		(opts->plssgn != 0 || opts->spc != 0))
			str = ft_zpad(str, opts->rjust, opts);
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
		result = ft_cpyhex(va_arg(ap, unsigned int), opts, 0);
	if (opts->fmt == 'X')
		result = ft_strupper(result);
	if (opts->fmt == 'p')
		result = ft_hxpfx(ft_cpyptr(va_arg(ap, uintptr_t), 0), opts);
	if (opts->fmt == '%')
		result = ft_charcpy('%', opts);
	return (result);
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
		ft_setwidth(opts);
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
	va_end(ap);
	return (count);
}
