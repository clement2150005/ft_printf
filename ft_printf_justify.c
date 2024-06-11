/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolin <ccolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 13:24:24 by ccolin            #+#    #+#             */
/*   Updated: 2024/06/11 13:30:07 by ccolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_rjust_init(char *str, int *width, int *length, t_opts *opts)
{
	if (opts->prec != -1 && opts->zpad != -1 && \
	opts->plssgn == 0 && opts->rjust == 0)
		*width = opts->zpad;
	else
		*width = opts->rjust;
	*length = ft_strlen(str);
	return (0);
}

char	*ft_rjust(char *str, t_opts *opts)
{
	int		width;
	int		length;
	int		i;
	int		j;
	char	*result;

	j = ft_rjust_init(str, &width, &length, opts);
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
	int		length;
	int		i;
	int		j;
	char	*result;

	j = 0;
	i = 0;
	length = ft_strlen(str);
	if (length > opts->width)
		return (str);
	result = ft_calloc((opts->width +1), sizeof(char));
	if (!result)
		return (NULL);
	while (str[i])
		result[j++] = str[i++];
	i = opts->width - length;
	while (i > 0)
	{
		result[j++] = ' ';
		i--;
	}
	result[j] = '\0';
	free(str);
	return (result);
}

int	ft_charljust(char *result, t_opts *opts)
{
	int	count;
	int	i;

	count = 0;
	if (opts->fmt == 'c' && opts->ljust != -1)
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
