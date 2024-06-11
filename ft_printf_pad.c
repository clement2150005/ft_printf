/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolin <ccolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 13:29:26 by ccolin            #+#    #+#             */
/*   Updated: 2024/06/11 13:31:13 by ccolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_moveminus(char *result)
{
	int		i;
	char	c;

	i = 0;
	while (result[i++])
	{
		if (result[i] == '-' || result[i] == '+' || result[i] == ' ' || \
		result[i] == 'x' || result[i] == 'X')
		{
			c = result[i];
			result[i] = '0';
			if (c != 'x' && c != 'X')
				result[0] = c;
			else
				result[1] = c;
		}
	}
	return (result);
}

char	*ft_zpad(char *str, int width, t_opts *opts)
{
	int		length;
	int		i;
	int		j;
	char	*result;

	j = 0;
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
	if (opts->fmt == 'd' || opts->fmt == 'i' || opts->hxpfx == 1)
		result = ft_moveminus(result);
	return (result);
}
