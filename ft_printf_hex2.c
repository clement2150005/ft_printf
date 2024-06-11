/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolin <ccolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 13:36:11 by ccolin            #+#    #+#             */
/*   Updated: 2024/06/11 13:36:59 by ccolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexlen(unsigned long n)
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

int	ft_cpyhex_0(int nbr, t_opts *opts)
{
	if (nbr == 0)
	{
		opts->hxpfx = 0;
		return (1);
	}
	else
		return (0);
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
	if ((str[0] == '0' && str[1] == '\0' && opts->fmt != 'p') || str[0] == '\0')
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
