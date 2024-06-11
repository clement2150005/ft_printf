/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opts.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolin <ccolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 13:51:47 by ccolin            #+#    #+#             */
/*   Updated: 2024/06/11 13:52:19 by ccolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_reset_opts(t_opts *opts)
{
	opts->ljust = -1;
	opts->rjust = 0;
	opts->zpad = -1;
	opts->prec = -1;
	opts->hxpfx = 0;
	opts->plssgn = 0;
	opts->spc = 0;
	opts->fmt = '0';
	opts->chrnll = 0;
	opts->width = 0;
}

void	ft_setwidth(t_opts *opts)
{
	if (opts->prec != -1)
		opts->width = opts->prec;
	if (opts->zpad != -1)
		opts->width = opts->zpad;
	if (opts->ljust != -1)
		opts->width = opts->ljust;
	if (opts->rjust != 0)
		opts->width = opts->rjust;
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
