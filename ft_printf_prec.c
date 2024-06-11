/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolin <ccolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 13:34:07 by ccolin            #+#    #+#             */
/*   Updated: 2024/06/11 13:34:22 by ccolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
