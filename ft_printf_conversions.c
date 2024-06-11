/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolin <ccolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 13:27:10 by ccolin            #+#    #+#             */
/*   Updated: 2024/06/11 13:50:29 by ccolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
