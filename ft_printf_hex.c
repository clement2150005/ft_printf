/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolin <ccolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 13:37:10 by ccolin            #+#    #+#             */
/*   Updated: 2024/06/11 13:37:49 by ccolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_cpyhex(unsigned int nbr, t_opts *opts, int i)
{
	int				len;
	static char		*s;

	if (i == 0)
	{
		if (ft_cpyhex_0(nbr, opts))
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
